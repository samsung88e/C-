#ifndef ABSTRACT_DELIVERER_H_
#define ABSTRACT_DELIVERER_H_

#include "battery.h"
#include "AEntitySubject.h"
#include "package.h"

namespace csci3081 {

class AbstractDeliverer {
public:
    virtual void MoveToPoints(float dt) = 0;

    virtual Battery* GetBattery() = 0;

    virtual AEntitySubject* GetSubject() = 0;
       /**
     * Adds a vector(x,y,x) point to a queue of points
     */
    virtual void AddPoint(std::vector<float> point) = 0;

    /**
     * Removes a vector(x,y,x) point from a queue of points (Not used anywhere currently)
     */
    virtual void RemovePoint() = 0;

    /**
     * Returns whether the drone has a delivery or not.
     */
    virtual bool HasDelivery() = 0;
    
    /**
     * Sets if the drone has a delivery.
     */
    virtual void SetHasDelivery(bool hasDelivery) = 0;

    /**
     * Returns whether the drone is currently holding a package.
     */
    virtual bool HasPackage() = 0;
    
     /**
     * Sets if the drone is currently holding a package.
     */
    virtual void SetHasPackage(bool hasPackage) = 0;
    
    /**
     * Returns a pointer to the package the drone is scheduled to deliver.
     */
    virtual Package* GetPackage() = 0;
    
    /**
     * Sets the package that the drone will be delivering to the customer.
     */
    virtual void SetPackage(Package* package) = 0;
  
    /**
     * Sets has package to true.
     */
    virtual void PickupPackage() = 0;

    /**
     * Sets has package to false and has delivery to false.
     */
    virtual void DeliverPackage() = 0;

    /**
     * Sets the drone to be Idled.
     */
    virtual void Idle() = 0;

    /**
     * Checks if the battery of the drone is empty.
     */
    virtual bool IsBatteryEmpty() = 0;

    /**
     * Checks if the state of the drone is idle.
     */
    virtual bool IsIdle() = 0;

    /**
     * Updates the drone's moving path to be observed.
     */
    virtual void updateObserverPath() = 0;

    /**
     * Checks varible if the drone is moving.
     */
    virtual bool IsDynamic() const = 0;

    virtual void UpdateColor(std::string color) = 0;

    virtual bool CanFly() = 0;

    virtual int GetIdentification() = 0;

    virtual picojson::object GetObject() = 0; 
};

}

#endif