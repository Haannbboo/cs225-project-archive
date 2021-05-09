#include <math.h> 
#include "Astar.h"
#include <stdlib.h> 


Astar::Astar(Point* A, Point* B, std::string filename) {
    start_ = A;
    destination_ = B;
    Map m(filename);
    map_ = &m;
}

double Astar::calcG(Road* A) {
    double total = 0;
    for (Road* r : path_) {
        total+= r->length_;
    }
    return total + A->length_;
}

double Astar::calcH(Point* A) {
    return destination_->distance(A);
}; // this is equavilent to calculate distance between A and B;

double Astar::calcF(Road* road, Point* point) 
{
    return calcG(road) + calcH(point);
}

/***
NewPoint *Astar::findPath(NewPoint &startPoint,NewPoint &endPoint, bool isIgnoreCorner) 
{ 
     openList.push_back( new NewPoint(startPoint.x,startPoint.y));
     while (!openList.empty()) 
     { 
         auto curPoint=getLeastFpoint();
         openList.remove (curPoint);
         closeList.push_back(curPoint);
         auto surroundPoints=getSurroundPoints(curPoint,isIgnoreCorner); 
         for ( auto &target:surroundPoints) 
         { 
             if (!isInList(openList,target)) 
             { 
                 target->parent=curPoint; 
                 target->G=calcG(curPoint,target); 
                 target->H=calcH(target,&endPoint); 
                 target->F=calcF(target); 
                 openList.push_back(target); 
             } 
             else 
             { 
                 int tempG=calcG(curPoint,target); 
                 if (tempG<target->G) 
                 { 
                     target->parent=curPoint; 
                     target->G=tempG; 
                     target->F=calcF(target); 
                 } 
             } 
             NewPoint *resPoint=isInList(openList,&endPoint); 
             if (resPoint) 
                 return resPoint;
         } 
     } 
     return NULL; 
} 
***/
/***
void Astar::GetPath(NewPoint &startPoint,NewPoint &endPoint, bool isIgnoreCorner) 
{ 
     NewPoint *result=findPath(startPoint,endPoint,isIgnoreCorner); 
     while (result) 
     { 
         path_.push_front(result); 
         result=result->parent; 
     }
     return;
} 
***/


bool Astar::isInList(const Point* point) const {
    for (Point* iter_point : openList) {
        if (*point == *iter_point) return true;
    }
    return false;
}


Point* Astar::getLeastFpoint(std::vector<Road*> roads, Point* point) {
    if (roads.empty()) return point;
    double min = calcF(roads[0],roads[0]->otherSide(point));
    Point* min_point;
    for (Road* road : roads) {
        if (calcF(road,road->otherSide(point)) < min) {
            min = calcF(road,road->otherSide(point));
            min_point = road->otherSide(point);
        }
    }
    return min_point;
}

std::vector<Road*> Astar::getSurroundPoints(Point* point) {
    return map_->incidentRoads(point);

}

void Astar::print_path() {
    for (auto p : path_) {
        std::cout << "Road:  "<< p->id_ << "  |  " <<std::endl;
    }
}

/*** 
 * 
 * NewPoint *Astar::getLeastFpoint() 
{ 
     if (!openList.empty()) 
     { 
         auto resPoint=openList.front(); 
         for ( auto &point:openList) 
             if (point->F<resPoint->F) 
                 resPoint=point; 
         return resPoint; 
     } 
     return NULL; 
} 
void Astar::print_path() {
    for ( auto &p:path_) {
         std::cout<< '(' <<p->x<< ',' <<p->y<< ')' <<std::endl; 
    }
}
std::vector<NewPoint *> Astar::getSurroundPoints( const NewPoint *point, bool isIgnoreCorner) const 
{ 
     std::vector<NewPoint*> surroundPoints; 
     for ( unsigned long x=point->x-1;x<=point->x+1;x++) 
         for ( unsigned long y=point->y-1;y<=point->y+1;y++) 
             if (isCanreach(point, new NewPoint(x,y),isIgnoreCorner)) 
                 surroundPoints.push_back( new NewPoint(x,y)); 
     return surroundPoints; 
} 


bool Astar::isCanreach( const NewPoint *point, const NewPoint *target, bool isIgnoreCorner) const 
{ 
     if (target->x<0||(target->x>maze.size()-1)
         ||(target->y<0&&target->y>maze[0].size()-1)
         ||maze[target->x][target->y]==1 
         ||(target->x==point->x&&target->y==point->y) 
         ||isInList(closeList,target))
         return false ; 
     else 
     { 
         if ((point->x-target->x)+(point->y-target->y)==1)
             return true ; 
         else 
         { 
             if (maze[point->x][target->y]==0&&maze[target->x][point->y]==0) 
                 return true ; 
             else 
                 return isIgnoreCorner; 
         } 
     } 
} 

NewPoint *Astar::isInList( const std::list<NewPoint *> &list, const NewPoint *point) const 
{ 
     for ( auto p:list) 
         if (p->x==point->x&&p->y==point->y) 
             return p; 
     return NULL; 
} 


void Astar::InitAstar(std::vector<std::vector<int>> &_maze) { 
     maze=_maze; 
} 

int Astar::calcG(NewPoint *temp_start,NewPoint *point) 
{ 
     int extraG=((point->x-temp_start->x)+ (point->y-temp_start->y))==1?kCost1:kCost2; 
     int parentG=point->parent==NULL?0:point->parent->G;
     return parentG+extraG; 
} 

int Astar::calcH(NewPoint *point,NewPoint *end) 
{ 
     return sqrt (( double )(end->x-point->x)*( double )(end->x-point->x)+( double )(end->y-point->y)*( double )(end->y-point->y))*kCost1; 
} 

int Astar::calcF(NewPoint *point) 
{ 
     return point->G+point->H; 
} 
***/



