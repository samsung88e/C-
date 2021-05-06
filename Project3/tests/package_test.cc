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

class PackageTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    system = dynamic_cast<IDeliverySystem*>(GetEntitySystem("default"));
    system->AddFactory(new PackageFactory());
    system->AddFactory(new CustomerFactory());
	//~ entitySubject = new AEntitySubject();
  }
  virtual void TearDown() {}

  IDeliverySystem* system;
   //~ AEntitySubject* entitySubject;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(PackageTest, PackageConstructor) {
  picojson::object obj = JsonHelper::CreateJsonObject();
  JsonHelper::AddStringToJsonObject(obj, "type", "package");
  std::vector<float> position;
  position.push_back(152.664);
  position.push_back(968.143);
  position.push_back(-120.401);
  JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position);
  std::vector<float> direction;
  direction.push_back(1);
  direction.push_back(0);
  direction.push_back(0);
  JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction);
  IEntity* entity = system->CreateEntity(obj);
  // Checks that the returned entity is not NULL
  ASSERT_NE(entity, nullptr) << "The entity created";
  system->AddEntity(entity);
  ASSERT_EQ(1, system->GetEntities().size());
  
  Package* PackagePtr = dynamic_cast<Package*>(entity);
  ASSERT_FLOAT_EQ(PackagePtr->GetPosition()[0], position[0]);
  ASSERT_FLOAT_EQ(PackagePtr->GetPosition()[1], position[1]);
  ASSERT_FLOAT_EQ(PackagePtr->GetPosition()[2], position[2]);
  ASSERT_EQ(PackagePtr->GetName(), "package");
  ASSERT_EQ(PackagePtr->IsDelivered(), false);
  
  // Checks that when GetDetails() is called, the entity returns 
  //  the picojson object that was used to initialize it
  ASSERT_EQ(picojson::value(system->GetEntities()[0]->GetDetails()).serialize(), picojson::value(obj).serialize());

}

TEST_F(PackageTest, SetGetCustomer){
	//create the package
    picojson::object obj = JsonHelper::CreateJsonObject();
	JsonHelper::AddStringToJsonObject(obj, "type", "package");
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
	IEntity* entity = system->CreateEntity(obj);
	// Checks that the returned entity is not NULL
	ASSERT_NE(entity, nullptr) << "The entity created";
	system->AddEntity(entity);
	Package* PackagePtr = dynamic_cast<Package*>(entity);
	
	//create the customer
    picojson::object obj2 = JsonHelper::CreateJsonObject();
	JsonHelper::AddStringToJsonObject(obj2, "type", "customer");
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
	Customer* CustomerPtr = dynamic_cast<Customer*>(entity2);
	
	PackagePtr->SetCustomer(CustomerPtr);
	ASSERT_TRUE(PackagePtr->GetCustomer() == CustomerPtr);
}

TEST_F(PackageTest, SetGetIsDelivered){
	
    picojson::object obj = JsonHelper::CreateJsonObject();
	JsonHelper::AddStringToJsonObject(obj, "type", "package");
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
	IEntity* entity = system->CreateEntity(obj);
	// Checks that the returned entity is not NULL
	ASSERT_NE(entity, nullptr) << "The entity created";
	system->AddEntity(entity);
	Package* PackagePtr = dynamic_cast<Package*>(entity);
	
	PackagePtr->SetIsDelivered(true);
	ASSERT_EQ(PackagePtr->IsDelivered(), true);
	PackagePtr->SetIsDelivered(false);
	ASSERT_EQ(PackagePtr->IsDelivered(), false);
}

TEST_F(PackageTest, SetGetPosition){
	
    picojson::object obj = JsonHelper::CreateJsonObject();
	JsonHelper::AddStringToJsonObject(obj, "type", "package");
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
	IEntity* entity = system->CreateEntity(obj);
	// Checks that the returned entity is not NULL
	ASSERT_NE(entity, nullptr) << "The entity created";
	system->AddEntity(entity);
	Package* PackagePtr = dynamic_cast<Package*>(entity);
	
	
	std::vector<float> position_test;
	position_test.push_back(2);
	position_test.push_back(1);
	position_test.push_back(-8);
	PackagePtr->SetPosition(position_test);
	ASSERT_EQ(PackagePtr->GetPosition(), position_test);
}

TEST_F(PackageTest, IsDeliveredTest){
	picojson::object obj = JsonHelper::CreateJsonObject();
	JsonHelper::AddStringToJsonObject(obj, "type", "package");
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
	IEntity* entity = system->CreateEntity(obj);
	// Checks that the returned entity is not NULL
	ASSERT_NE(entity, nullptr) << "The entity created";
	system->AddEntity(entity);
	Package* package = dynamic_cast<Package*>(entity);

	ASSERT_EQ(false, package->GetIsDelivered());
	package->SetIsDelivered(true);
	ASSERT_EQ(true, package->GetIsDelivered());
}

TEST_F(PackageTest, IsSubjectTest){
	picojson::object obj = JsonHelper::CreateJsonObject();
	JsonHelper::AddStringToJsonObject(obj, "type", "package");
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
	IEntity* entity = system->CreateEntity(obj);
	// Checks that the returned entity is not NULL
	ASSERT_NE(entity, nullptr) << "The entity created";
	system->AddEntity(entity);
	Package* package = dynamic_cast<Package*>(entity);

	ASSERT_EQ(true, package->isSubject());
}

}  // namespace csci3081

