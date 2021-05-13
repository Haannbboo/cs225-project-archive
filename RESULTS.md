# RESULTS

## Dijkstra Algorithm

TODO
可以写一写如何设计这个算法
它的优缺点
跑在北京地图上的性能如何etc.

```js
NULL
```


## A* (Astar) algorithm

A star algorithm is by far the most popular algorithm in finding the shortest path from one point to another. The essence of it is BFS, but unlike BFS (Blind Search and it looks like wavefront)that will find the all the points surround the current point, A* algorithm has 'brain', which means that it will directly research towards the destination. It is achieved through calculating the cost of one point and the cost is composed of two parts. We call it heuristic search. In our algorithm design, there are three types of cost and they are calculated through the following function:



    double Astar::calcG(Point* A, Road* R) 
    {
    	if (A->parent==nullptr) return R->length_;
    	else return A->parent->G + R->length_;
    }
    double Astar::calcH(Point* A) 
    {
    	return destination_->distance(A)*1.33;
    }; // this is equavilent to calculate distance between A and B;

    double Astar::calcF(Road* road, Point* point) 
    {
    return calcG(point,road) + calcH(point);
    }

 
During the testing of our algorithm, we found out that weight is a really important factor in our algorithm design. Essentially, heurisitc search like A* is informed search. We found out that if we multiply the weight of H with a different factor, the result will totally different.

![image](factor5.png)
When the factor is 5
--------------------------------------------
![image](factor1.33.png)
When the factor is 1.33
--------------------------------------------
Obviously, factor of 1.33 gives us better result generally speaking. But what cause this difference?



This informs us that our algorithm can be optimized in multiple ways since it relies on retrieving the next point with the lowest F value. In real life traffic, multiple factors can be considered. Is it a highway or pedestrian? Is this road in downtown or in suburb area? Does this road charges any fee? If the user is planning to go to work using our navigation algorithm, can we find not only the shortest path, but also the least time consuming path by bypassing some of the traffic-congested area? We then realize that modern map&nagivation application have some factors that needed to be taken into consideration. 

## Error Analysis
After calculating the shortest path, we also compare our navigating result with which from Google map. We also found some problems with our dataset that doesn't give us full information about the road and point. 
