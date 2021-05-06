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
    
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the class for the customer which inherents off the EntityBase class
 * and the IEntity interface
 *
 * This class holds all the values of a customer including is position.
 */

class Customer : public csci3081::EntityBase {
public:
    /**
    * @brief Constructor: This creates a customer and sets its position and direction.
    */
    Customer(std::vector<float> position, std::vector<float> direction, const picojson::object& details);

    /// to check if the Customer can move.
    bool IsDynamic() const;

    };
} // namespace csci3081


#endif
