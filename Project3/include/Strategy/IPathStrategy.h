/**
 * @file IPathStrategy.h
 */
#ifndef I_PATH_STRATEGY_H_
#define I_PATH_STRATEGY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <EntityProject/facade/delivery_system.h>
#include "delivery_simulation.h"
#include "vector3D.h"

namespace csci3081{

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the Strategy Pattern interface for the Path Strategy.
 * 
 * The DeliverySimulation class is the context class, which holds a
 * concrete instance of a strategy pattern while setting routes for
 * different entities.
 *
 */

class IPathStrategy{
    public:
	/**
	 * This is a destructor for the class since the strategy holds
	 * a reference to another class.
	 */
	virtual ~IPathStrategy(){ delete graph; }

	/**
	 * This is a pure virtual method that can be overriden to give 
	 * a vector of vectors as a path between a position and destination.
	 */
	virtual std::vector<std::vector<float>> GetPath(std::vector<float> pos, std::vector<float> dest) = 0;

	/**
	 * This is the method to set the graph for the strategy pattern.
	 * The default implementation is empty, since only the smart 
	 * route uses the graph.
	 */
	virtual void SetGraph(const IGraph* graph){}

	/**
	 * Get the graph that was held by the strategy, if it exists.
	 */
	const IGraph* GetGraph(){ return graph; }
		
    protected:
        const IGraph* graph;
};

} // namespace csci3081

#endif
