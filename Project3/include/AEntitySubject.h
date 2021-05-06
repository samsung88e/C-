#ifndef A_ENTITY_SUBJECT_H_
#define A_ENTITY_SUBJECT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <EntityProject/facade/delivery_system.h>


namespace csci3081
{

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Represents a type of observer that will be observing objects.
 * 
 * This is a helper class for drone and robot class
 * Check if the objects have enough battery to work or not 
 * 
 */
class AEntitySubject {
    public:

        /**
        * @brief Adds observer to the package
        * @post IEntityObserver vector obs will contain the new observer added
        * 
        * Used to add an observer to observe any changes to the package. Observers
        *  will be added to the IEntityObserver vector observers.
        *
        * @param[in] observer An entity observer pointer
        */
        void Attach(IEntityObserver* observer);

        /**
        * @brief Removes observer from the package
        * 
        * @pre AddObserver(IEntityObserver* observer) has been called, and the obs 
        *       vector storing observers should not be empty
        * 
        * @post An observer will be removed from obs vector. Obs vector size will be reduced by 1.
        * 
        * A observer will be removed from the IEntityObserver vector.
        *
        * @param[in] observer An entity observer pointer
        */
        void Detach(IEntityObserver* observer);

        /**
        * @brief Notifies the observer the current status of the package.
        * 
        * @pre IEntityObserver vector observers should not be empty.
        * 
        * @post A message is sent.
        * 
        * Loops through IEntityObserver, calling OnEvent on each observer, which lets
        *  the user know that an event has happened.
        *
        */
        void Notify(const picojson::value& event, const IEntity& entity);
    private:
        std::vector<IEntityObserver*> observers;
};
    
} // namespace csci3081

#endif
