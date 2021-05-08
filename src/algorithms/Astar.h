#include <iostream>
#include <vector>
//#include "../data/Point.h"
//#include "../data/Road.h"

#pragma once 

#include <vector> 

#include <list> 

   

const int kCost1=10;
const int kCost2=14;

struct NewPoint 
{ 
     unsigned long x,y;
     int F,G,H;
     NewPoint *parent;
     NewPoint( int _x, int _y):x(_x),y(_y),F(0),G(0),H(0),parent(NULL) {} 
}; 

class Astar { 

public : 
     void InitAstar(std::vector<std::vector<int>> &_maze); 
     std::list<NewPoint *> GetPath(NewPoint &startPoint,NewPoint &endPoint, bool isIgnoreCorner); 

private : 
     NewPoint *findPath(NewPoint &startPoint,NewPoint &endPoint, bool isIgnoreCorner); 
     std::vector<NewPoint *> getSurroundPoints( const NewPoint *point, bool isIgnoreCorner) const ; 
     bool isCanreach( const NewPoint *point, const NewPoint *target, bool isIgnoreCorner) const ;
     NewPoint *isInList( const std::list<NewPoint *> &list, const NewPoint *point) const ;
     NewPoint *getLeastFpoint();
     int calcG(NewPoint *temp_start,NewPoint *point); 
     int calcH(NewPoint *point,NewPoint *end); 
     int calcF(NewPoint *point); 

     std::vector<std::vector<int>> maze; 
     std::list<NewPoint*> openList; 
     std::list<NewPoint*> closeList;
};
    