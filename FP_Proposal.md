# CS 225 Final Project Proposal: Navigation problem


## Leading Question

The objective of this final project is to construct a navigation functionality using graphs algorithms. Given the connections and coordinates of roads and the destination, the algorithm tells me the path from the current location to the destination. We will try to solve the navigation problem given a city roads dataset, and we will discover the time complexity and viability of the algorithms in the real-world situations. We would define a “successful” project to solve the navigation problem and offer insight on the application of graph algorithms on real-world settings. Maybe our algorithms can't be applied to the real-world because of the time and spacial complexity, we still hope to explore them in a real-world map and appreciate the difficulty.

## Dataset Acquisition and Processing Your final project

We have chosen to use the Open Street Map (www.openstreetmap.org) for our data source for the real-world navigation problem. The Open Street Map (OSM) provides downloadable .shp (shape) file for a selected geographical area, which illustrates the coordinates of all rotates within the area. We selected Beijing, the city we live in, for extracting geographic data and downloaded the shape files manually through the OSM. 

The data downloaded from OSM is in .shp format, which has been converted to a regular .csv file using Python (this conversion is only used ONCE for this project, so a few lines of code in IDLE would accomplish this). We aim to convert this .csv file into a data structure that holds the connections, length, directions, and level of and among roads. From our investigation of the dataset, each row of the .csv file represents a ROAD with a “geometry” entry holding the various geographic coordinates along this road. These coordinates can be converted to directions and length of the road, and the connections among roads can be deducted from it as well. We tried to manually do this conversion and it looked fine, but in case of some roads that can’t be converted, we might omit the road or manually fix them (these tend to be some small roads and in real-world navigation they are not important). This ROAD data structure will be used to generate the input of the graph algorithms, like an adjacency matrix.

# Graph Algorithms

Apart from Dijkstra algorithm, we want to implement other algorithms includingD*, LPA*, and D* lite. There are two important data structures and conversion of data in our program. The first one is to translate the data in the .csv table into a data structure that holds the processed roads’ information. This data structure can generate the input data structure for the algorithms, such as adjacency matrix. The second is to use pre-processed data in the algorithms to generate the final result, which is the route from point A to point B and will be represented as a node-edge-node connection array. We want to implement the following algorithms: Dijkstra algorithm, A* algorithm, D* algorithm, and LPA* algorithm.

Dijkstra algorithm implements the greedy pattern. The complexity is O(|E|) where E is the number of edges.

The details for D* algorithm can be found in this article (http://robotics.caltech.edu/~jwb/courses/ME132/handouts/Dstar_ijcai95.pdf)

The navigation algorithm usually uses a combination of algorithms to optimize the result of the algorithm.


## Timeline As a team

We will handed in our final project proposal on april 16th, and then we will have a meeting discussing the details of the final project, such as what is the structure of the final project, what is the hierarchical structure of different class (basically design our Doxygen) and design class that implement which function. The input of each function and output should be clarified as well.

We will seperate the project to two parts: data cleaning and implementing graph algorithms. One teammate would be in charge of the overall management, cordinating the data flow within the project and standarlizing the code style. 

Upon mid-project report, we aim to construct the templates of our class designs and have implemented the Dijkstra algorithm. Data cleaning requires additional studies on csv manipulation in c++, so probably it can't be completed upon mid-project report but some progress will be demenstrated.

For the two weeks after mid-project report, we will complete the data cleaning and implement one graph algorithm per week. By the start of May, we would have a funtioning demo for every component of our project. From our past experience of projects, we will spend the last week intregrating code and compiling them to be easy-to-use. 


