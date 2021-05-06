/**
 * @file DistanceFromDecorator.h
 */
#ifndef DISTANCE_FROM_DECORATOR_H_
#define DISTANCE_FROM_DECORATOR_H_

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
 * @brief This is the concrete entity decorators by distnace.
 *
 * This class is for creating a new base entity decorator object to change the color
 * by the distance to destination.
 */
class DistanceFromDecorator : public csci3081::EntityDecorator {
public:
    // Constructor creates a new base entity decorator object and gives it the pointer of the
    // entity to be decorated. 
    DistanceFromDecorator(IEntity* entity) {
        this->entity = entity;   
    }

    // check if  the entity has package to change the color.
    void HasDelivery();

    // This class only decorates the MoveToPoints function.
    void MoveToPoints(float dt) {
        picojson::value val;
        std::string json = "{\"details\": {\"color\": \"0xFFFF00\"},\"type\": \"notify\", \"value\": \"updateDetails\"}";
        picojson::parse(val, json);
        entitySubject->Notify(val, *entity);
    }

    // To check the entity, drone or robot. 
    bool IsDynamic() const { return entity->IsDynamic(); }

private:
    /// store the entities.
    IEntity* entity;

};

} // namespace csci3081


#endif