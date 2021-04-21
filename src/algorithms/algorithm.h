#pragma once
#include "data/Point.h"
#include "data/Road.h"
#include "data/Map.h"

class algorithm{
    public:
    void Dijkstra(Point* start, Point* destination);
    void Astart(Point* start, Point* destination);
    void Dstar(Point* start, Point* destination);

    private:
    Point* start_;
    Point* destination_;



}