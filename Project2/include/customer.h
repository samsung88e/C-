/**
 *@file customer.h
 */
#ifndef CUSTOMER_H_
#define CUSTOMER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity_base.h"
#include "vector3D.h"


namespace csci3081 {

/**
 * @brief This is the class for the customer which inherents off the EntityBase class
 * and the IEntity interface
 *
 * This class holds all the values of a customer including is position.
 */

class Customer : public csci3081::EntityBase {
public:
    /**
    * @brief Constructor: this creates a customer and sets it's position and direction.
    */
    Customer(std::vector<float> position, std::vector<float> direction, const picojson::object& details);

    /**
     * Returns the ID of the customer.
     */
    int GetId() const;

    /**
     * Returns the Name of the customer.
     */
    const std::string& GetName();

    /**
     * Returns the current position of the customer.
     */
    const std::vector<float>& GetPosition() const;

    /**
     * Returns the current direction of the customer.
     */
    const std::vector<float>& GetDirection() const;

    /**
     * Returns the radius of the customer.
     */
    float GetRadius() const;

    /**
     * Returns the Version of the customer (Not yet implemeted).
     */
    int GetVersion() const;

    /**
     * Returns if the customer is dynamic or not.
     */
    bool IsDynamic() const;

private:
    std::vector<float> position{0.f,0.f,0.f};
    std::vector<float> direction{0.f,0.f,0.f};
    float radius;
    int version;
    std::string name;
    int id;
};
}


#endif