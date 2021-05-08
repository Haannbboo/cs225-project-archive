#include "Dijkstra.h"
#include "../data/Point.h"
#include "../data/Map.h"
#include "../data/Road.h"

#include <vector>
#include <cmath>
#include <iostream>
#include <functional>
#include <utility>


void algorithm::Dijkstra(Point* start, Point* destination){
    Point* cur;
    vector<string> road;
    while(cur != destination){
        cur = findnearstpoint(start);
        start = cur;
        road.push_back(cur->name);
    }
}

double algorithm::distance(Point* a, Point* b){
    return ((double) sqrt((a->x-b->x)*(a->x-b->x)+(a->y-b->y)*(a->y-b->y)));
}

Point* algorithm::findnearstpoint(Point* a){
    double min = DBL_MAX; //minimum dis counter
    Point* minp; //the point with minimum dis
    vector<Point*> connectedpts = a->connectedpts;
    for(Point* point:connectedpts){
        double dis = distance(point,a);
        if(a->sestimate + dis < point->sestimate)
            point->sestimate = a->sestimate + dis; //add the distance to the point's estimate
        if(point->sestimate < min){
            min = point->sestimate;
            minp = point;
        }
    }
    return minp;
}


***/
