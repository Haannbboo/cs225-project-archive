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
        std::vector<Point*> cordinates_;
        Point* start_;
        Point* end_;
    public:
        Road();
        ~Road();

        //  Line to Road
        void loadLine(const Line& line);

        // for testing
        void geometry_to_cordiantes(std::string geometry);

    private:
        void clean();
        void delete_ptr(Point* const ptr);
        
};


