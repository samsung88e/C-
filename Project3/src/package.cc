#include "package.h"

namespace csci3081 {

Package::Package(std::vector<float> position, std::vector<float> direction, const picojson::object& details) {

    for(int i = 0; i < position.size(); i++)
    {
        this->position[i] = position[i];
        this->direction[i] = direction[i];
    }

    
    name = "package";
    isDelivered = false;

    id = GenerateId();


  // The following line saves the json object in the details_ member variable
  // from the EntityBase class, in order to return it later in GetDetails()
    details_ = details;
}

bool Package::IsDynamic() const {
  //This is just a stub for compilation
  return true;
}

void Package::SetCustomer(Customer* customer) {
  this->customer = customer;
}

Customer* Package::GetCustomer() {
  return customer;
}

void Package::SetIsDelivered(bool isDelivered) {
  this->isDelivered = isDelivered;
}

bool Package::GetIsDelivered(){
  return isDelivered;
}

bool Package::IsDelivered() {
  return isDelivered;
}

void Package::SetPosition(std::vector<float> position) {
  this->position = position;
}

std::vector<float> Package::GetPosition(){
	return position;
}

void Package::Scheduled() {
  picojson::value val;
  const char* json = "{\"type\": \"notify\", \"value\": \"scheduled\"}";
  picojson::parse(val, json);

  entitySubject->Notify(val, *this);
}

bool Package::isSubject() {
  return true;
}




};
