#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include <EntityProject/web_scene_viewer.h>
#include <EntityProject/osm_graph_parser.h>
#include <EntityProject/graph.h>
#include <EntityProject/facade/delivery_system.h>
#include <EntityProject/entity_console_logger.h>
#include "Factory/CustomerFactory.h"
#include "Factory/PackageFactory.h"
#include "Factory/DroneFactory.h"
#include "Factory/RobotFactory.h"


#include <iostream>

namespace csci3081 {

using entity_project::IEntity;

class RobotTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    system = dynamic_cast<IDeliverySystem*>(GetEntitySystem("default"));
    system->AddFactory(new RobotFactory());
    system->AddFactory(new PackageFactory());
    entitySubject = new AEntitySubject();
  }
  virtual void TearDown() {}

  IDeliverySystem* system;
  AEntitySubject* entitySubject;
};

TEST_F(RobotTest, PointFunctionsTest){
    picojson::object obj = JsonHelper::CreateJsonObject();
    JsonHelper::AddStringToJsonObject(obj, "type", "robot");
    std::vector<float> position_to_add;
    position_to_add.push_back(100);
    position_to_add.push_back(0);
    position_to_add.push_back(0);
    JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position_to_add);
    std::vector<float> direction_to_add;
    direction_to_add.push_back(1);
    direction_to_add.push_back(0);
    direction_to_add.push_back(0);
    JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction_to_add);
    JsonHelper::AddFloatToJsonObject(obj, "speed", 100);
    IEntity* entity = system->CreateEntity(obj);

  // Checks that the returned entity is not NULL
    ASSERT_NE(entity, nullptr) << "The entity created";
    system->AddEntity(entity);
    Robot* robot1 = dynamic_cast <Robot*> (entity);
    std::vector<float> point1;
    point1.push_back(1);
    point1.push_back(0);
    point1.push_back(0);
    robot1->AddPoint(point1);
    robot1->MoveToPoints(1);
    EXPECT_LT(robot1->GetPosition()[0] - point1[0], 1);
    EXPECT_LT(robot1->GetPosition()[1] - point1[1], 1);
    EXPECT_LT(robot1->GetPosition()[2] - point1[2], 1);
    std::vector<float> point2;
    point2.push_back(0);
    point2.push_back(200);
    point2.push_back(0);
    robot1->AddPoint(point2);
    robot1->MoveToPoints(1);
    EXPECT_LT(robot1->GetPosition()[0] - point2[0], 1);
    EXPECT_LT(robot1->GetPosition()[1] - point2[1], 1);
    EXPECT_LT(robot1->GetPosition()[2] - point2[2], 1);

}

TEST_F(RobotTest, BooleanTests){
    picojson::object obj = JsonHelper::CreateJsonObject();
    JsonHelper::AddStringToJsonObject(obj, "type", "robot");
    std::vector<float> position_to_add;
    position_to_add.push_back(100);
    position_to_add.push_back(0);
    position_to_add.push_back(0);
    JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position_to_add);
    std::vector<float> direction_to_add;
    direction_to_add.push_back(1);
    direction_to_add.push_back(0);
    direction_to_add.push_back(0);
    JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction_to_add);
    JsonHelper::AddFloatToJsonObject(obj, "speed", 100);
    IEntity* entity = system->CreateEntity(obj);

  // Checks that the returned entity is not NULL
    ASSERT_NE(entity, nullptr) << "The entity created";
   // system->AddEntity(entity);
    Robot* robot1 = dynamic_cast<Robot*>(entity);
    EXPECT_EQ(robot1->HasDelivery(), false) << "hasDelivery constructor not working";
    robot1->SetHasDelivery(true);
    EXPECT_EQ(robot1->HasDelivery(), true) << "hasDelivery setter not working";
    EXPECT_EQ(robot1->HasPackage(), false) << "hasPackage constructor not working";

}

TEST_F(RobotTest, PackageTests){
  picojson::object obj = JsonHelper::CreateJsonObject();
  JsonHelper::AddStringToJsonObject(obj, "type", "package");
  std::vector<float> position_to_add;
  position_to_add.push_back(498.292);
  position_to_add.push_back(253.883);
  position_to_add.push_back(-228.623);
  JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", position_to_add);
  std::vector<float> direction_to_add;
  direction_to_add.push_back(1);
  direction_to_add.push_back(0);
  direction_to_add.push_back(0);
  JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", direction_to_add);
  IEntity* entity = system->CreateEntity(obj);

  // Checks that the returned entity is not NULL
  ASSERT_NE(entity, nullptr) << "The entity created";
  //system->AddEntity(entity);
  Package* package1 = dynamic_cast<Package*>(entity);

  picojson::object obj1 = JsonHelper::CreateJsonObject();
  JsonHelper::AddStringToJsonObject(obj1, "type", "robot");
  std::vector<float> position_to_add1;
  position_to_add1.push_back(100);
  position_to_add1.push_back(0);
  position_to_add1.push_back(0);
  JsonHelper::AddStdFloatVectorToJsonObject(obj1, "position", position_to_add1);
  std::vector<float> direction_to_add1;
  direction_to_add1.push_back(1);
  direction_to_add1.push_back(0);
  direction_to_add1.push_back(0);
  JsonHelper::AddStdFloatVectorToJsonObject(obj1, "direction", direction_to_add1);
  JsonHelper::AddFloatToJsonObject(obj1, "speed", 100);
  IEntity* entity2 = system->CreateEntity(obj1);

  // Checks that the returned entity is not NULL
  ASSERT_NE(entity2, nullptr) << "The entity created";
  system->AddEntity(entity2);
  Robot* robot1 = dynamic_cast<Robot*>(entity2);

  robot1->SetPackage(package1);
  EXPECT_EQ(robot1->GetPackage()->GetId(), package1->GetId());

}



}
