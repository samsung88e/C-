/**
 *@file EntityDeliverer.h
 */
#ifndef ENTITY_DELIVERER_H_
#define ENTITY_DELIVERER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "package.h"
#include "entity_base.h"
#include "vector3D.h"
#include "battery.h"
#include "AbstractDeliverer.h"
#include <vector>
#include <string>
#include <queue>

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the class for the drone which inherents off the EntityBase class
 * and the IEntity interface
 *
 * This class controlls all the atributes of a drone including movment and picking up and delivering packages
 */

class EntityDeliverer : public csci3081::EntityBase , public csci3081::AbstractDeliverer  {
  public:
    /**
     * Adds a vector(x,y,x) point to a queue of points
     */
    void AddPoint(std::vector<float> point);

    /**
     * Removes a vector(x,y,x) point from a queue of points (Not used anywhere currently)
     */
    void RemovePoint();
    
    /**
     * Moves the drone to the next point in the queue and then removes the point from
     * the queue when the drone reaches that point. It currently also handles moving the
     * package when the drone picks it up.
     */
    void MoveToPoints(float dt);

    /**
     * Returns whether the drone has a delivery or not.
     */
    bool HasDelivery();
    
    /**
     * Sets if the drone has a delivery.
     */
    void SetHasDelivery(bool hasDelivery);

    /**
     * Returns whether the drone is currently holding a package.
     */
    bool HasPackage();
    
     /**
     * Sets if the drone is currently holding a package.
     */
    void SetHasPackage(bool hasPackage);
    
    /**
     * Returns a pointer to the package the drone is scheduled to deliver.
     */
    Package* GetPackage();
    
    /**
     * Sets the package that the drone will be delivering to the customer.
     */
    void SetPackage(Package* package);
  
    /**
     * Sets has package to true.
     */
    void PickupPackage();

    /**
     * Sets has package to false and has delivery to false.
     */
    void DeliverPackage();

    /**
     * Sets the drone to be Idled.
     */
    void Idle();

    /**
     * Checks if the battery of the drone is empty.
     */
    bool IsBatteryEmpty();

    /**
     * Checks if the state of the drone is idle.
     */
    bool IsIdle();

    /**
     * Updates the drone's moving path to be observed.
     */
    void updateObserverPath();

    /**
     * Checks varible if the drone is moving.
     */
    bool IsDynamic() const;

    /**
     * Updates the color using RGB color.
     */
    void UpdateColor(std::string color);

    /**
     * Checks varible if the entity is deliverer.
     */
    bool IsDeliverer();

    /**
    * Checks varible if the entity can fly.
    */
    bool CanFly();

    Battery* GetBattery();

    AEntitySubject* GetSubject();

    int GetIdentification();

    picojson::object GetObject();

  protected:

    /// points to move between points.
    std::deque<std::vector<float>> points;
    std::vector<std::vector<float>> path;
    int version;
    bool hasDelivery;
    bool hasPackage;
    bool isIdle;
    bool canFly;
    float speed;



    /// package class uses.
    Package* package;
    
    /// battery class uses.
    Battery* battery;

    /// stores the paths
    std::vector<picojson::value> pathVals;

  };

} // namespace csci3081

#endif 
