#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include <EntityProject/web_scene_viewer.h>
#include <EntityProject/osm_graph_parser.h>
#include <EntityProject/graph.h>
#include <EntityProject/facade/delivery_system.h>
#include <EntityProject/entity_console_logger.h>
//~ #include "Factory/CustomerFactory.h"
//~ #include "Factory/PackageFactory.h"
//~ #include "Factory/DroneFactory.h"
//~ #include "Factory/RobotFactory.h"
#include <delivery_simulation.h>

#include <iostream>
#include <math.h>
using namespace std;
using entity_project::OSMGraphParser;

namespace csci3081 {

using entity_project::IEntity;

class StrategyTest : public ::testing::Test {
protected:
	virtual void SetUp() {
		//~ system = dynamic_cast<IDeliverySystem*>(GetEntitySystem("default"));
		//~ system->AddFactory(new CustomerFactory());
		//~ system->AddFactory(new DroneFactory());
		//~ system->AddFactory(new PackageFactory());
		//~ system->AddFactory(new RobotFactory());
	}
	virtual void TearDown() {}

  IDeliverySystem* system;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(StrategyTest, BeelineGetPath){
	std::vector<float> initial_position{101.143, 250.999, -85.172};
	std::vector<float> final_position{-73.424, 250.999, 300.180};
	
	IPathStrategy* pathStrategy;
	pathStrategy = new BeelineRoute();
	std::vector<std::vector<float>> path;
	path = pathStrategy->GetPath(initial_position, final_position);
	
	//~ cout << "{ ";
	//~ for (int i = 0; i < path.size(); i++) {
		//~ cout << "{ ";
		//~ for (int j = 0; j < path[i].size(); j++){
		  //~ cout << path[i][j] << " ";
		//~ }
	//~ cout << "}\n";
	//~ }
	//~ cout << "}\n";
	
	
	std::vector<std::vector<float>> test_path = {
		{ 101.143, 250.999, -85.172 },
		{ 101.143, 350.999, -85.172 },
		{ -73.424, 350.999, 300.180 },
		{ -73.424, 250.999, 300.180 }
	};
	for (int i = 0; i < path.size(); i++) {
		for (int j = 0; j < path[i].size(); j++){
		  ASSERT_FLOAT_EQ(path[i][j], test_path[i][j]);
		}
	}
}

TEST_F(StrategyTest, ParabolicRoute){
	std::vector<float> initial_position{187, 250, 0};
	std::vector<float> final_position{187, 250, 400};
	
	IPathStrategy* pathStrategy;
	pathStrategy = new ParabolicRoute();
	std::vector<std::vector<float>> path;
	path = pathStrategy->GetPath(initial_position, final_position);
	
	//~ cout << "{ ";
	//~ for (int i = 0; i < path.size(); i++) {
		//~ cout << "{ ";
		//~ for (int j = 0; j < path[i].size(); j++){
		  //~ cout << path[i][j] << " ";
		//~ }
	//~ cout << "}\n";
	//~ }
	//~ cout << "}\n";
	
	std::vector<std::vector<float>> test_path = {	
		{ 187, 250, 1 },
		{ 187, 274, 26 },
		{ 187, 294, 51 },
		{ 187, 311, 76 },
		{ 187, 325, 101 },
		{ 187, 336, 126 },
		{ 187, 343, 151 },
		{ 187, 348, 176 },
		{ 187, 349, 201 },
		{ 187, 348, 226 },
		{ 187, 343, 251 },
		{ 187, 335, 276 },
		{ 187, 324, 301 },
		{ 187, 310, 326 },
		{ 187, 292, 351 },
		{ 187, 272, 376 },
		{ 187, 250, 400 }
	};
	//~ for (int i = 0; i < path.size(); i++) {
		//~ for (int j = 0; j < path[i].size(); j++){
		  //~ ASSERT_FLOAT_EQ(path[i][j], test_path[i][j]);
		//~ }
	//~ }
	//~ };
	
	//~ cout << "{ ";
	//~ for (int i = 0; i < path.size(); i++) {
		//~ cout << "{ ";
		//~ for (int j = 0; j < path[i].size(); j++){
		  //~ cout << path[i][j] << " ";
		//~ }
	//~ cout << "}\n";
	//~ }
	//~ cout << "}\n";
	
	// points lie along an inverted parabola of the form ax^2+bx+c,
	//with a = -1/k, b = 1, and c = 250. where k is the distance from 
	//the initial to the final point, which is 400.
	//Thus, we assert that the height (second point) is of
	//the form y = - x^2/k + x + 250, where x is the third point.
	for (int i = 0; i < path.size(); i++) {
		for (int j = 0; j < path[i].size(); j++){
		  ASSERT_NEAR(path[i][j], test_path[i][j], 1.0);
		}
	}
	
	float x;
	float k = 400;
	for(int i=0; i<path.size(); i++){
		x = path[i][2];
		//~ cout << x << " " << (-1.0/k)* pow(x, 2) + x + 250 << endl;
		ASSERT_NEAR(path[i][1], (-1.0/k)* pow(x, 2) + x + 250, 0.5);
	}
}

TEST_F(StrategyTest, SmartRoute){
	std::vector<float> initial_position{498.292, 253.883, -228.623};
	std::vector<float> final_position{-951.412, 254.665, 298.271};
	
	IPathStrategy* pathStrategy;
	pathStrategy = new SmartRoute();
	//~ cout <<"Here1" << endl;
	  OSMGraphParser parser;
	  //~ cout <<"Here2" << endl;
      const IGraph* graph = parser.CreateGraph("data/umn.osm", "data/umn-height.csv");
      //deliverySystem->SetGraph(graph);
      //~ cout <<"Here3" << endl;
      pathStrategy->SetGraph(graph);
	
	//~ cout <<"Here4" << endl;
	std::vector<std::vector<float>> path;
	//~ cout <<"Here5" << endl;
	path = pathStrategy->GetPath(initial_position, final_position);
	//~ cout <<"Here6" << endl;
	//~ cout << "{ ";
	//~ for (int i = 0; i < path.size(); i++) {
		//~ cout << "{ ";
		//~ for (int j = 0; j < path[i].size(); j++){
		  //~ cout << path[i][j] << " ";
		//~ }
	//~ cout << "}\n";
	//~ }
	//~ cout << "}\n";
	
	//make sure the initial and final position are in the path
	bool found = false;
	for (int i = 0; i < path.size(); i++) {
		if(path[i] == initial_position || path[i] == final_position){
			found = true;
		}
	}
	ASSERT_TRUE(found);
	
	//make sure a path has been made from the graph by checking if
	//the points are relatively close to one another
	for (int i = 0; i < path.size()-1; i++) {
		ASSERT_TRUE((fabs(path[i][0] - path[i+1][0]) < 1) ||
		(fabs(path[i][1] - path[i+1][1]) < 1));
		//~ cout << i << endl;
		//~ for (int j = 0; j < path[i].size(); j++){
		  //~ cout << path[i][j] << " ";
		//~ }
		//~ cout << endl;
		//~ cout << fabs(path[i][0] - path[i+1][0]) << endl;
		//~ cout << fabs(path[i][1] - path[i+1][1]) << endl;
	}
	
}

}  // namespace csci3081
