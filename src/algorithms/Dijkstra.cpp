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
    start = map_->findPoint(start->x, start->y);
    destination = map_->findPoint(destination ->x, destination ->y);
    Point* cur = start; //initialize current point
    visited_points.push_back(cur);
    while(cur != destination){
        cur = findnearstpoint();
        // currentpoint->visited = true;
        visited_points.push_back(cur);
        cout<<"new point: "<<cur->x<<","<<cur->y<<endl;
    }
}

Point* Dijkstra::findnearstpoint(){
    double min = 99999999; //minimum dis counter
    Point* minp; //the point with minimum dis
    for(auto visit: visited_points){ //loop over visited points and get connected points
        getpoints(visit);
        for(auto point:visit->connectedpts){ //loop over connected points
            double dis = point->distance(visit);
            if(point->best_estimate == 999999){ //if not updated before, update
                point->best_estimate = dis;
            } else if(visit->best_estimate+dis < point->best_estimate){ //if smaller than current estimate, update
                point->best_estimate = visit->best_estimate+dis;
            }
            if(point->best_estimate < min){ // find out the smallest point to take as nearest point
                cout<<"best estimate: "<<point->best_estimate<<endl;
                min = point->best_estimate;
                minp = point;
            }
        }
    }
    cout<<minp<<endl;
    cout<<"current points are:";
    for(auto point : visited_points){
        cout<<point<<endl;
    }
    cout<<"finish findnearest point"<<endl;
    return minp;
}

void Dijkstra::getpoints(Point * a) { //add all unvisited point to a's connected point group
    vector<Road*> roads = map_->incidentRoads(a);
    for(auto road:roads){
        Point * otherside = road->otherSide(a);
        bool flag = true;
        for(auto point:visited_points){ //check if the point is visited before
            if(point == otherside)
                flag = false;
                for(size_t i = 0; i < a->connectedpts.size(); i++){
                    if(a->connectedpts[i] == otherside)
                        a->connectedpts.erase(a->connectedpts.begin() + i - 1); //if this point is visited before, 
                                                                                //erase this point from the connected points
                }
        }
        if(flag == true) //if the point is not visited before, then add
            for(auto point:a->connectedpts){
                if(otherside == point)
                    flag = false;
            }
        if(flag == true)
            a->connectedpts.push_back(otherside);
        
    }
}
void Dijkstra::print_path(){
    cout<<"the path should be:";
    for(size_t i = 0; i < road.size(); i++){
        cout<<road[i]<<endl;
    }
}

