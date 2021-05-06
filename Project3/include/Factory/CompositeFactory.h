#ifndef COMPOSITE_FACTORY_H_
#define COMPOSITE_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "delivery_simulation.h"
#include "json_helper.h"
#include <vector>

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the class for the Composite Factory pattern which uses the IEntityFactory interface.
 * This pattern is used to keep track of all the factories and makes adding more factory classes simpler.
 * This class should not have to be modified if you need to add more factory classes.
 */
class CompositeFactory : public entity_project::IEntityFactory {
    public: 
    
        /**
        * Adds a factory that uses the IEntityFactory interface to the factory list.
        */
        void AddFactory(IEntityFactory* factory) {
            factoryList.push_back(factory);
        }

        /**
        * Searches through all the factories until one of the factories creates an entity else it returns NULL.
        */
        IEntity* CreateEntity(const picojson::object& val) {
            for (IEntityFactory* fac : factoryList) {
                IEntity* entity = fac->CreateEntity(val);
                if (entity) {
                    return entity;
                }
            }
            return NULL;
        }

    private:

        /**
        * Stores the created factories.
        */
        std::vector<IEntityFactory*> factoryList;
};

} // namespace csci3081

#endif
