/*! \mainpage CSCI 3081 Delivery Simulation project w/ Extra Credit
*
* 
* To run the simulation, first build the project with `make` in the `project` directory.
* Next, navigate to `project/bin` and run `./run.sh'.
* Then go to `http://127.0.0.1:8081` in your web browser to view the simulation. 
* 
* The composite factory pattern is used in this project to keep track of all the factories that are
* used. A pro when it comes to using this pattern is that it makes it easily expandable when adding new
* factories. All we have to do is add a new factory class which uses the IEntityFactory interface, and we 
* never even have to touch the CompositeFactory class.
*
* The use of a abstract factory pattern allows us to use the composite factory pattern, because it allows us to
* treat all factroies that use the IEntityFactory interface as the same object. This is better than just using a regular
* factory pattern because its more expandable. With a factory pattern we would have to use many if statments to use the correct 
* factory and if we were to add another factory we would have to open up our code and then write another if statment to use that factory.
*/