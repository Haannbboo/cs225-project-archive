#include <iostream>
#include <vector>
using namespace std;
struct Point {
    double x;
    double y;
    string name; //the name of the place
    double sestimate; //the best estimate of distance to this point
    vector<Point*> connectedpts; //a vector of points connected to this point
    Point();

    Point(double x, double y);

    bool operator==(const Point &other) const;

    double distance(Point other);
        
};