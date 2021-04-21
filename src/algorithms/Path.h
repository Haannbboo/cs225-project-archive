#include "Algorithm.h"
#include "data/Point.h"
#include "data/Road.h"
#include "data/Map.h"
#include <vector>


class Path {
    public:
    Path();
    ~Path();
    void Print_path();


    private:
    std::vector<Point*> pointlist_;
    std::vector<Road*> roadlist_;
    Point* Pointstart_;
    Point* Pointdestination_;


}