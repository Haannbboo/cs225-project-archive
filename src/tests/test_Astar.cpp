/* test for navigation algorithm */
#include "../cs225/catch/catch.hpp"
#include "../algorithms/Astar.h"

#include "../data/Map.h"

std::vector<std::vector<std::string>> map = {
        {"o","o","o","o","o","o","o","o"},
        {"o","o","o","o","X","o","o","o"},
        {"o","o","S","o","X","o","E","o"},
        {"o","o","o","o","X","o","o","o"},
        {"o","o","o","o","o","o","o","o"},
    };

    Astar problem(map);

    if (problem.solve()) {
        problem.print_map();
    }
}




bool almostEqual(double x, double target) {
    double TOLERANCE = 0.1;
    return abs(x - target) / target < TOLERANCE;
}


TEST_CASE("Test Astar Basics") {
    // cordinates and distacne info from Google Map
    Point* p1 = new Point(39.907637673875094, 116.39943696144262);
    Point* p2 = new Point(39.90059254163761, 116.39960862282466);

    double distance = p1->distance(p2);

    REQUIRE( almostEqual(distance, 850) );  // actual distance is 850m

    // two close points
    p1->setNewCords(39.91847555732769, 116.35651420148747);
    p2->setNewCords(39.91855345474758, 116.35723854503502);
    distance = p1->distance(p2);

    REQUIRE( almostEqual(distance, 63) );

}