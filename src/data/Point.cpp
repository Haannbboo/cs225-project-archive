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
    return sqrt((x*1000000 - other->x*1000000) * (x*1000000 - other->x*1000000) + (y*1000000 - other->y*1000000) * (y*1000000 - other->y*1000000));
}