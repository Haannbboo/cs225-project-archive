#include "Road.h"


class Map {
    private: 
        std::string fpath;
        std::vector<Road*> roads;
    public: 
        Map();
        Map(std::string path);
        ~Map();
        
        std::vector<std::vector<int>> convertToAdjacencyMatrix();
        std::vector<Point> convertToPoints();

        void readeFile();
}