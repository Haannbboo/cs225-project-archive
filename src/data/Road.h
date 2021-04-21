#include "Point.h"


class Road {
    private:
        int level_;
        int length_;
        std::pair<Point*, Point*> direction_;
        std::vector<Point*> cordinates_;
    public:
        Road();
        Road(int level, int length, std::vector<Point*> cordinates);
        ~Road();
}