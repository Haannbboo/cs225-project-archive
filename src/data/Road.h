#include "Point.h"
#include "../DataLoader/dataLoader.h"
#include <map>
#pragma once

class Road {
    public:
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
        std::pair<Point*, Point*> direction_;
        std::vector<Point*> cordinates_;
        Point* start_;
        Point* end_;
    public:
        Road();
        ~Road();

        //  Line to Road
        void loadLine(const Line& line);

    private:
        std::vector<Point*> split_geometry(std::string geometry);
};


