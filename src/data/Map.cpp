#include "Map.h"
#include "Road.h"


//  Load data from CSV using DataLoader
//  Clean and load data to vector<Road*>

Map::Map() {
    raw_data = LinesFromCsvFile("./DataLoader/shape.csv");
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
    }
}