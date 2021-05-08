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
    void InitAstar(std::vector<std::vector<int>> &_maze); 
    void Dijkstra(Point* start, Point* destination);
    Point* findnearstpoint(Point* a); //find and return the nearst point to a point
    double distance(Point* a, Point* b); //the distance between two points
    void print_path();

    private:
    Point* start_;
    Point* destination_;
    std::vector<Point*> path_;

};