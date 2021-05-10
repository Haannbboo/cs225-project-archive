#include <math.h> 
#include "Astar.h"
#include <stdlib.h> 


Astar::Astar(Point* A, Point* B, std::string filename) {
    start_ = A;
    destination_ = B;
    Map* m = new Map(filename);
    map_ = m;
}

double Astar::calcG(Point* A, Road* R) {
    if (A->parent==nullptr) return 0.0;
    else return A->G + R->length_;
}

double Astar::calcH(Point* A) {
    return destination_->distance(A);
}; // this is equavilent to calculate distance between A and B;

double Astar::calcF(Road* road, Point* point) 
{
    return calcG(point,road) + calcH(point);
}


Point* Astar::findPath() 
{ 
     openList.push_back(start_);
     while (!openList.empty()) 
     { 
         Point* curPoint=getLeastFpoint();
         openList.remove(curPoint);
         closeList.push_back(curPoint);
         std::vector<Road*> surroundPoints= getSurroundPoints(curPoint);
         for (Road* r :surroundPoints) 
         { 
             if (!isInList(r->otherSide(curPoint))) 
             { 
                 r->otherSide(curPoint)->parent=curPoint; 
                 r->otherSide(curPoint)->F = calcF(r,curPoint);
                 r->otherSide(curPoint)->G = calcG(curPoint, r);
                 r->otherSide(curPoint)->H = calcH(r->otherSide(curPoint));
                 openList.push_back(r->otherSide(curPoint)); 
             } 
             else 
             { 
                 int tempG=calcG(curPoint,r); 
                 if (tempG< (r->otherSide(curPoint)->G) ) 
                 { 
                     r->otherSide(curPoint)->parent=curPoint; 
                     r->otherSide(curPoint)->G=tempG; 
                     r->otherSide(curPoint)->F=calcF(r,curPoint); 
                 } 
             } 
             Point *resPoint=isInList(); 
             if (resPoint!=nullptr) return resPoint;
         } 
     } 
     return NULL; 
} 


void Astar::getPath() {
    Point* result = findPath();
    while(result->parent!=nullptr) {
        path_.push_front(result);
        result = result->parent;
    }
}


bool Astar::isInList(const Point* point) const {
    for (Point* iter_point : openList) {
        if (*point == *iter_point) return true;
    }
    return false;
}

Point* Astar::isInList() const {
    for (Point* iter_point : openList) {
        if (*destination_ == *iter_point) return iter_point;
    }
    return nullptr;
}

Point* Astar::getLeastFpoint() {
    double min = openList.front()->F;
    Point* returnpoint;
    for (std::list<Point*>::iterator i = openList.begin(); i!=openList.end(); i++) {
        if ((*i)->F < min) {
            returnpoint = *i;
        }
    }
    return returnpoint;
}

std::vector<Road*> Astar::getSurroundPoints(Point* point) {
    return map_->incidentRoads(point);

}

void Astar::print_path() {
    for (Point* point : path_) {
        std::cout << "Road:  "<< point->x << "  |  " << point->y << "\n" <<std::endl;
    }
}

void Astar::ToOpenList(Point* point) {
    openList.push_back(point);
}