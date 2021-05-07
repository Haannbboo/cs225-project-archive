#include "Road.h"


void Road::loadLine(const Line& line) {
    try {
        level_ = levelMapping.at(line.type);
    } catch (const std::out_of_range& oor) {
        level_ = 10;  // default value
    }
    
    std::string geometry = line.geometry;
    
    "LINESTRING (116.3894407 39.9062721, 116.3894463 39.9060115)"

}


std::vector<Point*> Road::split_geometry(std::string geometry) {
    size_t start = geometry.find("(") + 1;
    std::string geoInfo = geometry.substr(start, geometry.length() - start);

    std::vector<Point*> cordinates;

    while (geoInfo.lenth() >= 0) {
        size_t y_start_index = geoInfo.find(" ") + 1;
        double x = std::stod(geoInfo.substr(0, y_start_index - 1));
        size_t comma_index = geoInfo.find(",");
        double y = std::stod(geoInfo.substr(y_start_index, comma_index - y_start_index));
        Point point = new Point(x, y);
        cordinates.push_back(point);
        geoInfo.erase()
    }
}