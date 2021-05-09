
#include <string>
#include <vector>
#pragma once

struct Point {
    double x;
    double y;
    std::string name; //the name of the place
    double sestimate; //the best estimate of distance to this point
    std::vector<Point*> connectedpts; //a vector of points connected to this point
    Point();

    Point(double x, double y);

    bool operator==(const Point &other) const;

    double distance(Point* other);

    std::vector<Point*> adjacent(Point* other);
    void setNewCords(double x, double y);
    Point* parent;
    double F;
    double G;
    double H;
        
};