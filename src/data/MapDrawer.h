#include "Map.h"
#include "../cs225/PNG.h"

#pragma once


class MapDrawer {
    private:
        Map* cityMap;

    private:
        Point* corner1;
        Point* corner2;

    private:
        struct Cord {
            Cord(double x, double y) {
                this->x = x;
                this->y = y;
            }
            double x;
            double y;
        };
    
    public:
        MapDrawer();
        MapDrawer(Map* cityMap);
        
        cs225::PNG* drawMap();
        cs225::PNG* drawMap(Point* p1, Point* p2);
        cs225::PNG* drawMapWithPath(Point* p1, Point* p2);

    private:
        Cord convertCord(Point* point);

};