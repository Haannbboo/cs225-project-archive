#include "Point.h"
#include <cmath>

Point:: Point(){
    this->x = 0;
    this->y = 0;
}

Point::Point(double x, double y){
    this->x = x;
    this->y = y;
}

bool Point::operator==(const Point &other) const{
    return (x == other.x && y == other.y);
}

double Point::distance(Point* other) {
    // Euclidean distance
    // return sqrt((x*1000000 - other->x*1000000) * (x*1000000 - other->x*1000000) + (y*1000000 - other->y*1000000) * (y*1000000 - other->y*1000000));

    // Great-Circle distance
    // double R = 6371000.0;  // radius of earth in meters
    // return R * acos(cos(y) * cos(other->y) * cos(other->x - x) + sin(y) * sin(other->y));

    // Haversine
    double R = 6371000.0;  // radius of earth in meters

    double x2 = other->x;
    double y2 = other->y;

    double dx = (x2 - x) * M_PI / 180.00;
    double dy = (y2 - y) * M_PI / 180.00;

    // convert to radians
    double y1 = y * M_PI / 180.00;
    double y3 = y2 * M_PI / 180.00;

    // apply Haversine formula
    double a = pow(sin(dy / 2), 2) + pow(sin(dx / 2), 2) * cos(y1) * cos(y3);
    return 2 * asin(sqrt(a)) * R;
}


void Point::setNewCords(double x, double y) {
    // used for unit testing
    this->x = x;
    this->y = y;
}