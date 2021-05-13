

# mqiu3-daweix3-hanbog2-lurenw2 
# CS225 Navigation in the City of Beijing🇨🇳🇺🇸

## The location of all major code, data, and results.

Our project can be divided into the following part under the src folder:


1. DataLoader

This part has the functionality of translating csv file into std::string that can be furthered processed into data that can be used in our program. 

2. data

The data folder has the functionality of processing csv file into our defined class: ```Point```, ```Road```, and ```Map```. A ```Map``` stores ```Point```s (geo coordinates) of all ```Road``` within Beijing and each ```Road``` is defined by two ```Point```s. Most APIs used in algorithms are provided in ```Map```, supported by private methods in ```Road``` and ```Point```. The data folder also has the ```MapDrawer``` class that uses the ```PNG``` and ```HSLAPixel``` developed by CS225 faulties to draw the map of Beijing and to visualize output of graph algorithms. 
 
3. cs225

Visualization class and catch files developed by CS225 fauclties. 

4. algorithms

Our application has two different algorithms to compute the shortest path from point A to point B for users: Dijkstra and A* algorithm.

5. tests

This file include three different test cases for data, Dijkstra algorithm, and Astar algorithm. How to run those tests is demonstrated later.

6. main.cpp

## Full instructions on how to build and run your executable, including how to define the input data and output location for each method.

```js
    Point* start = new Point(116.2812022, 39.9708235); //create the start point using Geographic coordinate. 
    Point* destination = new Point(116.4015409, 40.0011546); // create the destination point using Geographic coordinate. 
    // One thing to notice is that the point has to be the point in the csv file. Otherwise the navigation application may not be able to locate where to start or where to end
    std::string filename = "./src/shape.csv";
    Map* m = new Map(filename);  // set a Map pointer
    Astar star(start,destination,m); //constructor
    star.print_path(star.findPath());  // first find the path, and then print the path 

    MapDrawer drawer(m); // set up a MapDrawer
    std::vector<Point*> points = star.points_in_path();
    drawer.drawMapWithSolution(points); // draw all the points in the path 
    drawer.save("navigation_result.png"); // save the png picture on your computer
```
If you want to find the shortest path from Point* start to Point* end, you need to first define you point in main.cpp. Then, do the following instructions.

	make
	./main

Then you are able see that a png picture has been drawn in the folder. 

## Full instructions how to build and run your test suite, including a general description on what tests you have created. It is in your best interest to make the instructions (and the running of your executables and tests) as simple and straightforward as possible.



We use the catch module from CS225 to create our own test suite. Our team have created three tests for the application, which are 

1. test_data.cpp
2. test_dijkstra.cpp
3. test_Astar.cpp

and three small test data set which are

1. TEST_MAP.csv
2. s1.csv
3. s2.csv

TEST_MAP.csv is a small graph including only 5 vertices and eight edges. If our algorithms pass on this test, we can then use bigger dataset. s1.csv and s1.csv are part of Beijing, simply to try if the algorithm can run on this a small part of Beijing.  

To run the test, you can

	make test
	./test
to see if our algorithms are able to pass those test suite. 
 
