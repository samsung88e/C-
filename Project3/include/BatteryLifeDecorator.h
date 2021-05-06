/**
 *@file BatteryLifeDecorator.h
 */
#ifndef BATTERY_LIFE_DECORATOR_H_
#define BATTERY_LIFE_DECORATOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity_base.h"
#include "EntityDecorator.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the concrete entity decorators by battery life.
 * 
 * This class is for creating a new base entity decorator object to change the color
 * by the battery life.
 * Entity colors will be changed as 75% green, 50% yellow, 25% orange, 
 * 0% red, and 0% black, respectively.
 */    
class BatteryLifeDecorator : public csci3081::EntityDecorator {
public:
    // Constructor creates a new base entity decorator object and gives it the pointer of the
    // entity to be decorated. 
    BatteryLifeDecorator(AbstractDeliverer* entity) : EntityDecorator(entity), isGreen(false), isRed(false) {}


    // This class only decorates the MoveToPoints function.
    void MoveToPoints(float dt) override;

    void UpdateColor(std::string color);

private:
    bool isGreen;
    bool isRed;

};

} // namespace csci3081

#endif