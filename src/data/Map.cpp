#include "Map.h"
#include "Road.h"
#include <vector>


Map::Map() {

}

Map::~Map() {
    clean();
}

void Map::clean() {
    points.clear();
    roads.clear();

    pointsMap.clear();
    vertices.clear();
}

Map::Map(std::string filepath) {
    raw_data = LinesFromCsvFile(filepath);
    std::cout << "Finish reading raw data of size: " << raw_data.size() << std::endl;
    translateRawData();
}

Point* Map::findPoint(double x, double y) {
    std::pair<double, double> xy = std::make_pair(x, y);
    if (pointsMap.find(xy) != pointsMap.end()) {
        return pointsMap.at(xy);
    } else {
        return nullptr;
    }
}


void Map::translateRawData() {
    if (raw_data.empty()) {
        return;
    }

    for (auto line: raw_data) {
        Road* road = new Road();
        road->loadLine(line);

        // Deleting the road if length_ = 0
        if (road->length_ == 0) {
            delete road;
            continue;
        }

        // Since all Point(s) in Road are new(ed) when undergoing loadLine,
        // the same cordinate (x, y) might have been new(ed) several times in different Road
        // We need to make sure that each (x, y) pair correspond to ONE Point.
        // If (x, y) has been new(ed), we use the Point* that has been created
        // else we put the (x, y) : Point* into the pointsCreated map.
        for (size_t i = 0; i < road->cordinates_.size(); i++) {
            Point* p = road->cordinates_[i];
            std::pair<double, double> xy = std::make_pair(p->x, p->y);
            if (pointsMap.find(xy) != pointsMap.end()) {
                // when (x, y) is an old point
                delete road->cordinates_[i];
                road->cordinates_[i] = pointsMap.at(xy);
            } else {
                pointsMap[xy] = p;
                points.push_back(p);
            }
        }
        road->start_ = road->cordinates_[0];
        road->end_ = road->cordinates_.back();


        if (road->cordinates_.size() > 2) {
            for (int i = 0; i < (int) road->cordinates_.size() - 1; i++) {
                Point* newstart = road->cordinates_[i];
                Point* newend = road->cordinates_[i+1];
                std::pair<Point*, Point*> newpair = std::make_pair(newstart, newend);
                if (roadsMap.find(newpair) != roadsMap.end()) {
                    // road with (newstart, newend) already created
                    continue;
                } else {
                    Road* newroad = road->loadRoad(newstart, newend);
                    roadsMap[newpair] = newroad;
                    roads.push_back(newroad);
                    loadVertex(newroad);
                }
                
                // std::cout << "(" << newroad->start_->x << ", " << newroad->start_->y << "), "
                // << "(" << newroad->end_->x << ", " << newroad->end_->y << ")" << std::endl;
            }
            delete road;
            continue;
        } 

        roads.push_back(road);

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
    std::pair<double, double> xy = std::make_pair(x, y);
    if (pointsMap.find(xy) != pointsMap.end()) {
        return;
    }

    Point* point = new Point(x, y);
    std::vector<Road*> r;
    vertices[point] = r;

    points.push_back(point);
    pointsMap[xy] = point;
}

void Map::insertRoad(Point* p1, Point* p2, Road* road) {
    // check if p1 and p2 exist
    if (vertices.find(p1) == vertices.end() || vertices.find(p2) == vertices.end()) {
        return;
    }

    vertices.at(p1).push_back(road);
    vertices.at(p2).push_back(road);

    roads.push_back(road);
    
    if (road->start_ == nullptr && road->end_ == nullptr) {
        // road is the same as edges in a simple graph
        road->start_ = p1;
        road->end_ = p2;
        road->cordinates_.push_back(p1);
        road->cordinates_.push_back(p2);
    }

}

bool Map::areAdjacent(Point* p1, Point* p2) {
    // check if p1 and p2 exist
    if (vertices.find(p1) == vertices.end() || vertices.find(p2) == vertices.end()) {
        std::cout << "One of p1 or p2 is not in the Map" << std::endl;
        return false;
    }

    std::vector<Road*> r1 = vertices.at(p1);
    std::vector<Road*> r2 = vertices.at(p2);
    std::vector<Road*> r_small;
    std::vector<Road*> r_big;
    size_t minsize = std::min(r1.size(), r2.size());
    if (r1.size() == minsize) {
        r_small = r1;
        r_big = r2;
    } else {
        r_small = r2;
        r_big = r1;
    }
    for (size_t i = 0; i < r_small.size(); i++) {
        if (std::find(r_big.begin(), r_big.end(), r_small[i]) != r_big.end()) {
            return true;
        }
    }

    return false;
}

