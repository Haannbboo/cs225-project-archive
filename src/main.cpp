#include "data/Map.h"
#include "data/Road.h"
#include "data/MapDrawer.h"
#include "algorithms/Dijkstra.h"
#include "algorithms/Astar.h"

#include <iostream>

using namespace std;



int main() {
    /*
    std::vector<Line> data = LinesFromCsvFile("./DataLoader/shape.csv");
    std::cout << data.size() << std::endl;
    
    Line line = data[1];

    std::string geometry = "LINESTRING (116.315387 39.9062149, 116.315548 39.9065059, 116.3156185 39.9066426, 116.31561 39.909336, 116.3156094 39.9095281, 116.3156087 39.9097712)";
    std::cout << geometry << std::endl;

    size_t start = geometry.find("(") + 1;
    std::cout << start << std::endl;
    std::cout << geometry.length() << std::endl;
    std::string geoInfo = geometry.substr(start, geometry.length() - start - 1);
    std::cout << geoInfo << std::endl;

    size_t comma_index = geoInfo.find(",");
    if (comma_index == std::string::npos) {
            comma_index = geoInfo.length();  // one PAST the last index
    }
    std::cout << comma_index << std::endl;
    geoInfo.erase(0, comma_index+2);
    std::cout << geoInfo << std::endl;
    */

    // Map m("./DataLoader/shape.csv");
    // std::cout << m.vertices.size() << std::endl;
    // std::cout << m.points.size() << std::endl;
    // std::cout << m.roads.size() << std::endl;
    //Road* road = m.roads[2];

/***
    std::cout
    << "id_ = " << road->id_ << "\n"
    << "level_ = " << road->level_ << "\n"
    << "length_ = " << road->length_ << "\n"
    << "oneway_ = " << road->oneway_ << std::endl;

    std::cout << "roads size = " << m.roads.size() << std::endl;
    std::cout << "points size = " << m.points.size() << std::endl;
    std::cout << "pointsMap size = " << m.pointsMap.size() << std::endl;
    std::cout << "vertices size = " << m.vertices.size() << std::endl;

    Point* p1 = new Point(116.2998166, 39.9810686);
    // Point* p2 = new Point(116.3115702, 39.9746749); rdfz point
    Point* p2 = new Point(116.3194905, 39.9661083);
    std::cout << p1->distance(p2) << std::endl;

***/
    //Map* m = new Map("./DataLoader/shape.csv");
    /*
    double min = 100000;
    for (auto road: m->roads) {
        if (road->length_ < min) {
            min = road->length_;
        }
    }
    std::cout << min << std::endl;
    */
/*

    MapDrawer drawer(m);
    drawer.drawMap(p1, p2);
    drawer.save("bbbb.png");
*/

    /*
    MapDrawer draw(10, 10);
    MapDrawer::Cord c1(3, 3);
    MapDrawer::Cord c2(3, 7);
    MapDrawer::Cord c3(7, 3);
    draw.drawLine(c1, c2);
    draw.drawLine(c1, c3);
    draw.drawLine(c2, c3);
    draw.save("aaaa.png");
    */


    /*
    std::vector<std::vector<int>> maze={ 
         {1,1,1,1,1,1,1,1,1,1,1,1}, 
         {1,0,0,1,1,0,1,0,0,0,0,1}, 
         {1,0,0,1,1,0,0,0,0,0,0,1}, 
         {1,0,0,0,0,0,1,0,0,1,1,1}, 
         {1,1,1,0,0,0,0,0,1,1,0,1}, 
         {1,1,0,1,0,0,0,0,0,0,0,1}, 
         {1,0,1,0,0,0,0,1,0,0,0,1}, 
         {1,1,1,1,1,1,1,1,1,1,1,1} 
     }; 
     Astar astar; 
     astar.InitAstar(maze); 
     NewPoint start(1,1); 
     NewPoint end(6,10); 
     astar.GetPath(start,end,false ); 
     astar.print_path();
    */
    //Point* p1 = new Point(39.907637673875094, 116.39943696144262);
    //Point* p2 = new Point(116.3894407, 39.9062721);
    /***
    Point* p3 = new Point(116.5352315, 39.922418);
    Point* p4 = new Point(116.3395358, 39.8471243);
    Point* p5 = new Point(116.3939401, 40.0082142);
    Point* p6 = new Point(116.3124355, 39.8548184);
    std::vector<Road*> roadslinktop1 = m.incidentRoads(p6);
    std::cout << roadslinktop1.size() << std::endl;
    //std::cout << p5->distance(p4) << std::endl;
    Astar A(p2, p3, "./DataLoader/shape.csv");
    A.print_path();
    std::cout << "finish" << std::endl;
    //std::cout << A.calcH(p4) << std::endl;
    for (std::map<Point*, std::vector<Road*>>::iterator i = m.vertices.begin(); i!=m.vertices.end();i++) {
        std::cout << m.incidentRoads(i->first).size() << std::endl;
    }
    //std::cout << m.incidentRoads(m.vertices.end()->first).size() << std::endl;
    ***/
    Point* pt1 = new Point(0,0);
    Point* pt2 = new Point(10,10);
    Dijkstra star(pt1, pt2, "./tests/TEST_MAP.csv");
   // std::vector<Road*> testt = star.getSurroundPoints(pt1);
    //std::cout << testt.size() << std::endl;
    // std::cout << star.map_->vertices.size() << std::endl;
    // std::cout << star.map_->points.size() << std::endl;
    // std::cout << star.map_->roads.size() << std::endl;
    // std::vector<Road*> test_road = star.getSurroundPoints(star.map_->findPoint(5,5));
    // for (auto r : test_road) {
    //     std::cout << r->id_ << std::endl;
    // }
    // std::cout << test_road.size() << std::endl;
    // std::cout << star.calcH(pt1) << std::endl;
    star.print_path();
    return 0;
}

