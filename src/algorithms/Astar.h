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
    double calcG(Point* A, Road* R);
    double calcH(Point* A);
    double calcF(Road* road, Point* point);
    Point* getLeastFpoint();
    bool isInList(const Point* point) const;
    Point* isInList() const;
    Point* findPath();
    void getPath();

    // FUNCTIONS FOR TESTING
    void ToOpenList(Point* point);
    void ToCloseList(Point* point);
    

    private:
    std::list<Point*> openList; 
    std::list<Point*> closeList;
    std::list<Point*> path_;

    Map* map_;
    Point* start_;
    Point* destination_;
};   