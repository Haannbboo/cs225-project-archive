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
    std::cout << "min" << std::endl;
    std::cout << min << std::endl;
    Point* returnpoint;
    for (auto point : openList) {
        if (point->F < min) {
            returnpoint = point;
        }
    }
    return returnpoint;
}

std::vector<Road*> Astar::getSurroundPoints(Point* point) {
    return map_->incidentRoads(point);
}

void Astar::print_path(Point* point) {
    while (point->parent!=nullptr) {
        std::cout << "Point:  "<< point->x << "  |  " << point->y << "\n" <<std::endl;
        std::pair<Point*, Point*> r = std::make_pair(map_->findPoint(point->x,point->y),map_->findPoint(point->parent->x,point->parent->y));
        std::cout << "Road:  " << map_->roadsMap.at(r)->id_ << "\n" << std::endl;
        point = point->parent;
    }
    std::cout << "Point:  "<< point->x << "  |  " << point->y << "\n" <<std::endl;
}

std::vector<Point*> Astar::points_in_path() {
    return points_in_path(findPath());
}

std::vector<Point*> Astar::points_in_path(Point* point) {
    std::vector<Point*> result;
    if (point==nullptr) return result;
    while(point->parent!=nullptr) {
        result.push_back(point);
        point = point->parent; 
    }
    result.push_back(point);
    return result;
}

void Astar::ToOpenList(Point* point) {
    openList.push_back(point);
}

void Astar::ToPath(Point* point) {
    path_.push_back(point);
}
