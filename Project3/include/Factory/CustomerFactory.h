#ifndef CUSTOMER_FACTORY_H_
#define CUSTOMER_FACTORY_H_
#include "delivery_simulation.h"
#include "json_helper.h"
#include "customer.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is class creates new Customer entities. It is used with the CompositeFactory class to create customers.
 */
class CustomerFactory : public entity_project::IEntityFactory {
    public: 
    
        /**
        * Creates a Customer entity by getting data with methods from the JsonHelper class and then returning a new Customer entity.
        */
        IEntity* CreateEntity(const picojson::object& val) {
            if (JsonHelper::GetString(val, "type") == "customer") {
                std::vector<float> position = JsonHelper::GetStdFloatVector(val, "position");
                std::vector<float> direction = JsonHelper::GetStdFloatVector(val, "direction");
                return new Customer(position, direction, val);
            }

            return NULL;
        }
};

} // namespace csci3081

#endif
