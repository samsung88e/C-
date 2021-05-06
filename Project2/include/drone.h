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
#include "AEntitySubject.h"
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

class Drone : public csci3081::EntityBase {
  public:
    /**
    * @brief Constructor: this creates a drone and sets it's position direction and speed.
    */
    Drone(std::vector<float> pos, std::vector<float> direction, float speed, const picojson::object& obj);

    /**
     * Returns the ID of the drone.
     */
    int GetId() const;

    /**
     * Returns the Name of the drone.
     */
    const std::string& GetName();

    /**
     * Returns the current position of the drone.
     */
    const std::vector<float>& GetPosition() const;

    /**
     * Returns the current direction of the drone.
     */
    const std::vector<float>& GetDirection() const;

    /**
     * Returns the radius of the drone.
     */
    float GetRadius() const;

    /**
     * Returns the Version of the drone (Not yet implemeted).
     */
    int GetVersion() const;

    /**
     * Returns if the drone is dynamic or not.
     */
    bool IsDynamic() const;

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
     * Sets if the drone is currently holding a package.
     */
    void SetHasPackage(bool hasPackage);

    /**
     * Returns whether the drone is currently holding a package.
     */
    bool HasPackage();

    /**
     * Sets if the drone has a delivery.
     */
    void SetHasDelivery(bool hasDelivery);

    /**
     * Sets the package that the drone will be delivering to the customer.
     */
    void SetPackage(Package* package);

    /**
     * Sets has package to true.
     */
    void PickupPackage(AEntitySubject* sub);

    /**
     * Sets has package to false and has delivery to false.
     */
    void DeliverPackage(AEntitySubject* sub);

    /**
     * Returns a pointer to the package the drone is scheduled to deliver.
     */
    Package* GetPackage();

    void Idle(AEntitySubject* sub);

    //TEMP
    void addPathVal(picojson::value val);

    void updateObserverPath(AEntitySubject* sub);

  private:
    std::queue<std::vector<float>> points;
    std::vector<float> position{0.f,0.f,0.f};
    std::vector<float> direction{0.f,0.f,0.f};
    float radius;
    int version;
    std::string name;
    int id;
    bool hasDelivery;
    bool hasPackage;
    Package* package;
    float speed;

    //TEMP
    std::vector<picojson::value> pathVals;

};

}

#endif 