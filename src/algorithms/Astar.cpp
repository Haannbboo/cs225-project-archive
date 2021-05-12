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
    if (A->parent==nullptr) return R->length_;
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
     openList.push_back(map_->findPoint(start_->x,start_->y));
     while (!openList.empty()) 
     { 
         Point* curPoint=getLeastFpoint();
         std::cout << "curPoint Position" << curPoint->x << "|" << curPoint->y << std::endl;
         std::cout << "Get The Least F Point" << std::endl;
         openList.remove(curPoint);
         std::cout << "Remove curPoint from openList" << std::endl;
         closeList.push_back(curPoint);
         std::cout << "Push curPoint to the closeList" << std::endl;
         std::vector<Road*> surroundPoints= getSurroundPoints(curPoint);
         if (surroundPoints.empty()) continue;
         for (Road* r :surroundPoints) 
         { 
             std::cout << "Road id: " << r->id_ << std::endl; 
             if (isInCloseList(r->otherSide(curPoint))) continue;
             else if (!isInList(r->otherSide(curPoint))) 
             { 
                 std::cout << "In Open List" << std::endl;
                 std::cout << "Next Point" << r->otherSide(curPoint)->x << "|" << r->otherSide(curPoint)->y << std::endl;
                 r->otherSide(curPoint)->parent=curPoint;
                 std::cout << "Child: " << r->otherSide(curPoint)->x << " | "<<r->otherSide(curPoint)->y << std::endl;
                 std::cout << "Parent: " << curPoint->x << " | " << curPoint->y << std::endl;
                 r->otherSide(curPoint)->F = calcF(r,r->otherSide(curPoint));
                 std::cout << "F: " << calcF(r,curPoint) << std::endl;
                 r->otherSide(curPoint)->G = calcG(r->otherSide(curPoint), r);
                 std::cout << "G: " << calcG(curPoint,r) << std::endl;
                 r->otherSide(curPoint)->H = calcH(r->otherSide(curPoint));
                 std::cout << "H: " << calcH(r->otherSide(curPoint)) << std::endl;
                 openList.push_back(r->otherSide(curPoint)); 
             } 
             else 
             { 
                 int tempG=calcG(curPoint,r); 
                 std::cout << "tempG" << tempG << std::endl;
                 if (tempG< (r->otherSide(curPoint)->G) ) 
                 { 
                     r->otherSide(curPoint)->parent=curPoint; 
                     r->otherSide(curPoint)->G=tempG; 
                     r->otherSide(curPoint)->F=calcF(r,curPoint); 
                 } 
             } 
             Point *resPoint= isInList();
             if (resPoint!=nullptr) return resPoint;
             map_->findPoint(start_->x,start_->y)->parent = nullptr;
         } 
     } 
     return nullptr; 
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

bool Astar::isInCloseList(const Point* point) const {
    for (Point* iter_point : closeList) {
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
    double x_F,y_F;
    Point* returnpoint;
    for (auto point : openList) {
        if (point->F <= min) {
            x_F = point->x;
            y_F = point->y;
        }
    }
    return map_->findPoint(x_F,y_F);
}

std::vector<Road*> Astar::getSurroundPoints(Point* point) {
    return map_->incidentRoads(point);
}

void Astar::print_path(Point* point) {
    if (point==nullptr) std::cout << "No Way To Get To Your Destination From the Start" << std::endl;
    while (point->parent!=nullptr) {
        std::cout << "Point:  "<< point->x << "  |  " << point->y << "\n" <<std::endl;
        std::pair<Point*, Point*> r1 = std::make_pair(map_->findPoint(point->x,point->y),map_->findPoint(point->parent->x,point->parent->y));
        std::pair<Point*, Point*> r2 = std::make_pair(map_->findPoint(point->parent->x,point->parent->y),map_->findPoint(point->x,point->y));
        //if (map_->roadsMap.find(r1) != map_->roadsMap.end()) {
        //}std::cout << "in there" << std::endl;
        //std::cout << "Road:  " << map_->roadsMap.at(r1)->id_ << "\n" << std::endl;
        point = point->parent;
    }
    std::cout << "Point:  "<< point->x << "  |  " << point->y << "\n" <<std::endl;
    std::cout << "---- FINISHED ----" << std::endl;
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

