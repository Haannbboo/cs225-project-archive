#pragma once
#include "../data/Map.h"
#include "../data/Point.h"
#include "../data/Road.h"
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

const int kCost1=10;
const int kCost2=14;

class Dijkstra{
    public:
    Dijkstra();
    Dijkstra(Point* start,Point* destination, string filename);
    Dijkstra(Point* a, Point* b,  Map* m);
    Point* findnearstpoint(); //find and return the nearst point to a point
    double distance(Point* a, Point* b); //the distance between two points
    void print_path();
    void getPath();
    void getpoints(Point *a);
    vector<Point*> findpath();
    Map* map_;
    vector<Point*> road;
    private:
    
    Point* start_;
    Point* destination_;
    std::vector<Point*> path_;
    vector<Point*> visited_points;

};