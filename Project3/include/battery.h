/**
 * @file battery.h
 */
#ifndef BATTERY_H_
#define BATTERY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity_base.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Represents a Battery for the Drone and Robot class to use.
 * 
 * This is a class contained for drone and robot class
 * Check if the objects have enough charge to work or not.
 * 
 */
class Battery {
public:

    /**
    * @brief Default constructor for Battery class.
    *
    * Set battery charge = 10000.f, chargeRate = 10000.f, 
    *  dechargeRate = 1.f, chargeSize = 1.f. 
    */

    Battery(float charge = 10000.f, float chargeSize = 10000.f, float chargeRate = 1.f, float dechargeRate = 1.f);
    
    /**
    * @brief Default destructor for Battery class.
    * 
    * Set battery charge = 10000.f, chargeRate = 10000.f,
    * dechargeRate = 1.f, chargeSize = 1.f.
    */
    
    
    /**
    * @brief update the battery capacity with dt.
    * @param dt a float value.
    * 
    * set the battery capacity + dt.
    */ 
    void Charge(float dt);

    /**
    * @brief update the battery capacity with dt.
    * @param dt a float value.
    * 
    * set the battery capacity - dt.
    */ 
    void Decharge(float dt);

    /**
    * @brief Setter for the battery capacity.
    * @param charge a float value.
    * 
    * set the battery capacity.
    */ 
    void SetCharge(float charge);
    
    /**
    * @brief Getter for the remaining battery capacity.
    * @return The remaining battery capacity.
    */
    float GetCharge();

    /**
    * @brief Setter for the maximum battery charge.
    * @return The maximum battery capacity.
    */
    void SetChargeSize(float chargeSize);
    
    /**
    * @brief Getter for the maximum battery charge.
    * @return The maximum battery capacity.
    */
    float GetChargeSize();



private:
    /// Stores the battery capacity.
    float charge;

    /// Stores the battery size.
    float chargeSize;

    /// Stores the battery rate.
    float chargeRate;

    /// Stores the battery decreasing capacity.
    float dechargeRate;
    };

} // namespace csci3081

#endif
