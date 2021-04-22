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

    private:
    Point* start_;
    Point* destination_;

    Point* findnearstpoint(Point* a); //find and return the nearst point to a point
    double distance(Point* a, Point* b); //the distance between two points
};