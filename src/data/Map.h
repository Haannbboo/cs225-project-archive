#include "Road.h"
#include "../DataLoader/data"


class Map {
    private: 
        std::vector<Road*> roads;
        std::vector<Line> raw_data;
    public: 
        Map();
        ~Map();
        
        std::vector<std::vector<int>> convertToAdjacencyMatrix();
        std::vector<Point> convertToPoints();
    private:
        void cleanRawData();  // O(n)
};