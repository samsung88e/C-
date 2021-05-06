/**
 *@file robot.h
 */
#ifndef ROBOT_H_
#define ROBOT_H_

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
 * @brief This is the class for the robot which inherents off the EntityDeliver class
 * and the IEntity interface
 *
 * This class creates and destroys robots
 */
class Robot : public csci3081::EntityDeliverer {
  public:
    Robot(std::vector<float> pos, std::vector<float> direction, float speed, const picojson::object& obj, bool fly, float batteryCapacity = 10000.f);
    ~Robot();
};

} // namespace csci3081

#endif 