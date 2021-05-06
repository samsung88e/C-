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
#include "json_helper.h"

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

    bool IsDynamic() const;

    /**
     * Sets the pointer to the customer the package is for.
     */
    void SetCustomer(Customer* customer);
    
    /**
     * Returns the pointer to the customer that the package is for.
     */
    Customer* GetCustomer();

    /**
     * Sets if the package has been deliverd (Currently not used).
     */
    void SetIsDelivered(bool isDelivered);

    /**
    * Gets isDelivered. Primarily used for testing purposes.
    */
    bool GetIsDelivered();

    /**
     * returns whether the package has been delivered (Currently not used).
     */
    bool IsDelivered();

    /**
     * Sets the position of the package.
     */
    void SetPosition(std::vector<float> position);
    
    /**
     * Gets the position of the package.
     */
    std::vector<float> GetPosition();

    /**
     * Set the package get scheduled.
     */
    void Scheduled();
    
    /**
     * Check if the package is a subject.
     */
    bool isSubject();
    
private:

    /// check varible if the package delivered.
    bool isDelivered;

    /// customer class uses.
    Customer* customer;
};

} // namespace csci3081

#endif
