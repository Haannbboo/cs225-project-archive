#include "Point.h"
#include <math>

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

double Point::distance(Point other) {
    // Euclidean distance
    return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
}