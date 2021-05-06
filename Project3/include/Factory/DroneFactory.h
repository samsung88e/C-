/**
 * @file DroneFactory.h
 */
#ifndef DRONE_FACTORY_H_
#define DRONE_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "delivery_simulation.h"
#include "json_helper.h"
#include "drone.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is class creates new Drone entities. It is used with the CompositeFactory class to create drones.
 */
class DroneFactory : public entity_project::IEntityFactory {
    public: 
    
        /**
        * Creates a Drone entity by getting data with methods from the JsonHelper class and then returning a new Drone entity.
        */
        IEntity* CreateEntity(const picojson::object& val) {
            if (JsonHelper::GetString(val, "type") == "drone") {
                std::vector<float> position = JsonHelper::GetStdFloatVector(val, "position");
                std::vector<float> direction = JsonHelper::GetStdFloatVector(val, "direction");
                float speed = static_cast<float>(JsonHelper::GetDouble(val, "speed"));
                float chargeCap;
                if(JsonHelper::ContainsKey(val, "battery_capacity")) {
                   chargeCap = static_cast<float>(JsonHelper::GetDouble(val, "battery_capacity"));
                   return new Drone(position, direction, speed, val, true, chargeCap);
                }
                return new Drone(position, direction, speed, val, true);
            }

            return NULL;
        }
};

} // namespace csci3081

#endif
