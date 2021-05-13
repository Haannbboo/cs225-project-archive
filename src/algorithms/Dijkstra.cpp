#include "Dijkstra.h"
#include "../data/Point.h"
#include "../data/Map.h"
#include "../data/Road.h"

#include <vector>
#include <cmath>
#include <iostream>
#include <functional>
#include <utility>
 Dijkstra::Dijkstra(Point* a, Point* b,  Map* m){
    start_ = a;
    destination_ = b;
    map_ = m;
}
 Dijkstra::Dijkstra(Point* start, Point* destination, string filename){
    
    Map* m = new Map(filename);
    map_ = m;
    
    start = map_->findPoint(start->x, start->y);
    destination = map_->findPoint(destination ->x, destination ->y);
    start->best_estimate = 0;
    road.push_back(start);
    Point* cur = start; //initialize current point
    visited_points.push_back(cur);
    while(cur != destination){
        cur = findnearstpoint();
        cur->visited = true;
        // currentpoint->visited = true;
        visited_points.push_back(cur);
        road.push_back(cur);
        //cout<<"new point: "<<cur->x<<","<<cur->y<<endl;
    }
}

Point* Dijkstra::findnearstpoint(){
    double min = 99999999; //minimum dis counter
    Point* minp; //the point with minimum dis
    for(auto visit: visited_points){ //loop over visited points and get connected points
        getpoints(visit); //update unvisited neighbout points
        for(auto point:visit->connectedpts){ //loop over connected points
            if(point->visited == false){
                double dis = point->distance(visit); //calculate the distance
                if(visit->best_estimate+dis < point->best_estimate){ //if smaller than current estimate, update
                point->best_estimate = visit->best_estimate+dis;
                }
                if(point->best_estimate < min){ // find out the smallest point to take as nearest point
                //cout<<"best estimate: "<<point->best_estimate<<endl;
                    min = point->best_estimate;
                    minp = point;
                }
            }
            
        }
    }
    //cout<<minp<<endl;
    //cout<<"current points are:";
    //for(auto point : visited_points){
    //   cout<<point<<endl;
    //}
    //cout<<"finish findnearest point"<<endl;
    cout<<minp;
    return minp;
}

void Dijkstra::getpoints(Point * a) { //add all unvisited point to a's connected point group
    a->connectedpts.clear();
    vector<Road*> roads = map_->incidentRoads(a);
    for(auto road:roads){
        Point * otherside = road->otherSide(a);
        if(otherside->visited == false){
            a->connectedpts.push_back(otherside);
        }

        
    }
}
void Dijkstra::print_path(){
    cout<<"the estimate should be:"<<endl;
    for(size_t i = 0; i < road.size(); i++){
        cout<<"("<<road[i]->x<<","<<road[i]->y<<") "<<road[i]->best_estimate<<" "<<endl;
    }
}

