/*! \mainpage CSCI 3081W Project - Drone Delivery System
 * 
 * \section intro_sec Introduction
 *
 * This is the code documentation for Iteration 1 of the CSCI 3081W Project -
 * Drone Delivery System. This projects make use of 3 patterns:
 * Facade Pattern, Factory Pattern and Observer Pattern. The goal of this project is to
 * provide a concept of a working drone delivery system.
 * 
 * \subsection getting_started Getting Started
 * The project revolves around the the facade entity_project::DroneDeliverySystem. 
 * Any new developers that are interested in this project should start by understanding this class and its functions. 
 * Most functionality is implemented inside the csci3081::DroneSimulation class. All drones, customers, and packages extend
 * the entity_project::Entity class, which has basic information about position, direction, and size. This is used inside the visualization.
 * 
 * \subsection quick_link Quick Links
 * - <a href="https://www.dofactory.com/net/facade-design-pattern">Facade Pattern</a>
 * \- Structure for Facade pattern<br> 
 * - <a href="https://www.dofactory.com/net/abstract-factory-design-pattern">Factory Pattern</a>
 * \- Structure for Factory pattern <br>
 * - <a href="https://www.dofactory.com/net/observer-design-pattern">Observer Pattern</a>
 * \- Structure for Observer pattern <br>
 * 
 * \section iter_1 Iteration 1
 * Iteration 1 acted as the proof of concept for such a system. There are 3 main entities in the system: 
 * - Drones
 * - Packages
 * - Customers
 * - Each Factory and composite Factory
 * - Vector2D and 3D
 * 
 * <p>These entities are created using factory classes, and added into the simulation via DroneSimulation. The simulation
 * is displayed in realtime through a web browser. Packages are scheduled to a customer, and a drone would be assigned to deliver it. For iteration 1, the drone moved
 * along a predefined route. Once it reached the package, it would then pick up the package, and continue along
 * the route. Upon reaching the customer, the drone will drop the package, and the package will be deleted from
 * the system.</p>
 * 
 * <p> For iteration 1, our system was not robust enough to handle mutplie deliveries. It could only handle, 1 drone,
 * 1 customer, and 1 package. </p>
 * 
 * \section instruction Testing the simulation
 * If you are interested in using the simulation, make sure you are in the /project directory. First build the environment
 * by running ""./bin/build-env.sh". After building, compile the program, and run the command "./bin/run.sh" and 
 * go to <a href="http://127.0.0.1:8081/"> this link </a>
 * 
 */

