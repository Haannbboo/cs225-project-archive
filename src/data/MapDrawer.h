#include "Map.h"
#include "../cs225/PNG.h"

#pragma once


class MapDrawer {
    private:
        Map* cityMap;
        cs225::PNG* canvas;

    private:
        Point* corner1;  // upper-left corner
        Point* corner2;  // lower-right corner
        std::map<Road*, bool> roadsDrawn;

    public:  // for testing only
        struct Cord {
            Cord(double x, double y) {
                this->x = x;
                this->y = y;
            }
            double x;
            double y;
        };
    
    public:
        MapDrawer(unsigned width, unsigned height);  // for debugging only
        MapDrawer(Map* cityMap);
        ~MapDrawer();

        void save(std::string fpath);
        
        void drawMap();
        void drawMap(Point* p1, Point* p2);
        cs225::PNG* drawMapWithPath(Point* p1, Point* p2);

    public:
        Cord convertCord(Point* point);  // convert a geo cord to the (x, y) on PNG
        bool withinCanvas(Point* point);  // if point is within the (p1, p2) range
        void clear();

        void drawLine(Point* p1, Point* p2);  // draw a STRAIGHT line from p1 to p2
        void drawVerticalLine(Cord c1, Cord c2);
        void drawHorizontalLine(Cord c1, Cord c2);
        void drawZigZags(Cord c1, Cord c2);


        void drawLine(Cord c1, Cord c2);  // for debugging only

};