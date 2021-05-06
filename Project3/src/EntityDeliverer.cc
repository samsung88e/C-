#include "EntityDeliverer.h"

#include <iostream>
using namespace std;

namespace csci3081 {

bool EntityDeliverer::IsDynamic() const {
  return true;
}

void EntityDeliverer::AddPoint(std::vector<float> point) {
  points.push_back(point);
}

void EntityDeliverer::RemovePoint() {
  points.pop_front();
}

void EntityDeliverer::MoveToPoints(float dt) {
  if(points.empty()) { return; }
  if(isIdle) { return; }

  Vector3D pos(position);
  Vector3D dest(points.front());
  Vector3D dir(dest - pos);

  Vector3D normDir = dir.GetNormalizedVector();

  for (int i = 0; i < direction.size(); i++) {
    direction.at(i) = normDir.GetVector()[i];
  }

  Vector3D motionVector = normDir * speed * dt;

  if((dest-pos).GetMagnitude() < speed*dt){
    position = points.front();
    points.pop_front();
  }
  else{
    for (int i = 0; i < position.size(); i++) {
      position.at(i) = position.at(i) + motionVector.GetVector()[i];
    }
  }

  if (hasPackage) {
    package->SetPosition(position);
  }

  battery->Decharge(dt);
}

bool EntityDeliverer::HasDelivery() {
  return hasDelivery;
}

void EntityDeliverer::SetHasDelivery(bool hasDelivery) {
  this->hasDelivery = hasDelivery;
}

void EntityDeliverer::SetPackage(Package* package) {
  this->package = package;
}

void EntityDeliverer::SetHasPackage(bool hasPackage) {
  this->hasPackage = hasPackage;
}

bool EntityDeliverer::HasPackage() {
  return hasPackage;
}

void EntityDeliverer::PickupPackage() {
  hasPackage = true;

  // Send on route to Observers
  picojson::value val;
  std::string json = "{\"type\": \"notify\", \"value\": \"en route\"}";
  picojson::parse(val, json);
  entitySubject->Notify(val, *this);

  // Send Path to Observers
  updateObserverPath();

}

void EntityDeliverer::DeliverPackage() {
  hasPackage = false;
  hasDelivery = false;
  package->SetIsDelivered(true);

  // Send Path to Observers
  picojson::value val;
  const char* json = "{\"type\": \"notify\", \"value\": \"delivered\"}";
  picojson::parse(val, json);
  entitySubject->Notify(val, *this);
}

Package* EntityDeliverer::GetPackage() {
  return package;
}

void EntityDeliverer::Idle() {
  isIdle = true;
  picojson::value val;
  const char* json = "{\"type\": \"notify\", \"value\": \"idle\"}";
  picojson::parse(val, json);
  entitySubject->Notify(val, *this);


}

bool EntityDeliverer::IsBatteryEmpty() {
    return (battery->GetCharge() < 0.0001f);
}

bool EntityDeliverer::IsIdle() {
  return isIdle;
}

void EntityDeliverer::updateObserverPath() {
  picojson::value val;
  std::string json;

  for(auto point : path) {
    path.pop_back();
  }
  for(auto point : points) {
    path.push_back(point);
  }

  picojson::value pathVal = JsonHelper::EncodeArray(path);
    std::string str = pathVal.serialize();
    json = "{\"type\": \"notify\", \"value\": \"moving\", \"path\":" + str + "}";
    picojson::parse(val, json);
    entitySubject->Notify(val, *this);
}

void EntityDeliverer::UpdateColor(std::string color) {
  picojson::value val;
  std::string json = "{\"details\": {\"color\": \"" + color + "\"},\"type\": \"notify\", \"value\": \"updateDetails\"}";
  picojson::parse(val, json);
  entitySubject->Notify(val, *this);
}

bool EntityDeliverer::IsDeliverer() {
  return true;
}

bool EntityDeliverer::CanFly() {
  return canFly;
}

Battery* EntityDeliverer::GetBattery() {
  return battery;
}

AEntitySubject* EntityDeliverer::GetSubject() {
  return entitySubject;
}

int EntityDeliverer::GetIdentification() {
  return id;
}

picojson::object EntityDeliverer::GetObject() {
  return details_;
}

}
