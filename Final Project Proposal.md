For the proposal please visit: https://docs.google.com/document/d/1Uu_T6ln-i2hvtNrUnN_g0HndjSSjul3xao7IEi8FbtQ/edit

CS 225 Final Project Proposal
Path Planning


Leading Question
We want to solve the path planning problem through graph algorithms. Path planning is an important tool for network routing, video games, gene sequencing, navigation etc. The basic idea is to find the shortest, or the most optimal, route from A to B.  In path planning, graph theory plays an important role as we need to convert a real world question into a mathematical model that can be processed by computer programs. Each place will be a node and each node is connected to by an edge. We will find a dataset that depicts that map of a certain place and we will implement different path planning algorithms. Besides, we will find out that which of these algorithms has the best performance among different cases. 

##Dataset Acquisition and Processing Your final project
We have chosen to use the Open Street Map (www.openstreetmap.org) for our data source for the real-world navigation problem. The Open Street Map (OSM) provides downloadable .shp (shape) file for a selected geographical area. We selected Beijing, the city we live in, for extracting geographic data and downloaded the shape files manually through the OSM. 
The data downloaded from OSM is in .shp format, which has been converted to a regular .csv file using Python (this conversion is only used ONCE for this project, so a few lines of code in IDLE would accomplish this). We aim to convert this .csv file into a data structure that holds the connections, length, directions, and level of and among roads. From our investigation of the dataset, each row of the .csv file represents a ROAD with a “geometry” entry holding the various geographic coordinates along this road. These coordinates can be converted to directions and length of the road, and the connections among roads can be deducted from it as well. We tried to manually do this conversion and it looked fine, but in case of some roads that can’t be converted, we might omit the road or manually fix them (these tend to be some small roads and in real-world navigation they are not important). This ROAD data structure will be used to generate the input of the graph algorithms, like an adjacency matrix.
Graph Algorithms
Apart from Dijkstra algorithm, we want to implement other algorithms including A*, D*, LPA*, and D* lite. 

Timeline As a team
We will handed in our final project proposal on april 9th, and then we will have a meeting discussing the details of the final project, such as what is the structure of the final project, what is the hierarchical structure of different class (basically design our Doxygen) and design class that implement which function. The input of each function and output should be clarified as well. 4
Then in the Mid-Project Checkin period, we will assign the work to each of the teammates to develop and have two meeting per week to make check with the development and if we have any problems. 
In the final part, we will submit our code and combine our code together and debug. 

 
