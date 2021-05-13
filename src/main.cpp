#include "data/Map.h"
#include "data/Road.h"
#include "data/MapDrawer.h"
#include "algorithms/Dijkstra.h"
#include "algorithms/Astar.h"

#include <iostream>

using namespace std;



int main() {

    Map* m1 = new Map("./tests/s1.csv");
    //Map* m2 = new Map("./tests/s2.csv");
    //Map* m3 = new Map("./tests/TEST_MAP.csv");
    //Map* m4 = new Map("./DataLoader/shape.csv");
 
    Point* p3 = new Point(116.3115702, 39.9746749);
    Point* p4 = new Point(116.3117259, 39.9745902);
    //Point* p1 = new Point(0,0);
    //Point* p2 = new Point(10,10);
    Astar star(p3, p4, m1);
    star.print_path(star.findPath());
    Point* result = star.findPath();
    std::vector<Point*> points = star.points_in_path(result);
    MapDrawer drawer(m1);
    drawer.drawMapWithSolution(points);
    drawer.save("dddd.png");

    //std::vector<Road*> roads = m->incidentRoads(m->findPoint(116.2970399, 39.9589332));
    //std::cout << roads.size() << std::endl;
    return 0;
}

