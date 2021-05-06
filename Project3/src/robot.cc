#include "robot.h"

namespace csci3081{

Robot::Robot(std::vector<float> position, std::vector<float> direction, float speed, const picojson::object& details, bool fly, float batteryCapacity) {
      for(int i = 0; i < position.size(); i++){
            this->position[i] = position[i];
            this->direction[i] = direction[i];  
      }

      name = "pkgRobot";
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

Robot::~Robot() {
  delete battery;
}
    
}
