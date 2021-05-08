#include "Road.h"
#include "../DataLoader/dataLoader.h"


class Map {
    public: 
        std::vector<Road*> roads;
        std::vector<Line> raw_data;

        std::map<Point*, std::vector<Road*>> vertices;

        // store all Points new(ed)]
        std::map<std::pair<double, double>, Point*> pointsCreated;
    public: 
        Map();
        ~Map();
        
        std::vector<Road*> incidentRoads(Point* point);

    private:
        void translateRawData();  // O(n)
        void loadVertex(Road* road);
};