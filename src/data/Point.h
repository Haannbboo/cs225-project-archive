#include <iostream>
#include <vector>
using namespace std;
struct Point {
    unsigned x;
    unsigned y;
    string name; //the name of the place
    double sestimate; //the best estimate of distance to this point
    vector<Point*> connectedpts; //a vector of points connected to this point
    Point();

    Point(unsigned x_, unsigned y_);

    bool operator==(const Point &other) const;
        
};