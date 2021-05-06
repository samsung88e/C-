/**
 *@file drone.h
 */
#ifndef DRONE_H_
#define DRONE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "package.h"
#include "entity_base.h"
#include "vector3D.h"
#include "battery.h"
#include "EntityDeliverer.h"
#include <vector>
#include <string>
#include <queue>

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the class for the drone which inherents off the EntityDeliver class
 * and the IEntity interface
 *
 * This class creates and destructs drones
 */

class Drone : public csci3081::EntityDeliverer {
  public:
    Drone(std::vector<float> pos, std::vector<float> direction, float speed, const picojson::object& obj, bool canFly, float batteryCapacity = 10000.f);

    ~Drone();
  };

} // namespace csci3081

#endif 
