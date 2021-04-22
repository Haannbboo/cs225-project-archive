#include "Point.h"

Point:: Point(){
    this->x = 0;
    this->y = 0;
}

Point::Point(unsigned x_, unsigned y_){
    this->x = x_;
    this->y = y_;
}

bool Point::operator==(const Point &other) const{
    return (x == other.x && y == other.y);
}