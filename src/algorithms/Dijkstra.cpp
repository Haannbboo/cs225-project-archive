#include "Dijkstra.h"
#include "../data/Point.h"
#include "../data/Map.h"
#include "../data/Road.h"

#include <vector>
#include <cmath>
#include <iostream>
#include <functional>
#include <utility>

 Dijkstra::Dijkstra(Point* start, Point* destination, string filename){
    start->best_estimate = 0;
    Map* m = new Map(filename);
    map_ = m;
    Point* cur = start; //initialize current point
    visited_points.push_back(start);
    while(cur != destination){
        Point* currentpoint = findnearstpoint();
        currentpoint->visited = true;
        cur = currentpoint;
        visited_points.push_back(cur);
        cout<<"reach21"<<endl;
        road.push_back("point:"+ to_string(cur->x)+" "+to_string(cur->y));
    }
}

double Dijkstra::distance(Point* a, Point* b){
    return ((double) sqrt((a->x-b->x)*(a->x-b->x)+(a->y-b->y)*(a->y-b->y)));
}

Point* Dijkstra::findnearstpoint(){
    double min = 99999; //minimum dis counter
    Point* minp; //the point with minimum dis
    for(auto visit: visited_points){ //loop over visited points and get connected points
        getpoints(visit);
        for(auto point:visit->connectedpts){ //loop over connected points
            double dis = distance(point,visit);
            if(visit->best_estimate + dis < point->best_estimate)
                point->best_estimate = visit->best_estimate + dis; //add the distance to the point's estimate
            if(point->best_estimate < min){
                min = point->best_estimate;
                minp = point;
            }
        }
    }
    
    return minp;
}

void Dijkstra::getpoints(Point * a) { //add all unvisited point to a's connected point group
    vector<Road*> roads = map_->incidentRoads(a);
    for(auto road:roads){
        Point * end = road->otherSide(a);
        if(end->visited == false){
            a->connectedpts.push_back(end);
        }
    }

}
void Dijkstra::print_path(){
    cout<<"the path should be:";
    for(size_t i = 0; i < road.size(); i++){
        cout<<road[i]<<endl;
    }
}

