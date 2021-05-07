#include "Point.h"
#include "../DataLoader/data.h"
#include <map>

class Road {
    private:
        int level_;
        int length_;
        bool oneway_;
        bool bridge_;
        std::map<std::string, int> levelMapping = {
            {"primary", 1},
            {"secondary", 2},
            {"tertiary", 3},
            {"trunk", 4},
        }
        std::pair<Point*, Point*> direction_;
        std::vector<Point*> cordinates_;
        Point* start_;
        Point* end_;
    public:
        Road();
        ~Road();

    private:
        //  Line to Road
        void loadLine(const Line& line);
        std::vector<Point*> split_geometry(std::string geometry);
};


