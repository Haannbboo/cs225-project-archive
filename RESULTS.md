# RESULTS

## Dijkstra Algorithm


## Full instructions on how to build and run your executable, including how to define the input data and output location for each method.

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

 
