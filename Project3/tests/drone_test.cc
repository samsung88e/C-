#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include <EntityProject/web_scene_viewer.h>
#include <EntityProject/osm_graph_parser.h>
#include <EntityProject/graph.h>
#include <EntityProject/facade/delivery_system.h>
#include <EntityProject/entity_console_logger.h>
#include "Factory/DroneFactory.h"
#include "Factory/PackageFactory.h"
#include "Factory/CustomerFactory.h"

#include <iostream>
using std::string;

namespace csci3081 {

using entity_project::IEntity;

class DroneTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    system = dynamic_cast<IDeliverySystem*>(GetEntitySystem("default"));
    system->AddFactory(new DroneFactory());
    system->AddFactory(new PackageFactory());
	//~ entitySubject = new AEntitySubject();
  }
  virtual void TearDown() {}

  IDeliverySystem* system;
   //~ AEntitySubject* entitySubject;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(DroneTest, DroneConstructor) {
  picojson::object obj = JsonHelper::CreateJsonObject();
  JsonHelper::AddStringToJsonObject(obj, "type", "drone");
  std::vector<float> position;
  position.push_back(10.163);
  position.push_back(-204.00);
  position.push_back(37.85);
  JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position);
  std::vector<float> direction;
  direction.push_back(1);
  direction.push_back(0);
  direction.push_back(0);
  JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction);
  JsonHelper::AddFloatToJsonObject(obj, "speed", 30);
  IEntity* entity = system->CreateEntity(obj);
  // Checks that the returned entity is not NULL
  ASSERT_NE(entity, nullptr) << "The entity created";
  system->AddEntity(entity);
  ASSERT_EQ(1, system->GetEntities().size());
  Drone* DronePtr = dynamic_cast<Drone*>(entity);
  
  ASSERT_FLOAT_EQ(DronePtr->GetPosition()[0], position[0]);
  ASSERT_FLOAT_EQ(DronePtr->GetPosition()[1], position[1]);
  ASSERT_FLOAT_EQ(DronePtr->GetPosition()[2], position[2]);
  ASSERT_EQ(DronePtr->GetName(), "pkgDrone");
  ASSERT_EQ(DronePtr->HasDelivery(), false);
  ASSERT_EQ(DronePtr->HasPackage(), false);
  
  // Checks that when GetDetails() is called, the entity returns 
  //  the picojson object that was used to initialize it
  ASSERT_EQ(picojson::value(system->GetEntities()[0]->GetDetails()).serialize(), "{\"color\":\"0x58D68D\",\"direction\":[1,0,0],\"position\":[10.163000106811523,-204,37.849998474121094],\"speed\":30,\"type\":\"drone\"}");

}

TEST_F(DroneTest, AddRemovePoint){
	
    picojson::object obj = JsonHelper::CreateJsonObject();
	JsonHelper::AddStringToJsonObject(obj, "type", "drone");
	std::vector<float> position;
	position.push_back(0);
	position.push_back(1);
	position.push_back(0);
	JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position);
	std::vector<float> direction;
	direction.push_back(1);
	direction.push_back(0);
	direction.push_back(0);
	JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction);
	JsonHelper::AddFloatToJsonObject(obj, "speed", 30);
	IEntity* entity = system->CreateEntity(obj);
	// Checks that the returned entity is not NULL
	ASSERT_NE(entity, nullptr) << "The entity created";
	system->AddEntity(entity);
	Drone* DronePtr = dynamic_cast<Drone*>(entity);
	
	std::vector<float> vec1{1, 2, 3};
	std::vector<float> vec2{2, 3, 4};
	DronePtr->AddPoint(vec1);
	DronePtr->AddPoint(vec2);
	//Drone is able to remove points
	EXPECT_NO_THROW({
		DronePtr->RemovePoint();
		DronePtr->RemovePoint();
	});
}

TEST_F(DroneTest, SetGetHasDelivery){
	
    picojson::object obj = JsonHelper::CreateJsonObject();
	JsonHelper::AddStringToJsonObject(obj, "type", "drone");
	std::vector<float> position;
	position.push_back(0);
	position.push_back(1);
	position.push_back(0);
	JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position);
	std::vector<float> direction;
	direction.push_back(1);
	direction.push_back(0);
	direction.push_back(0);
	JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction);
	JsonHelper::AddFloatToJsonObject(obj, "speed", 30);
	IEntity* entity = system->CreateEntity(obj);
	// Checks that the returned entity is not NULL
	ASSERT_NE(entity, nullptr) << "The entity created";
	system->AddEntity(entity);
	Drone* DronePtr = dynamic_cast<Drone*>(entity);
	
	DronePtr->SetHasDelivery(true);
	ASSERT_EQ(DronePtr->HasDelivery(), true);
	DronePtr->SetHasDelivery(false);
	ASSERT_EQ(DronePtr->HasDelivery(), false);
}

TEST_F(DroneTest, SetGetHasPackage){
	
    picojson::object obj = JsonHelper::CreateJsonObject();
	JsonHelper::AddStringToJsonObject(obj, "type", "drone");
	std::vector<float> position;
	position.push_back(0);
	position.push_back(1);
	position.push_back(0);
	JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position);
	std::vector<float> direction;
	direction.push_back(1);
	direction.push_back(0);
	direction.push_back(0);
	JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction);
	JsonHelper::AddFloatToJsonObject(obj, "speed", 30);
	IEntity* entity = system->CreateEntity(obj);
	// Checks that the returned entity is not NULL
	ASSERT_NE(entity, nullptr) << "The entity created";
	system->AddEntity(entity);
	Drone* DronePtr = dynamic_cast<Drone*>(entity);
	
	DronePtr->SetHasPackage(true);
	ASSERT_EQ(DronePtr->HasPackage(), true);
	DronePtr->SetHasPackage(false);
	ASSERT_EQ(DronePtr->HasPackage(), false);
}

TEST_F(DroneTest, SetGetPackage){
	//create the drone
    picojson::object obj = JsonHelper::CreateJsonObject();
	JsonHelper::AddStringToJsonObject(obj, "type", "drone");
	std::vector<float> position;
	position.push_back(0);
	position.push_back(1);
	position.push_back(0);
	JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position);
	std::vector<float> direction;
	direction.push_back(1);
	direction.push_back(0);
	direction.push_back(0);
	JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction);
	JsonHelper::AddFloatToJsonObject(obj, "speed", 30);
	IEntity* entity = system->CreateEntity(obj);
	// Checks that the returned entity is not NULL
	ASSERT_NE(entity, nullptr) << "The entity created";
	system->AddEntity(entity);
	Drone* DronePtr = dynamic_cast<Drone*>(entity);
	
	//create the package
    picojson::object obj2 = JsonHelper::CreateJsonObject();
	JsonHelper::AddStringToJsonObject(obj2, "type", "package");
	std::vector<float> position2;
	position2.push_back(0);
	position2.push_back(1);
	position2.push_back(0);
	JsonHelper::AddStdFloatVectorToJsonObject(obj2, "position", position2);
	std::vector<float> direction2;
	direction2.push_back(1);
	direction2.push_back(0);
	direction2.push_back(0);
	JsonHelper::AddStdFloatVectorToJsonObject(obj2, "direction", direction2);
	IEntity* entity2 = system->CreateEntity(obj2);
	// Checks that the returned entity is not NULL
	ASSERT_NE(entity2, nullptr) << "The entity created";
	system->AddEntity(entity2);
	Package* PackagePtr = dynamic_cast<Package*>(entity2);
	
	DronePtr->SetPackage(PackagePtr);
	ASSERT_TRUE(DronePtr->GetPackage() == PackagePtr);
}

TEST_F(DroneTest, IsBatteryEmptyTest) {
  picojson::object obj = JsonHelper::CreateJsonObject();
  JsonHelper::AddStringToJsonObject(obj, "type", "drone");
  std::vector<float> position;
  position.push_back(10.163);
  position.push_back(-204.00);
  position.push_back(37.85);
  JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position);
  std::vector<float> direction;
  direction.push_back(1);
  direction.push_back(0);
  direction.push_back(0);
  JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction);
  JsonHelper::AddFloatToJsonObject(obj, "speed", 30);
  JsonHelper::AddFloatToJsonObject(obj, "batteryCapacity", 10000);
  IEntity* entity = system->CreateEntity(obj);
  // Checks that the returned entity is not NULL
  ASSERT_NE(entity, nullptr) << "The entity created";
  system->AddEntity(entity);
  ASSERT_EQ(1, system->GetEntities().size());
  Drone* DronePtr = dynamic_cast<Drone*>(entity);
  
  ASSERT_FLOAT_EQ(DronePtr->GetPosition()[0], position[0]);
  ASSERT_FLOAT_EQ(DronePtr->GetPosition()[1], position[1]);
  ASSERT_FLOAT_EQ(DronePtr->GetPosition()[2], position[2]);
  ASSERT_EQ(DronePtr->IsBatteryEmpty(), false);


  // Checks that when GetDetails() is called, the entity returns 
  //  the picojson object that was used to initialize it
  ASSERT_EQ(picojson::value(system->GetEntities()[0]->GetDetails()).serialize(), "{\"batteryCapacity\":10000,\"color\":\"0x58D68D\",\"direction\":[1,0,0],\"position\":[10.163000106811523,-204,37.849998474121094],\"speed\":30,\"type\":\"drone\"}");

}

TEST_F(DroneTest, MoveToPointsTest){
	picojson::object obj = JsonHelper::CreateJsonObject();
  	JsonHelper::AddStringToJsonObject(obj, "type", "drone");
  	std::vector<float> position;
  	position.push_back(0);
  	position.push_back(0);
  	position.push_back(0);
  	JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position);
  	std::vector<float> direction;
  	direction.push_back(1);
  	direction.push_back(0);
  	direction.push_back(0);
  	JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction);
  	JsonHelper::AddFloatToJsonObject(obj, "speed", 10);
  	IEntity* entity = system->CreateEntity(obj);
	// Checks that the returned entity is not NULL
	ASSERT_NE(entity, nullptr) << "The entity created";
	system->AddEntity(entity);
  	ASSERT_EQ(1, system->GetEntities().size());
	Drone* drone = dynamic_cast<Drone*>(entity);
	std::vector<float> vec1{19, 0, 0};
	std::vector<float> vec2{19, 25, 0};
	drone->AddPoint(vec1);
	drone->AddPoint(vec2);
	drone->MoveToPoints(1);
	std::vector<float> expected1{10, 0, 0};
	EXPECT_EQ(drone->GetPosition(), expected1);
	drone->MoveToPoints(1);
	std::vector<float> expected2{19, 0, 0};
	EXPECT_EQ(drone->GetPosition(), expected2);
	drone->MoveToPoints(1);
	std::vector<float> expected3{19, 10, 0};
	EXPECT_EQ(drone->GetPosition(), expected3);
}

TEST_F(DroneTest, PickupPackageTest){
	picojson::object obj = JsonHelper::CreateJsonObject();
  	JsonHelper::AddStringToJsonObject(obj, "type", "drone");
  	std::vector<float> position;
  	position.push_back(0);
  	position.push_back(0);
  	position.push_back(0);
  	JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position);
  	std::vector<float> direction;
  	direction.push_back(1);
  	direction.push_back(0);
  	direction.push_back(0);
  	JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction);
  	JsonHelper::AddFloatToJsonObject(obj, "speed", 100);
  	IEntity* entity = system->CreateEntity(obj);
	// Checks that the returned entity is not NULL
	ASSERT_NE(entity, nullptr) << "The entity created";
	system->AddEntity(entity);
  	ASSERT_EQ(1, system->GetEntities().size());
	Drone* drone = dynamic_cast<Drone*>(entity);


	picojson::object obj2 = JsonHelper::CreateJsonObject();
	JsonHelper::AddStringToJsonObject(obj2, "type", "package");
	std::vector<float> position2;
	position2.push_back(100);
	position2.push_back(100);
	position2.push_back(100);
	JsonHelper::AddStdFloatVectorToJsonObject(obj2, "position", position2);
	std::vector<float> direction2;
	direction2.push_back(1);
	direction2.push_back(0);
	direction2.push_back(0);
	JsonHelper::AddStdFloatVectorToJsonObject(obj2, "direction", direction2);
	IEntity* entity2 = system->CreateEntity(obj2);
	// Checks that the returned entity is not NULL
	ASSERT_NE(entity2, nullptr) << "The entity created";
	system->AddEntity(entity2);
	Package* package = dynamic_cast<Package*>(entity2);
	drone->SetPackage(package);
	drone->MoveToPoints(2);

	ASSERT_TRUE(drone->GetPackage() == package);
}

}  // namespace csci3081
