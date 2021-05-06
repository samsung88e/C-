/**
 * @file RobotFactory.h
 */
#ifndef ROBOT_FACTORY_H_
#define ROBOT_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "delivery_simulation.h"
#include "json_helper.h"
#include "robot.h"

namespace csci3081 {

/**
 * @brief This is class creates new Robot entities. It is used with the CompositeFactory class to create robots.
 */
class RobotFactory : public entity_project::IEntityFactory {
    public: 
        /**
        * Creates a Robot entity by getting data with methods from the JsonHelper class and then returning a new Robot entity.
        */
        IEntity* CreateEntity(const picojson::object& val) {
            if (JsonHelper::GetString(val, "type") == "robot") {
                std::vector<float> position = JsonHelper::GetStdFloatVector(val, "position");
                std::vector<float> direction = JsonHelper::GetStdFloatVector(val, "direction");
                float speed = static_cast<float>(JsonHelper::GetDouble(val, "speed"));
                return new Robot(position, direction, speed, val);
            }

            return NULL;
        }
};

}





#endif