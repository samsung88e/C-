/**
 * @file smart_route.h
 */
#ifndef SMART_ROUTE_H_
#define SMART_ROUTE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "IPathStrategy.h"

namespace csci3081{

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the concrete strategy for the Parabolic Route.
 *
 * This class will return a single vector of floating-point vectors, 
 * that will form a route shaped like an upside-down parabola, for a 
 * drone to travel along to reach a destination point. 
 */

class SmartRoute : public IPathStrategy {
public:

   /**
    *  This function gets the path of points for the smart route. It 
    * does easily by calling the GetPath method for a graph.
    */
    std::vector<std::vector<float>> GetPath(std::vector<float> pos, std::vector<float> dest){
		std::vector<std::vector<float>> path;
		std::vector<std::vector<float>> entToDest = graph->GetPath(pos, dest);
		for (std::vector<float> point : entToDest) {
			path.push_back(point);
		}
		return path;
    }

    /**
     * This function sets a graph that is passed to it. This way, the 
     * SmartRoute can access a graph that it holds.
     */
    void SetGraph(const IGraph* graph){ this->graph = graph; }
};

} // namespace csci3081

#endif

