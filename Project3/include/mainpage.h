/*! \mainpage CSCI 3081 Project - Drone Delivery Simulation
* 
* \section intro_sec Introduction
*   This is the code documentation for Iteration 1 and 2 of the Project, Drone Delivery System. 
*   This project make use of 5 patterns: It uses the Facade, Factory, Observer, Strategy, and Decorator patterns.
*   The goal of this project is to provide a concept of a working drone delivery simulation.
*   This will be running the code from the master branch on the umn.json scene file provided in <repo>/project/web/scenes/. 
*
*   \subsection quick_link Quick Links
*   - <a href="https://www.dofactory.com/net/facade-design-pattern">Facade Pattern</a>
*   \- Structure for Facade pattern<br> 
*   - <a href="https://www.dofactory.com/net/abstract-factory-design-pattern">Factory Pattern</a>
*   \- Structure for Factory pattern <br>
*   - <a href="https://www.dofactory.com/net/observer-design-pattern">Observer Pattern</a>
*   \- Structure for Observer pattern <br>
*   - <a href="https://www.dofactory.com/net/strategy-design-pattern">Strategy Pattern</a>
*   \- Structure for Strategy pattern <br>
*     <a href="https://www.dofactory.com/net/decorator-design-pattern">Decorator Pattern</a>
*   \- Structure for Decorator pattern <br>
*
* \section iter_1 Iteration 1
* Iteration 1 has Functionality/Implementation, Documentation, and Google Tests of the proof of concept simulation.
*
* Watch the simulation run, and the Drone to travel to the Package, pick it up and deliver it to the Customer,
* then remove the Package from the scene. Extra credit (multiple objects such as drones, customers, and packages)
* implemented.
*
* <p>
* The composite factory pattern is used in this project to keep track 
* of all the factories that are used. One of the advantages when it 
* comes to using this pattern is that it makes it classes open to 
* extensibility when adding new factories. All we have to do is add 
* a new factory class which uses the IEntityFactory interface, and we 
* never even have to touch the CompositeFactory class.
* </p>
*
* <p>
* The use of an abstract factory pattern allows us to use the composite 
* factory pattern, because it allows us to treat all factories that use 
* the IEntityFactory interface as the same object. This is better than 
* just using a regular factory pattern because it is even more extendable,
* and we don't have to change as much code when adding new classes.
* With a factory pattern we would have to use many if statments to switch 
* to using the correct factory and if we were to add another factory we 
* would have to open up our code and then write 
* another if statment to use that factory.
* </p>
*
*  \section iter_2 Iteration 2
* The different components of the Iteration 2 consist of Functionality/Implementation, Documentation, and the Google Tests for the proof of concept simulation.
* We can also see the simulation run, and the Drone/Robot deliver multiple packages to multiple customers. 
* Once the packages have been delivered in the simulation, we expect the package to be removed from the scene. 
* The drone alse has to be able to use different routes to get to a package or customer - namely, the smart route, beeline route, and parabolic route. 
* Notice that we also require that the package is dropped and drone/robot goes into an idle state when the battery dies. Unit testing is done simultaneously for development, and classes involved in the Strategy and Observer pattern are also tested.
*
*   \subsection imprvmts2 improvements include:
*   - Drone/robot moves smoothly (does not teleport large distances), and at the correct speed.
*   - Drone implements the beeline path.
*   - Drone implements the parabolic path.
*   - Drone/Robot goes to idle state when the battery dies.
*   - Package is dropped when the battery dies.
*   - Package is rescheduled and is picked up by another drone/robot.
*   - Multiple scenes work on the simulation.
*   - Battery does not drain when the robot/drone are idle.
*   - Observer Pattern is tested for accuracy, Beeline and Parabolic Paths are tested, 
*   - Strategy Pattern has been implemented for the different routes.
* 
* <p>
* The observer factory pattern is used in this project to be notified of any objects' status change.
* This a behavioral design pattern that allows some objects to notify other objects about changes in their state.
* The Observer pattern provides a way to attach and detach to and from these events for any object.
* Observers are responsible for knowing what they are to watch for and 
* the subject is free from knowing which observers depend on it.
* </p>
*
*  \section iter_3 Iteration 3
* The purpose of iteration 3 is to expand the package delivery system and develop useful optimizations or features. 
* Our team decided on the Entity Color Decorator for this iteration.
* Use decorator patterns to add color to an entity based on battery life.
* Entity colors will be changed as 75% green, 50% yellow, 25% orange, 0% red, and 0% black, respectively.
*
*   \subsection imprvmts3 improvements include:
*   - Entities' color changes by battery life percentage.
*   - Decorator Pattern has been implemented for the different colors use of entities.
*   - Deduplication with repeated code has been removed from all classes.
*   - All classes and methods documented properly.
*   - All functions in Delivery Simulation contain at most a few lines delegating work to other helper classes. 
*   
* 
* <p>
* The decorator pattern is used in this project to allow the addition of actions to individual objects dynamically 
* without affecting the behavior of other objects of the same class. 
* Decorator patterns are useful for adhering to a single accountability principle, 
* as they allow functions to be divided between classes with unique domains of interest. 
* Using decorator patterns can be more efficient than subclassification 
* because it can augment the behavior of objects without defining completely new objects.
* </p>
*
* \section strategy Basics of the Strategy Pattern
* <p>
* The Strategy factory pattern is used in this project for the different routes.
* This a behavioral design pattern that turns a set of behaviors into objects and 
* makes them interchangeable inside original context object. 
* The original object, called the context, holds a reference to a strategy object and 
* delegates it executing the behavior. 
* The goal is to create a path consisting of three dimensional points for the drone to follow 
* in a fluid path. The context class (Drone or Robot) need only keep track of an IStrategy* member attribute that it may call the AlgorithmInterface() (GetPath(), in our case) on. 
* Furthermore, due to the limitations of the Robot, it will never use the other path
* strategies apart from the smart path, and so only requires the use of a SmartRoute object.
* </p>
*
* \subsection routes Designing and Implementing the Different Routes
* <p>
* In our case, strategy pattern was used to implement the smart, parabolic, and 
* beeline routes. The strategy pattern allows the simulation to switch 
* between the different paths so that we can choose different paths for 
* different entities. To implement a strategy pattern, you need a 
* context class that holds a pointer to a strategy. This will serve as 
* an interface for concrete classes, which become different strategies 
* that the context class can use. 
* </p>
*
* <p>
* Therefore, we needed to add the IPathStrategy class, along with the 
* BeelineRoute, ParabolicRoute, and SmartRoute classes. Each Route 
* class is inherited from the strategy. The interface contained a pure 
* virtual method called GetPath that would return a vector of vectors. 
* This would serve as a vector of points for where an entity should 
* travel. Then the setter and getter methods for the graph were also 
* defined, but the setter was empty because not every class might use 
* this particular method. This is because only the smart route requires 
* the use of the graph, so the empty method ends up inherited by the 
* concrete classes instead, and we can call the method regardless of 
* which concrete class we use. Since we also cannot change whether the 
* class stores a reference, we also have a pointer to a graph stored in
* classes that inherit from the interface.
* </p>
*
* \subsection paths Operation of the Route classes
* <p>
* Now, inside the concrete classes, each Route implements the GetPath 
* method a bit differently. The SmartRoute is simple, it creates a 
* vector of points by calling the GetPath method for the graph, and 
* then adding those points to another similar vector which is returned. 
* However, the beeline path is a bit different.
* </p>
*
* <p>
* Due to the fact that we want the drone to fly higher than the 
* buildings, we consider new points 'A' and 'B' above the drone and the 
* customer. These points help define the path of the drone, and so we 
* add these points, the initial position and the final destination to 
* a single vector. In this way, a vector of points can be also be 
* returned for the beeline function.
* </p>
*
* <p>
* Last, comes the parabolic route. This route is similar to the beeline 
* because we start by computing a beeline route. However, if we keep 
* track of the initial position and destination, we can calculate the 
* equation of an upside-down parabola. This allows us to find the 
* y-coordinate of the drone's location as it traces a parabola to its 
* destination. The points are then added successively to a vector of 
* points once more.
* </p>
*
* <p>
* Now, to use the Strategy Pattern, the DeliverySimulation class becomes 
* the context class. The strategy, by default, uses the smart route, 
* but by using the GetDetails method in the ScheduleDelivery function, 
* we can  assign a particular strategy to the class, based upon what 
* the script for the simulations says we should schedule for.
*
* The most difficult parts were surely the design of the parabolic path 
* and the final implementation with the observer pattern. The strategy 
* itself is not too bad, especially with fewer drones and packages to 
* worry about, but it is complicated slightly when you have to worry 
* about the observer pattern as well, so you make sure that you get 
* the type of path and return it first before the observer's methods
* take in the path. The way we did the simulation also added points to
* the drone and robot entities directly, which is another thing that 
* you may need to account for.
*
* </p>
* \subsection tips Tips for Understanding
* <p>
Good tips might be to go over the structure of the code first to make 
* sure you understand what you're going to implement before you start 
* coding. In this particular assignment, it helped also to have 
* different scenes to choose from so it was possible to troubleshoot 
* the simulation with only one customer. Overall, the strategy pattern 
* material from March 29th also helped to understand the pattern the 
* most, as well as an example from refactoring guru 
* (https://refactoring.guru/design-patterns/strategy/cpp/example).
* </p>
*
* \section instruction Testing the simulation
* If you are interested in using the simulation, make sure you are in the /project directory. First build the environment
* by running ""./bin/build-env.sh". After building, compile the program, and run the command "./bin/run.sh" and 
* go to <a href="http://127.0.0.1:8081/"> this link </a>
* 
* \section uml UML Class Diagram
* This is the UML diagram of the entire system. It depicts the exact interactions and relationship between classes.
* <a href="https://lucid.app/lucidchart/8142df86-c8b0-4d5a-b94d-72acbf9f61d4/edit?page=0_0#">Lucid Template</a>
* \image html Iteration2UML.jpeg width=1500px 
*
* \section team_doc Team Documentation
* <p>
* Our 3 most significant meetings with team members are listed here.
* The group members: Conor, Carlos, Hyunwoo, and David.  
* Details are given about the content of our meetings, and what we 
* planned to get done once the meeting was over.
* </p>
*
* <p>
* Conor-fix the tests, Carlos-implement decorator pattern, 
* Hyunwoo-implement CSV file reader, and David-implement schduler.
*
* For our first meeting, we have tried to reduce the number of repeated codes, e
* specially every feature of the delivery simulation contains up to a few lines that 
* delegate the task to another helper class. 
* In other words, we ensure that there is a minimal conditional branch within Delivery Simulation
* and most other features.
* </p>
*
* <p>
* Conor-implement decorator pattern, Carlos-implement decorator pattern, 
* Hyunwoo-implement CSV file reader, and David-implement Schduler.
*
* In the second meeting, we talked about everything we wanted to achieve for the last iteration. 
* We reviewed the requirements for iteration and split the entire priority list. 
* Each priority was created as an issue, and each person was assigned a subset of these issues.
* At the second meeting, we decided on the Entity Color Decorator as a new feature.
* </p>
*
* <p>
* Conor-implement decorator pattern, Carlos-implement decorator pattern & UML, 
* Hyunwoo-documenation work, and David-documenation work & updates the tests.
*
* Our third meeting was relatively short, and we went over everything 
* that we were going to get done for the time after the in class quiz6.
* We talked a bit about the decorator pattern, and making sure that things were going smoothly.
* We also divided up some of the documentation for the mainpage so that people worked on what 
* was relevant to the classes that we each implemented.
* We also talked in more depth about codes, lists of given features, 
* the use of decorator patterns, and the choice of RGB colors.
* </p>
*
* <p>
* Throughout each meeting, we were communicative in general 
* about what we were working on, when we needed someone to review our 
* commits and when we were running into issues. This way, we all knew 
* reasonably well how things were going, give advice to each other, and 
* make sure we knew what needed to get done. 
*
* Conor : implement decorator pattern
* Carlos : implement decorator pattern & UML & Test
* Hyunwoo : Documentation & implement CSV reader(not completed) & UML
* David : Documentation & deleting redundancy & Test & UML
* </p>
*/
