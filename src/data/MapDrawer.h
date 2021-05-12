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
        struct Color {
            Color(): h(0), s(1), l(1), a(0) { }
            Color(double h, double s, double l, double a): h(h), s(s), l(l), a(a) { }
            double h, s, l, a;
        };
    
    public:
        MapDrawer(unsigned width, unsigned height);  // for debugging only
        MapDrawer(Map* cityMap);
        ~MapDrawer();

        void save(std::string fpath);
        
        void drawMap();
        void drawMap(Point* p1, Point* p2);
        void drawMapWithSolution(std::vector<Point*> points);

    public:
        Cord convertCord(Point* point);  // convert a geo cord to the (x, y) on PNG
        bool withinCanvas(Point* point);  // if point is within the (p1, p2) range
        void clear();

        void drawLine(Point* p1, Point* p2, Color color);  // draw a STRAIGHT line from p1 to p2
        void drawVerticalLine(Cord c1, Cord c2, Color color);
        void drawHorizontalLine(Cord c1, Cord c2, Color color);
        void drawZigZags(Cord c1, Cord c2, Color color);


        void drawLine(Cord c1, Cord c2, Color color);  // for debugging only

};