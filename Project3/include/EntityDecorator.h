/**
 *@file EntityDecorator.h
 */
#ifndef ENTITY_DECORATOR_H_
#define ENTITY_DECORATOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "EntityDeliverer.h"
#include "AbstractDeliverer.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the base decorator class of any entities.
 *
 * Its job is to pass all function calls through to the decorated entities.
 */
class EntityDecorator : public csci3081::EntityDeliverer {
public:
    // A default constructor stores the constructed object.
    EntityDecorator(AbstractDeliverer* entity) : entity(entity) {}
    
    // virtual MoveToPoints 
    virtual void MoveToPoints(float dt) {
        entity->MoveToPoints(dt);
    }

    // virtual GetPackage 
    virtual Package* GetPackage() {
        entity->GetPackage();
    }
    
    // virtual AddPoint 
    virtual void AddPoint(std::vector<float> point) {
        entity->AddPoint(point);
    }

    // virtual RemovePoint 
    virtual void RemovePoint() {
        entity->RemovePoint();
    }
    
    // virtual HasDelivery
    virtual bool HasDelivery() {
        entity->HasDelivery();
    }
    
    // virtual SetHasDelivery
    virtual void SetHasDelivery(bool hasDelivery) {
        entity->SetHasDelivery(hasDelivery);
    }

    // virtual HasPackage
    virtual bool HasPackage() {
        entity->HasPackage();
    }
    
    // virtual SetHasPackage
    virtual void SetHasPackage(bool hasPackage) {
        entity->SetHasPackage(hasPackage);
    }
    
    // virtual SetPackage
    virtual void SetPackage(Package* package) {
        entity->SetHasPackage(package);
    }
    
    // virtual PickupPackage
    virtual void PickupPackage() {
        entity->PickupPackage();
    }

    // virtual DeliverPackage
    virtual void DeliverPackage() {
        entity->DeliverPackage();
    }

    // virtual Idle
    virtual void Idle() {
        entity->Idle();
    }

    // virtual IsBatteryEmpty
    virtual bool IsBatteryEmpty() {
        entity->IsBatteryEmpty();
    }

    // virtual IsIdle
    virtual bool IsIdle() {
        entity->IsIdle();
    }

    // virtual updateObserverPath
    virtual void updateObserverPath() {
        entity->updateObserverPath();
    }

    // virtual IsDynamic
    virtual bool IsDynamic() const {
        entity->IsDynamic();
    }

    // virtual UpdateColor
    virtual void UpdateColor(std::string color) {
        entity->UpdateColor(color);
    }

    virtual bool CanFly() {
       entity->CanFly();
     }
    virtual int GetIdentification() {
       return entity->GetIdentification();
    }
    virtual picojson::object GetObject() {
       return entity->GetObject();
    }

protected:
    /// stores entities, drone or robot.
    AbstractDeliverer* entity;
};

}  // namespace csci3081

#endif