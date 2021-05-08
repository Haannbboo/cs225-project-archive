#pragma once
#include "data/Point.h"
#include "data/Road.h"
#include "data/Map.h"
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
#include "Astar.h"

const int kCost1=10;
const int kCost2=14;

class Dijkstra{
    public:
    //void InitAstar(std::vector<std::vector<int>> &_maze); 
    Dijkstra();
    Dijkstra(Point* start,Point* destination, Map* map);
    ~Dijkstra();
    //void MazeToAdjMatrix(std::vector<std::vector<int>> &_maze);
    //Point* findnearstpoint(Point* a); //find and return the nearst point to a point
    //double distance(Point* a, Point* b); //the distance between two points
    void print_path();
    void getPath();

    private:
    Point* start_;
    Point* destination_;
    std::vector<Point*> path_;
    Map* map_;
    int n; //total number of vertices
    std::vector<Point*> book; // store whether a vertices has alraedy been checked;
    std::vector<Point*> dis; // store the shortest path from start to other points;
    //std::vector<NewPoint *> getSurroundPoints( const NewPoint *point, bool isIgnoreCorner) const;
    //bool isCanreach( const NewPoint *point, const NewPoint *target, bool isIgnoreCorner) const 


};