#include "Road.h"
#include "../DataLoader/dataLoader.h"


class Map {
    public: 
        std::vector<Road*> roads;
        std::vector<Line> raw_data;
    public: 
        Map();
        // ~Map();
        
        std::vector<std::vector<int>> convertToAdjacencyMatrix();
        std::vector<Point> convertToPoints();
    private:
        void translateRawData();  // O(n)
};