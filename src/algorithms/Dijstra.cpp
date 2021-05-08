//#include "algorithm.h"
#include <vector>
#include <cmath>
#include <iostream>
#include <functional>
#include <utility>

/***
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


void Astar(Point* start_, Point* des_) {
    // Initialize two empty sets
    std::vector<Point*> open_set, close_set;
    // Add the startpoint to the openset and set the priority to 0;
    //std::pair<Point*, double>  start = std::make_pair(start_,0.0);
    open_set.push_back(start_);
    if (!open_set.empty()) {
        // if n is the destination
        Point* highest = highest_priority(open_set);
        if (IsEndPoint(highest)) {
            for (auto i : open_set) {
                path_.push_back(i);
            }
        } else {
            close_set.push_back(highest);
            //open_set.remove(highest); delete highests from open_set
            for (auto i : highest->adjacent()) {
                if (IsInClose_Set(i)) continue;
                else {
                    // set i as the parent node of highest;
                    // calculate the priority of i;
                    // add highest into the open set
                }
            }
        }
    }
};

void Dstar(Point* start_, Point* end_) {
    std::vector<Point*> open_set, close_set;
}








bool IsEndPoint(Point* check);
bool IsStartPoint(Point* check);
bool IsInClose_Set(Point* check);
bool IsInOpen_Set(Point* check);
Point* highest_priority(std::vector<Point*> check);
***/
