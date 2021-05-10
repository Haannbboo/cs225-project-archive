#include "Point.h"
#include "../DataLoader/dataLoader.h"
#include <map>
#pragma once

class Road {
    public:
        int id_;
        int level_;
        int length_;
        bool oneway_;
        bool bridge_;
        std::map<std::string, int> levelMapping = {
            {"primary", 1},
            {"secondary", 2},
            {"tertiary", 3},
            {"trunk", 4},
        };
    public:
        // the three below have to be public for pointsCreated in Map
        std::vector<Point*> cordinates_;
        Point* start_;
        Point* end_;
    public:
        Road();
        ~Road();

        Point* otherSide(Point* oneside);
        
        //  Line to Road
        void loadLine(const Line& line);

        // Copy current road's property to a new Road with newstart and newend
        Road* loadRoad(Point* newstart, Point* newend);

        // for testing
        void geometry_to_cordiantes(std::string geometry);

    private:
        void clean();
        
};


