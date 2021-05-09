#include <iostream>
#include <vector>
#include "../data/Point.h"
#include "../data/Road.h"
#include "../data/Map.h"
#include <list>


#include <vector> 

#include <list> 

class Astar {
    public:
    Astar();
    Astar(Point* start, Point* des, std::string filename);
    void print_path();
    std::vector<Road*> getSurroundPoints(Point* point);
    double calcG(Road* A);
    double calcH(Point* A);
    double calcF(Road* road, Point* point);
    Point* getLeastFpoint(std::vector<Road*> roads, Point* Point);
    bool isInList(const Point* point) const;
    void findPath();

    private:
    std::list<Point*> openList; 
    std::list<Point*> closeList;
    std::list<Road*> path_;

    Map* map_;
    Point* start_;
    Point* destination_;

    //get surrounded points 
};   
/***
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
     void GetPath(NewPoint &startPoint,NewPoint &endPoint, bool isIgnoreCorner); 
     void print_path();

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
     std::list<NewPoint*> path_;
};
***/