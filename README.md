# FESA : GSBackend Software Project
> **DISCLAIMER:** This project was developed by the FESA Electronics & Software subteam for the TEKNOFEST Fighter UAV competition. Although the team successfully reached the final stage, 
the project could not be completed due to unexpected delays in material procurement and an underestimation of the workload by team members. However, for future reference and further 
development, we have decided to make our incomplete work available to the open-source community. Half of the software has been implemented, and the system design is nearly complete.

This software was built on TSML (Thread Safe Messaging Library), a generic library that I developed. This library provides a modular way to communicate between independent threads and 
manage the lifecycle of that thread (starting, looping, exception handling nad finishing). Additionally, to simplify the development process and ensure the software's modularity, I implemented a modular CMake system. With this system, each module can be built separately 
and tested independently. During the development process, I focused on creating clear and maintainable code. To achieve this, we adhered to SOLID principles and incorporated design patterns where appropriate, 
avoiding unnecessary overengineering. This approach not only streamlined development but also significantly enhanced our skills and understanding throughout the project.

GSBackend is one of the four main repositories of the FESA project. This software is designed to serve as a router between the user interface and other subsystems, such as the 
FlightStation software running on the UAV and the competency server within an intranet, using the HTTP protocol. Additionally, this software is responsible for calculating 
optimal route parameters using specialized pathfinding algorithms.

