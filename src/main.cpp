#include "data/Map.h"
#include <iostream>


int main() {
    /*
    std::vector<Line> data = LinesFromCsvFile("./DataLoader/shape.csv");
    std::cout << data.size() << std::endl;
    
    Line line = data[1];

    std::string geometry = "LINESTRING ()";
    std::cout << geometry << std::endl;
    size_t start = geometry.find("(") + 1;
    std::cout << start << std::endl;
    std::cout << geometry.length() << std::endl;
    std::string geoInfo = geometry.substr(start, geometry.length() - start - 2);
    std::cout << geoInfo << std::endl;

    size_t comma_index = geoInfo.find(",");
    if (comma_index == std::string::npos) {
            comma_index = geoInfo.length();  // one PAST the last index
    }
    std::cout << comma_index << std::endl;
    geoInfo.erase(0, comma_index+2);
    std::cout << geoInfo << std::endl;
    */

    Map m;

    Road* road = m.roads[0];

    std::cout
    << "level_ = " << road->level_ << "\n"
    << "length_ = " << road->length_ << "\n"
    << "oneway_ = " << road->oneway_ << std::endl;


    return 0;
}

