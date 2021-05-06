# C++
## CSCI3081W Program Design and Development based Projects
## Instructor: Tim Wrenn, 2021 Spring.

# Building a Virtual Delivery System - Drone & Robot & Customer
This is a visual project using interactive 3D computer graphics. Building a virtual delivery system from the ground up using drones, automated trucks, and automated robots. All of the delivery mechanisms will run on a battery and will be subject to the laws of physics. I.e. Vector Math.  For the trucks and robots they must follow the roads/sidewalks around the University of Minnesota campus (please note we may expand the simulation to execute in other locales). We will be giving you the shortest path for drone/robot to deliver the products. Drones on the other hand, will be allowed to due what is called a "beeline" delivery. I.e. point to point. There will be restrictions in place on how the drone can fly with a package/battery, thus collision avoidance must be implemented. In addition, the simulation will incorporate recharging stations where based upon the battery life of a drone, truck, or robot, the entities will determine when and where to recharge their batteries. 

## Presentation Vedio
 *  Iteration2 http://drive.google.com/file/d/1MQj92O0elvTQgo62XTE3991UrHoMSt-g/view
 *  Iteration3 http://www.youtube.com/watch?v=_UcewhlqqvI

## Pre-requisites
  * [Git](https://git-scm.com/)

## Docker Pre-requisites
  * Windows 10 Home
    * Install [wsl2 and Ubuntu](https://www.youtube.com/watch?v=ilKQHAFeQR0&list=RDCMUCzLbHrU7U3cUDNQWWAqjceA&start_radio=1&t=7)
  * Install [Docker Desktop](https://hub.docker.com/?overlay=onboarding) from [Docker Hub](https://hub.docker.com/)
  * Linux
    * Use [docker group instead of sudo](https://www.digitalocean.com/community/tutorials/how-to-install-and-use-docker-on-ubuntu-18-04)

## Getting Started with Docker

1. Build docker image

    ```bash
    bin/build-env.sh
    ```

2. Run docker image

    ```bash
    #Usage bin/run-env.sh <port - optional(default 8081)>
    bin/run-env.sh
    ```
    
3. Build project web server (inside docker image) NOTE: You won't be able to `cd` here yet because the project directory does not exist. If you were able to launch the above commands you should now be inside the docker image. You can exit it with CTRL+D now.

    ```bash
    # Inside docker image
    cd /home/user/repo/project
    make
    ```
    
4. Run web server (inside docker image)

    ```bash
    # MUST be within project/ directory inside docker image
    cd /home/user/repo/project
    ./bin/run.sh
    ```
    
5. Open up Firefox and browse to http://127.0.0.1:8081/


## Getting Started using SSH on CSE Lab machines

1. Run the ssh environment
    ```bash
    # Run the ssh environment
    # Example: ./bin/ssh-env.sh <x500> <port> <computer num>
    ./bin/ssh-env.sh myx500 8081 05
    ```

2. Build and run the simulation

    ```bash
    cd /path/to/project
    make -j
    ./bin/run.sh
    ```
  
5. Open up Firefox and browse to http://127.0.0.1:8081/

## Getting Started with VOLE-3D or VOLE

1. Log on to [VOLE-3D or VOLE](https://vole.cse.umn.edu/) (VOLE is slower for graphics, but is great for tests, etc...)

2. Build project

    ```bash
    cd /path/to/cloned/repository
    cd project
    make
    ```
    
 2. Run project

    ```bash
    # MUST be within project/ directory
    ./bin/run.sh
    ```
    
 5. Open up Firefox and browse to http://127.0.0.1:8081/
