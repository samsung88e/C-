#include "delivery_simulation.h"
#include "entity_base.h"
#include "json_helper.h"

#include "drone.h"
#include "customer.h"
#include "package.h"
#include "robot.h"
#include "EntityDecorator.h"
#include "BatteryLifeDecorator.h"
#include "EntityDeliverer.h"

namespace csci3081 {

DeliverySimulation::DeliverySimulation() {
	compositeFactory = new CompositeFactory();
	entitySubject = new AEntitySubject();
	pathStrategy = new SmartRoute();
}

DeliverySimulation::~DeliverySimulation() {
	delete compositeFactory;
	delete entitySubject;
	delete pathStrategy;
}

IEntity* DeliverySimulation::CreateEntity(const picojson::object& val) {
	return compositeFactory->CreateEntity(val);
}

void DeliverySimulation::AddFactory(IEntityFactory* factory) {
	compositeFactory->AddFactory(factory);
}

void DeliverySimulation::AddEntity(IEntity* entity) {

	if(JsonHelper::GetString(entity->GetDetails(), "type") == "drone" || JsonHelper::GetString(entity->GetDetails(), "type") == "robot") {
		EntityDeliverer* entityDeliverer = dynamic_cast<EntityDeliverer*>(entity);
		entityDeliverer_.push_back(entityDeliverer);
		AbstractDeliverer* abstractDeliverer = dynamic_cast<AbstractDeliverer*>(entity);
		abstractDeliverer = new BatteryLifeDecorator(abstractDeliverer);
		abstractDeliverer_.push_back(abstractDeliverer);
	}
	entities_.push_back(entity);
  	
}

void DeliverySimulation::SetGraph(const IGraph* graph) {
	this->graph = graph;
}

void DeliverySimulation::ScheduleDelivery(IEntity* package, IEntity* dest) {
	bool deliveryAssigned = false;

	for (auto entityDeliverer : entityDeliverer_) {
		entityDeliverer->SetEntitySubject(entitySubject);
		if (!entityDeliverer->HasDelivery()) {
			std::string pathType;
			if(JsonHelper::ContainsKey(entityDeliverer->GetDetails(), "path")) {
				// Choose the type of path for the strategy
				pathType = JsonHelper::GetString(entityDeliverer->GetDetails(), "path");
				if(pathType == "beeline") {
					pathStrategy = new BeelineRoute();
				}
				else if(pathType == "smart"){
					pathStrategy = new SmartRoute();
				}
				else if(pathType == "parabolic"){
					pathStrategy = new ParabolicRoute();
				}
			}
			else if (!entityDeliverer->CanFly()) {
				pathStrategy = new SmartRoute();
			}
			else {
				pathStrategy = new BeelineRoute();
			}
			pathStrategy->SetGraph(graph);
			std::vector<float> dronePosition = entityDeliverer->GetPosition();
			std::vector<float> packagePosition = package->GetPosition();
			std::vector<float> customerPosition = dest->GetPosition();
			std::vector<std::vector<float>> drnToPkg;
			std::vector<std::vector<float>> pkgToDest;
			drnToPkg = pathStrategy->GetPath(dronePosition, packagePosition);
			pkgToDest = pathStrategy->GetPath(packagePosition, customerPosition);
			std::vector<std::vector<float>> path;
			path.insert(path.end(), drnToPkg.begin(), drnToPkg.end());
			// Add the path points to the Drone
			for(std::vector<float> point : path){
				entityDeliverer->AddPoint(point);
			}
			entityDeliverer->updateObserverPath();
		
			Package* pkg = dynamic_cast<Package*>(package);
			Customer* cstmr = dynamic_cast<Customer*>(dest);
			pkg->SetEntitySubject(entitySubject);
			pkg->Scheduled();
			pkg->SetCustomer(cstmr);
			entityDeliverer->SetPackage(pkg);
			entityDeliverer->SetHasDelivery(true);
			deliveryAssigned = true;
			break;
		}

	}

	if(!deliveryAssigned && package != nullptr && dest != nullptr) {
			Deliveries delivery;
			delivery.dest = dest;
			delivery.package = package;
			deliveryQueue.push(delivery);
	}

}

void DeliverySimulation::AddObserver(IEntityObserver* observer) {
	entitySubject->Attach(observer);
}

void DeliverySimulation::RemoveObserver(IEntityObserver* observer) {
	entitySubject->Detach(observer);
}

const std::vector<IEntity*>& DeliverySimulation::GetEntities() const { return entities_; }

void DeliverySimulation::Update(float dt) {
	if (entities_.empty()) {return;}
	if (entityDeliverer_.empty()) {return;}
	for (auto entityDeliverer : entityDeliverer_) {		
		if(entityDeliverer->HasDelivery()) {
			Package* pkg = entityDeliverer->GetPackage();
			Customer* cstmr = pkg->GetCustomer();
			for(auto abstractDeliverer : abstractDeliverer_) {
				if(abstractDeliverer->GetIdentification() == entityDeliverer->GetId()) {
					abstractDeliverer->MoveToPoints(dt);
				}
			}
			
			Vector3D drnPosition = entityDeliverer->GetPosition();
			Vector3D pkgPosition = pkg->GetPosition();
			Vector3D cstmrPosition = cstmr->GetPosition();
			if(drnPosition.Equals(pkgPosition) && !entityDeliverer->HasPackage()) {
				std::string pathType;
				if(JsonHelper::ContainsKey(entityDeliverer->GetDetails(), "path")) {
					// Choose the type of path for the strategy
					pathType = JsonHelper::GetString(entityDeliverer->GetDetails(), "path");
					if(pathType == "beeline") {
						pathStrategy = new BeelineRoute();
					}
					else if(pathType == "smart"){
						pathStrategy = new SmartRoute();
					}
					else if(pathType == "parabolic"){
						pathStrategy = new ParabolicRoute();
					}
				}
				else if (!entityDeliverer->CanFly()) {
					pathStrategy = new SmartRoute();
				}
				else {
					pathStrategy = new BeelineRoute();
				}

				pathStrategy->SetGraph(graph);
				std::vector<std::vector<float>> path = pathStrategy->GetPath(entityDeliverer->GetPosition(), cstmr->GetPosition());
				for (std::vector<float> point : path) {
					entityDeliverer->AddPoint(point);
				}

				entityDeliverer->updateObserverPath();
				entityDeliverer->PickupPackage();
			}

			if(entityDeliverer->IsBatteryEmpty() && !entityDeliverer->IsIdle()) {
				entityDeliverer->Idle();
				ScheduleDelivery(pkg, cstmr);
			}
			if(pkgPosition.Equals(cstmrPosition) && entityDeliverer->HasPackage()) {
				entityDeliverer->DeliverPackage();
				std::vector<float> farAway(3, 100000.f);
				pkg->SetPosition(farAway);
				if(!deliveryQueue.empty()) {
					IEntity* dest = deliveryQueue.front().dest;
					IEntity* package = deliveryQueue.front().package;
					deliveryQueue.pop();
					ScheduleDelivery(package, dest);
				}
				else {
					entityDeliverer->Idle();
				}
			}
		
		}


		
	}
}


// DO NOT MODIFY THE FOLLOWING UNLESS YOU REALLY KNOW WHAT YOU ARE DOING
void DeliverySimulation::RunScript(const picojson::array& script, IEntitySystem* system) const {
  JsonHelper::PrintArray(script);
  IDeliverySystem* deliverySystem = dynamic_cast<IDeliverySystem*>(system);
	if (deliverySystem) {

	    // To store the unadded entities_
	    std::vector<IEntity*> created_entities;

		for (unsigned int i=0; i < script.size(); i++) {
			const picojson::object& object = script[i].get<picojson::object>();
			const std::string cmd = object.find("command")->second.get<std::string>();
			const picojson::object& params = object.find("params")->second.get<picojson::object>();
			// May want to replace the next few if-statements with an enum
			if (cmd == "createEntity") {
				IEntity* entity = NULL;
				entity = deliverySystem->CreateEntity(params);
				if (entity) {
					created_entities.push_back(entity);
				} else {
					std::cout << "Null entity" << std::endl;
				}
			}
			else if (cmd == "addEntity") {
				int ent_index = static_cast<int>(params.find("index")->second.get<double>());
				if (ent_index >= 0 && ent_index < created_entities.size()) {
					deliverySystem->AddEntity(created_entities[ent_index]);
				}
			}
			else if (cmd == "scheduleDelivery" ) {
				int pkg_index = static_cast<int>(params.find("pkg_index")->second.get<double>());
				int dest_index = static_cast<int>(params.find("dest_index")->second.get<double>());
				if (pkg_index >= 0 && pkg_index < system->GetEntities().size()) {
					IEntity* pkg = deliverySystem->GetEntities()[pkg_index];
					if (dest_index >= 0 && pkg_index < system->GetEntities().size()) {
						IEntity* cst = system->GetEntities()[dest_index];
						if (pkg && cst) {
							deliverySystem->ScheduleDelivery(pkg, cst);
						}
					}
				}
				else {
					std::cout << "Failed to schedule delivery: invalid indexes" << std::endl;
				}
			}
		}
	}
}

}
