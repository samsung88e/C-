/**
 *@file entity_controller.h
 */
#ifndef ENTITY_CONTROLLER_H_
#define ENTITY_CONTROLLER_H_

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the controller class for the objects to move, deliver, and pickup the package.
 *
 * This class holds all the values of a package including is position and it's customer.
 */

class EntityController {
    public:
        void Move();
        void Deliver();
        void Pickup();
    };

} // namespace csci3081

#endif
