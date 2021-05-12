# Week 1

- Constructed main structure and came up with appropriate algorithms for our project (Astar, Dijkstra)
- Gathered and validated data quality.
- Confirmed reliability of data source.
- Did research on related algorithm(Astar, Dijkstra) 
- Writing test cases and debuged codes we've already done (mainly about how to process csv dataset into std::string. Algorithms design is under study and research).

Useful link that I have found:
https://www.cs.cmu.edu/~motionplanning/lecture/Asearch_v8.pdf
https://www.cs.cmu.edu/~motionplanning/lecture/AppH-astar-dstar_howie.pdf


# Week 2
- Created Map, Point, Road class for our project. Map represents the map we run graph algorithms on together with some methods that is able to interact with point and map class. A point class contians the name of the place, the best estimate of distance to this point, a vector of points connected to this point etc. An road class mainly describe the road name, lengh, w/o brisge, if it's on way and some other properties of it.
- Cleaned the data we'd collected, mainly though deleting unnecesary and NA data points.
- Based on the data source we got from last week, we read the data csv file without using any non-standard library in C++. We created a class called line to store all records of data in the csv file. Line class contians a data point class which is basically just one record of data point and use vectior to store the data point class we created.
- Writing test cases and debuged codes we've already done.
- Check efficiency of our algorithms.

# Week 3
- Integrate DataLoader and Map/point/Road class together, so that we can use a better way to store our data.
- Introduce CS225 PNG and some exsisting classes into our code base.
- Get started and finished building Dstar algorithm.
- Get started and finished building Dijkstra algorithm.
- Trying to figuring out how to implement Astar algorithm.
- Writing test cases and debuged codes we've already done.
- Check efficiency of our algorithms.

# Week 4
- Get started and finished building Astar algorithm.
- Feed data to Astar, Dijkstra algorithms.
- Write codes to draw a simple result for our program.
- Writing test cases and debuged codes we've already done.
- Check efficiency of our algorithms.


# Week 5
- Constructed final debugging.
- Check and finsih the rest test cases, and think about edge cases of our programs.
- Write codes to be able to draw complete result for our program.
- Check efficiency of our algorithms.
- clean our repositories and make our codes comply the same style and formats.
- Preparing and  writing outlines for our final project video.
