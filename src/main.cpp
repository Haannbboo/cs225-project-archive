#include "data/Map.h"
#include "data/MapDrawer.h"

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

    /*
    Map m("./DataLoader/shape.csv");

    Road* road = m.roads[1];

    std::cout
    << "level_ = " << road->level_ << "\n"
    << "length_ = " << road->length_ << "\n"
    << "oneway_ = " << road->oneway_ << std::endl;

    std::cout << "roads size = " << m.roads.size() << std::endl;
    std::cout << "points size = " << m.points.size() << std::endl;
    std::cout << "pointsMap size = " << m.pointsMap.size() << std::endl;
    std::cout << "vertices size = " << m.vertices.size() << std::endl;
    */

    Point* p1 = new Point(115.0001, 41);
    Point* p2 = new Point(115, 41);
    std::cout << p1->distance(p2) << std::endl;


    Map* m = new Map("./DataLoader/shape.csv");
    /*
    double min = 100000;
    for (auto road: m->roads) {
        if (road->length_ < min) {
            min = road->length_;
        }
    }
    std::cout << min << std::endl;
    */

    // MapDrawer draw;  // for testing functionalities


    MapDrawer draw(10, 10);
    MapDrawer::Cord c1(3, 3);
    MapDrawer::Cord c2(3, 7);
    MapDrawer::Cord c3(7, 3);
    draw.drawLine(c1, c2);
    draw.drawLine(c1, c3);
    draw.drawLine(c2, c3);
    draw.save("aaaa.png");


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

    return 0;
}

