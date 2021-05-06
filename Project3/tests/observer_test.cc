#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include <EntityProject/web_scene_viewer.h>
#include <EntityProject/osm_graph_parser.h>
#include <EntityProject/graph.h>
#include <EntityProject/facade/delivery_system.h>
#include <EntityProject/entity_console_logger.h>
#include "AEntitySubject.h"
#include "Factory/DroneFactory.h"
#include "Factory/PackageFactory.h"

#include <iostream>
using namespace std;

namespace csci3081 {

using entity_project::IEntity;

class ObserverTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    system = dynamic_cast<IDeliverySystem*>(GetEntitySystem("default"));
    entity_project::EntityConsoleLogger logger;
    system->AddObserver(&logger);
    system->AddFactory(new DroneFactory());
    system->AddFactory(new PackageFactory());
    entitySubject = new AEntitySubject();
  }
  virtual void TearDown() {}
  
  AEntitySubject* entitySubject;
  IDeliverySystem* system;
};


TEST_F(ObserverTest, EntityIdleObsever) {
    picojson::object obj = JsonHelper::CreateJsonObject();
    JsonHelper::AddStringToJsonObject(obj, "type", "drone");
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
    JsonHelper::AddFloatToJsonObject(obj, "speed", 30);
    IEntity* entity = system->CreateEntity(obj);

    Drone* drn = dynamic_cast<Drone*>(entity);

    drn->SetEntitySubject(entitySubject);
    drn->Idle();
    ASSERT_EQ(drn->IsIdle(), true);


    ASSERT_EQ(picojson::value(drn->GetDetails()).serialize(), "{\"color\":\"0x58D68D\",\"direction\":[1,0,0],\"position\":[498.2919921875,253.88299560546875,-228.62300109863281],\"speed\":30,\"type\":\"drone\"}");

}

TEST_F(ObserverTest, EntityDeliverPackageObsever) {
    picojson::object obj = JsonHelper::CreateJsonObject();
    JsonHelper::AddStringToJsonObject(obj, "type", "drone");
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
    JsonHelper::AddFloatToJsonObject(obj, "speed", 30);
    IEntity* drone = system->CreateEntity(obj);

    picojson::object obj2 = JsonHelper::CreateJsonObject();
    JsonHelper::AddStringToJsonObject(obj2, "type", "package");
    std::vector<float> position_to_add2;
    position_to_add2.push_back(490.292);
    position_to_add2.push_back(252.883);
    position_to_add2.push_back(-220.623);
    JsonHelper::AddStdFloatVectorToJsonObject(obj2, "position", position_to_add2);
    std::vector<float> direction_to_add2;
    direction_to_add2.push_back(1);
    direction_to_add2.push_back(0);
    direction_to_add2.push_back(0);
    JsonHelper::AddStdFloatVectorToJsonObject(obj2, "direction", direction_to_add2);
    IEntity* package = system->CreateEntity(obj2);

    Package* pkg = dynamic_cast<Package*>(package);
    Drone* drn = dynamic_cast<Drone*>(drone);

    drn->SetPackage(pkg);
    drn->SetEntitySubject(entitySubject);

    drn->DeliverPackage();

    ASSERT_EQ(picojson::value(drn->GetDetails()).serialize(), "{\"color\":\"0x58D68D\",\"direction\":[1,0,0],\"position\":[498.2919921875,253.88299560546875,-228.62300109863281],\"speed\":30,\"type\":\"drone\"}");

}






}
