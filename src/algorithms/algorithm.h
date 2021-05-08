#pragma once
#include "data/Point.h"
#include "data/Road.h"
#include "data/Map.h"
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
class algorithm{
    public:
    void Dijkstra(Point* start, Point* destination);
    void Astart(Point* start, Point* destination);
    void Dstar(Point* start, Point* destination);
    Point* findnearstpoint(Point* a); //find and return the nearst point to a point
    double distance(Point* a, Point* b); //the distance between two points

    // function for Astar
    bool IsInOpen_Set(Point* check);
    bool IsInClose_Set(Point* check);
    bool IsStartPoint(Point* check);
    bool IsEndPoint(Point* check);
    Point* highest_priority(std::vector<Point*> open_set);

    private:
    Point* start_;
    Point* destination_;
    std::vector<Point*> path_;

};