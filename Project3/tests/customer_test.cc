#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include <EntityProject/web_scene_viewer.h>
#include <EntityProject/osm_graph_parser.h>
#include <EntityProject/graph.h>
#include <EntityProject/facade/delivery_system.h>
#include <EntityProject/entity_console_logger.h>
#include "Factory/CustomerFactory.h"
//~ #include <EntityProject/entity.h>
//~ #include "json_helper.h"
//~ #include "../include/entity_base.h"
//~ #include "../include/customer.h"


//~ #include "gtest/gtest.h"
//~ #include <EntityProject/project_settings.h>
//~ #include <EntityProject/web_scene_viewer.h>
//~ #include <EntityProject/osm_graph_parser.h>
//~ #include <EntityProject/graph.h>
//~ #include <EntityProject/facade/delivery_system.h>
//~ #include <EntityProject/entity_console_logger.h>
//~ #include "Factory/CustomerFactory.h"
//~ #include "Factory/PackageFactory.h"
//~ #include "Factory/DroneFactory.h"
//~ #include "Factory/RobotFactory.h"

#include <iostream>
using std::string;

namespace csci3081 {

using entity_project::IEntity;

class CustomerTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    system = dynamic_cast<IDeliverySystem*>(GetEntitySystem("default"));
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

TEST_F(CustomerTest, CustomerConstructor) {
  picojson::object obj = JsonHelper::CreateJsonObject();
  JsonHelper::AddStringToJsonObject(obj, "type", "customer");
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
  ASSERT_FLOAT_EQ(entity->GetPosition()[0], position[0]);
  ASSERT_FLOAT_EQ(entity->GetPosition()[1], position[1]);
  ASSERT_FLOAT_EQ(entity->GetPosition()[2], position[2]);
  ASSERT_EQ(entity->GetName(), "customer");
  
  
  // Checks that when GetDetails() is called, the entity returns 
  //  the picojson object that was used to initialize it
  ASSERT_EQ(picojson::value(system->GetEntities()[0]->GetDetails()).serialize(), picojson::value(obj).serialize());

}

}  // namespace csci3081
