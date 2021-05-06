/**
 * @file parabolic_route.h
 */
#ifndef PARABOLIC_ROUTE_H_
#define PARABOLIC_ROUTE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "Strategy/IPathStrategy.h"

namespace csci3081 {
	
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
 
class ParabolicRoute : public IPathStrategy{
public:

   /**
    *  This function gets the path of points for the parabolic route.
    */
	std::vector<std::vector<float>> GetPath(std::vector<float> pos, std::vector<float> dest){
		std::vector<std::vector<float>> points;
		Vector3D position(pos);
		Vector3D destination(dest);
		const Vector3D initial_position = position;
		
		// A counter to keep a limit on the number of points we add
		int iter = 0;
		
		Vector3D dist = position - destination;
		float initial_distance = dist.GetMagnitude();
		
		// intermediate vector to add to the list of vectors
		vector<float> to_add;
		
		while(!position.Equals(destination)){
			Vector3D direction = destination - position;
			direction = direction * (1.0 / direction.GetMagnitude());
			Vector3D vector_increment = direction;
			position = position + vector_increment;
			pos = position.GetVector();
			
			//vfind the drone's horizontal "coordinate" relative to its initial position
			Vector3D difference = position - initial_position;
			float curr_distance = difference.GetMagnitude();
			
			// use the parabolic equation y = - x^2/b + x, where b is the initial distance to the destination (this makes the curve a bit flatter)
			// set the value of y only
			to_add = pos;
			to_add.at(1) += curr_distance - (pow(curr_distance, 2) / initial_distance);
			if (iter % 25 == 0) {
				points.push_back(to_add);
			}
			position.SetVector(pos);
			iter++;
		}
		points.push_back(dest);
		return points;
	}
		
};

} // namespace csci3081

#endif
