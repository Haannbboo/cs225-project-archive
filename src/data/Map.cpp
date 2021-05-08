#include "Map.h"
#include "Road.h"


Map::Map() {

}

Map::Map(std::string filepath) {
    raw_data = LinesFromCsvFile(filepath);
    std::cout << "Finish reading raw data of size: " << raw_data.size() << std::endl;
    translateRawData();
}


void Map::translateRawData() {
    if (raw_data.empty()) {
        return;
    }

    for (auto line: raw_data) {
        Road* road = new Road();
        road->loadLine(line);
        roads.push_back(road);

        // Since all Point(s) in Road are new(ed) when undergoing loadLine,
        // the same cordinate (x, y) might have been new(ed) several times in different Road
        // We need to make sure that each (x, y) pair correspond to ONE Point.
        // If (x, y) has been new(ed), we use the Point* that has been created
        // else we put the (x, y) : Point* into the pointsCreated map.
        for (size_t i = 0; i < road->cordinates_.size(); i++) {
            Point* p = road->cordinates_[i];
            std::pair<double, double> xy;
            xy.first = p->x;
            xy.second = p->y;
            if (pointsMap.find(xy) != pointsMap.end()) {
                // when (x, y) is an old point
                road->cordinates_[i] = pointsMap.at(xy);
            } else {
                pointsMap[xy] = p;
                points.push_back(p);
            }
        }
        road->start_ = road->cordinates_[0];
        road->end_ = road->cordinates_.back();

        // Put start_ and end_ of every Road into adj list
        // Intermediate Points have not been considered yet
        loadVertex(road);
    }
}

void Map::loadVertex(Road* road) {
    Point* start = road->start_;
    if (vertices.find(start) == vertices.end()) {
        vertices[start] = std::vector<Road*>{road};
    } else {
        vertices.at(start).push_back(road);
    }

    Point* end = road->end_;
    if (vertices.find(end) == vertices.end()) {
        vertices[end] = std::vector<Road*>{road};
    } else {
        vertices.at(end).push_back(road);
    }
}

std::vector<Road*> Map::incidentRoads(Point* point) {
    if (vertices.find(point) == vertices.end()) {
        // when point is not in Map
        std::vector<Road*> r;
        return r;
    } else {
        return vertices.at(point);
    }
}

void Map::insertPoint(double x, double y) {
    // check if (x, y) already exists
    std::pair<double, double> xy;
    xy.first = x;
    xy.second = y;
    if (pointsMap.find(xy) != pointsMap.end()) {
        return;
    }

    Point* point = new Point(x, y);
    std::vector<Road*> r;
    vertices[point] = r;

    points.push_back(point);
    pointsMap[xy] = point;
}