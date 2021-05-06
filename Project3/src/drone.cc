#include "drone.h"

#include <iostream>
using namespace std;

namespace csci3081 {

Drone::Drone(std::vector<float> position, std::vector<float> direction, float speed, const picojson::object& details, bool fly, float batteryCapacity) {
  for(int i = 0; i < position.size(); i++)
  {
    this->position[i] = position[i];
    this->direction[i] = direction[i];
  }

  name = "pkgDrone";
  hasDelivery = false;
  hasPackage = false;
  isIdle = false;
  details_ = details;
  canFly = fly;

  battery = new Battery();
  battery->SetChargeSize(batteryCapacity);
  battery->SetCharge(batteryCapacity);

  this->speed = speed;

  id = GenerateId();

  JsonHelper::AddStringToJsonObject(details_, "color", "0x58D68D");
}

Drone::~Drone() {
  delete battery;
}

}
