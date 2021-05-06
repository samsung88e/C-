/**
 *@file package.h
 */
#ifndef PACKAGE_H_
#define PACKAGE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "customer.h"
#include "entity_base.h"
#include "vector3D.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @brief This is the class for the package which inherents off the EntityBase class
 * and the IEntity interface
 *
 * This class holds all the values of a package including is position and it's customer
 */

class Package : public csci3081::EntityBase {
public:
    /**
    * @brief Constructor: this creates a package and sets it's position and direction.
    */
    Package(std::vector<float> position, std::vector<float> direction, const picojson::object& details);

    /**
     * Returns the ID of the package.
     */
    int GetId() const;

    /**
     * Returns the Name of the package.
     */
    const std::string& GetName();

    /**
     * Returns the current position of the package.
     */
    const std::vector<float>& GetPosition() const;

    /**
     * Returns the current direction of the package.
     */
    const std::vector<float>& GetDirection() const;

    /**
     * Returns the radius of the package.
     */
    float GetRadius() const;

    /**
     * Returns the Version of the package (Not yet implemeted).
     */
    int GetVersion() const;

    /**
     * Returns if the package is dynamic or not.
     */
    bool IsDynamic() const;

    /**
     * Sets the pointer to the customer the package is for.
     */
    void SetCustomer(Customer* customer);

    /**
     * Sets if the package has been deliverd (Currently not used).
     */
    void SetIsDelivered(bool isDelivered);

    /**
     * returns whether the package has been delivered (Currently not used).
     */
    bool IsDelivered();

    /**
     * Returns the pointer to the customer that the package is for.
     */
    Customer* GetCustomer();

    /**
     * Sets the position of the package.
     */
    void SetPosition(std::vector<float> position);

private:
    std::vector<float> position{0.f,0.f,0.f};
    std::vector<float> direction{0.f,0.f,0.f};
    float radius;
    int version;
    std::string name;
    int id;
    bool isDelivered;
    Customer* customer;
};


}


#endif