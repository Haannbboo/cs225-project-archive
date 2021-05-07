#include "Map.h"


//  Load data from CSV using DataLoader
//  Clean and load data to vector<Road*>

Map::Map() {
    raw_data = LinesFromCsvFile("shape.csv");
}

void Map::cleanRawData() {
    if (raw_data.empty()) {
        return;
    }

    for (auto line: raw_data) {
        Road* road = new Road();
        road.loadLine(line);
        roads.push_back(road);
    }
}