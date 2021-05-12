

# mqiu3-daweix3-hanbog2-lurenw2 
# CS225 Navigation in the City of Beijing

## The location of all major code, data, and results.

Our project can be divided into the following part under the src folder:


1. DataLoader

This part has the functionality of translating csv file into std::string that can be furthered processed into data that can be used in our program. 

2. data

A map is composed of single points as each location and each road is defined by two points (including points in the middle of the road). Therefore, the data folder has the functionality of processing csv file into our defined class: Point, Road, and Map. Each of these class has different kinds of functionalities to be used in our algorithm designs. The data folder also has the MapDrawer function that used the class developed by CS225 faulties and we have used this function throughout our CS225 class. By using this class, we are able to draw the map of Beijing and to visualize our result. 
 
3. cs225

Visualization class developed by CS225 fauclties. 

4. algorithms

Our application has two different algorithms to compute the shortest path from point A to point B for users: Dijkstra and A* algorithm.

5. tests

This file include three different test cases for data, Dijkstra algorithm, and Astar algorithm. How to run those tests is demonstrated later.

6. main.cpp

## Full instructions on how to build and run your executable, including how to define the input data and output location for each method.

```js
    Point* start = new Point(116.2812022, 39.9708235);
    Point* destination = new Point(116.4015409, 40.0011546);
    std::string filename = "./src/shape.csv";
    Map* m = new Map(filename);
    Astar star(start,destination,m);
    star.print_path(star.findPath());

    MapDrawer drawer(m);
    drawer.drawMapWithSolution(points);
    drawer.save("navigation_result.png");
</script>
```



## Full instructions how to build and run your test suite, including a general description on what tests you have created. It is in your best interest to make the instructions (and the running of your executables and tests) as simple and straightforward as possible.

If you want just the A* search code (not the demo visualization), use code like this http://gist.github.com/581352
```js
	var startWithWeight = graphWithWeight.grid[0][0];
	var endWithWeight = graphWithWeight.grid[1][2];
	var resultWithWeight = astar.search(graphWithWeight, startWithWeight, endWithWeight);
	// resultWithWeight is an array containing the shortest path taking into account the weight of a node
</script>
```
A few notes about weight values:

1. A weight of 0 denotes a wall.
2. A weight cannot be negative.
3. A weight cannot be between 0 and 1 (exclusive).
4. A weight can contain decimal values (greater than 1).

### Original (slower) implementation

The original version of the algorithm used a list, and was a bit clearer but much slower.  It was based off the [original blog post](http://www.briangrinstead.com/blog/astar-search-algorithm-in-javascript).  The code is available at: https://github.com/bgrins/javascript-astar/tree/0.0.1/original-implementation.

The newest version of the algorithm using a Binary Heap.  It is quite faster than the original.
http://www.briangrinstead.com/blog/astar-search-algorithm-in-javascript-updated
Binary Heap taken from http://eloquentjavascript.net/appendix2.html (license: http://creativecommons.org/licenses/by/3.0/)


## Running the test suite

To run the test, you can

		make test
		./test


If you want to use the navigation application in Beijing, you need to first enter the location of the point in main.cpp, and then

		make
		./main

Then you are able see that a png picture has been drawn in the folder. 
