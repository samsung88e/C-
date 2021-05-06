/**
 * @file PackageFactory.h
 */
#ifndef PACKAGE_FACTORY_H_
#define PACKAGE_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "delivery_simulation.h"
#include "json_helper.h"
#include "package.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is class creates new Package entities. It is used with the CompositeFactory class to create packages.
 */
class PackageFactory : public entity_project::IEntityFactory {
    public: 

        /**
        * Creates a Package entity by getting data with methods from the JsonHelper class and then returning a new Package entity.
        */
        IEntity* CreateEntity(const picojson::object& val) {
            if (JsonHelper::GetString(val, "type") == "package") {
                std::vector<float> position = JsonHelper::GetStdFloatVector(val, "position");
                std::vector<float> direction = JsonHelper::GetStdFloatVector(val, "direction");
                return new Package(position, direction, val);
            }

            return NULL;
        }
};

} // namespace csci3081

#endif
