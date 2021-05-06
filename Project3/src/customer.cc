#include "customer.h"


namespace csci3081 {

Customer::Customer(std::vector<float> position, std::vector<float> direction,
                                        const picojson::object& details) {

    for(int i = 0; i < position.size(); i++)
    {
        this->position[i] = position[i];
    }
    name = "customer";
    id = GenerateId();

  // The following line saves the json object in the details_ member variable
  // from the EntityBase class, in order to return it later in GetDetails()
    details_ = details;
}

bool Customer::IsDynamic() const {
  // This is just a stub for compilation.
  return true;
}

}
