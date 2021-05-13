#include "../cs225/catch/catch.hpp"
#include "../algorithms/Dijkstra.h"
#include "../data/Road.h"
#include "../data/Map.h"
#include "../data/Point.h"
#include "../algorithms/Astar.h"

TEST_CASE("TEST Constructor") {
    Point* p1 = new Point(0,0);
    Point* p2 = new Point(10,10);
    Dijkstra dij(p1, p2, "./tests/TEST_MAP.csv");
    REQUIRE(dij.map_->vertices.size() == 5);
    REQUIRE(dij.map_->points.size() == 5);
    REQUIRE(dij.map_->roads.size() == 8);
    delete p1;
    delete p2;
}


TEST_CASE("Find nearest point") {
    Point* p1 = new Point(0,0);
    Point* p2 = new Point(10,10);
    Dijkstra dij(p1, p2, "./tests/TEST_MAP.csv");
    REQUIRE(dij.findnearstpoint()->x == 7);
    REQUIRE(dij.findnearstpoint()->y == 3);
    delete p1;
    delete p2;
}



TEST_CASE("Test algorithm") {
    Point* p3 = new Point(116.3818619, 39.8988605);
    Point* p4 = new Point(116.3894407, 39.9062721);
    double dis = p3->distance(p4);
    Dijkstra dij(p3,p4,"./tests/s1.csv");
    double estimate = dij.road[dij.road.size()]->best_estimate;
    REQUIRE(! estimate < dis);
    delete p3;
    delete p4;
}
