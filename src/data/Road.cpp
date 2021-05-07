#include "Road.h"


void Road::loadLine(const Line& line) {
    // level_
    try {
        level_ = levelMapping.at(line.type);
    } catch (const std::out_of_range& oor) {
        level_ = 10;  // default value
    }
    
    // cordinates_
    std::string geometry = line.geometry;
    cordinates_ = split_geometry(geometry);

    // start_ and end_
    if (!cordinates_.empty()) {
        start_ = cordinates_[0];
        end_ = cordinates_.back();
    }

    // length_
    length_ = 0;
    if (cordinates_.empty() || cordinates_.size() == 1) {
        length_ = 100000;  // a random large number
    } else {  // size >= 2
        for (size_t i = 0; i < cordinates_.size() - 1; i++) {
            length_ += cordinates_[i]->distance(cordiantes[i+1]);
        }
    }

    // direction
    direction_ = std::make_pair(start_, end_);

    // oneway
    oneway_ = line.oneway;

    // bridge
    bridge_ = line.bridge;

}


std::vector<Point*> Road::split_geometry(std::string geometry) {
    size_t start = geometry.find("(") + 1;
    std::string geoInfo = geometry.substr(start, geometry.length() - start);

    std::vector<Point*> cordinates;

    while (geoInfo.lenth() > 0) {
        size_t y_start_index = geoInfo.find(" ") + 1;
        double x = std::stod(geoInfo.substr(0, y_start_index - 1));

        size_t comma_index = geoInfo.find(",");
        if (comma_index != std::string::npos) {
            comma_index = geoInfo.length();  // one PAST the last index
        }
        double y = std::stod(geoInfo.substr(y_start_index, comma_index - y_start_index));

        Point point = new Point(x, y);
        cordinates.push_back(point);

        geoInfo.erase(0, comma_index);
    }
    return cordinates;
}