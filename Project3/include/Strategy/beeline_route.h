/**
 * @file beeline_route.h
 */
#ifndef BEELINE_ROUTE_H_
#define BEELINE_ROUTE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "IPathStrategy.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the concrete strategy for the Beeline Route.
 *
 * This class will return a short vector of floating-point vectors, 
 * that will form a beeline route for a drone from an initial point and 
 * a destination point.
 */

class BeelineRoute : public IPathStrategy{
public:

   /**
    *  This function gets the path of points for the beeline route.
    */
	std::vector<std::vector<float>> GetPath(std::vector<float> pos, std::vector<float> dest){
        std::vector<std::vector<float>> points;

        vector<float>pointA = pos;
        vector<float>pointB = dest;
        pointA.at(1) += 100;
        pointB.at(1) += 100;

        points.push_back(pos);
        points.push_back(pointA);
        points.push_back(pointB);
        points.push_back(dest);
		return points;
	}

};

} // namespace csci3081

#endif
