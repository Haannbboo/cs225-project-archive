#include "Point.h"

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