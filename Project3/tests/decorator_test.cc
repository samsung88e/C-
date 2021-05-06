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
#include "EntityDecorator.h"
#include "BatteryLifeDecorator.h"
#include "EntityDeliverer.h"

#include <iostream>
using std::string;

namespace csci3081 {

using entity_project::IEntity;

class DecoratorTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    system = dynamic_cast<IDeliverySystem*>(GetEntitySystem("default"));
    system->AddFactory(new DroneFactory());
	//~ entitySubject = new AEntitySubject();
  }
  virtual void TearDown() {}

  IDeliverySystem* system;
   //~ AEntitySubject* entitySubject;
};

TEST_F(DecoratorTest, InitialTest){

    picojson::object obj = JsonHelper::CreateJsonObject();
    JsonHelper::AddStringToJsonObject(obj, "type", "drone");
    std::vector<float> position;
    position.push_back(100);
    position.push_back(0);
    position.push_back(0);
    JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position);
    std::vector<float> direction;
    direction.push_back(1);
    direction.push_back(0);
    direction.push_back(0);
    JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction);
    JsonHelper::AddFloatToJsonObject(obj, "speed", 50);
    IEntity* entity = system->CreateEntity(obj);
    // Checks that the returned entity is not NULL
    ASSERT_NE(entity, nullptr) << "The entity created";
    system->AddEntity(entity);
    ASSERT_EQ(1, system->GetEntities().size());
    Drone* DronePtr = dynamic_cast<Drone*>(entity);
    AbstractDeliverer* abstractDeliverer = dynamic_cast<AbstractDeliverer*>(entity);
    abstractDeliverer = new BatteryLifeDecorator(abstractDeliverer);



    Battery* battery = DronePtr->GetBattery();

    std::vector<float> vec1{0, 0, 0};
	DronePtr->AddPoint(vec1);
	//abstractDeliverer->MoveToPoints(1);
    ASSERT_EQ(JsonHelper::GetString(DronePtr->GetDetails(), "color"), "0x58D68D") << JsonHelper::GetString(DronePtr->GetDetails(), "color") << std::endl;
    //abstractDeliverer->MoveToPoints(2);
    ASSERT_EQ(JsonHelper::GetString(DronePtr->GetDetails(), "color"), "0x58D68D") << JsonHelper::GetString(DronePtr->GetDetails(), "color") << std::endl;

}

}