#include "Road.h"
#include "../DataLoader/dataLoader.h"


class Map {
    private: 
        std::vector<Line> raw_data;

        // std::unordered_map is better if we have a hash func for Point
        std::map<Point*, std::vector<Road*>> vertices;  // adjacency list

        // store all Points new(ed)
        std::map<std::pair<double, double>, Point*> pointsMap;

    public:
        std::vector<Point*> points;
        std::vector<Road*> roads;  // edge list

    public: 
        Map();
        Map(std::string filepath);
        // ~Map();
        
        std::vector<Road*> incidentRoads(Point* point);

        // methods below implement some of the traditional graph data structure
        // they are mainly used for testing
        void insertPoint(double x, double y);

        void insertRoad(Point* p1, Point* p2, Road* road);

        bool areAdjacent(Point* p1, Point* p2);

    private:
        void translateRawData();  // O(n)
        void loadVertex(Road* road);
};