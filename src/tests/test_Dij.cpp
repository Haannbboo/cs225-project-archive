#include "../cs225/catch/catch.hpp"
#include "../algorithms/Dijkstra.h"
#include "../data/Road.h"
#include "../data/Map.h"
#include "../data/Point.h"
#include "../algorithms/Astar.h"


TEST_CASE("Find nearest point") {
    Point* p1 = new Point(0,0);
    Point* p2 = new Point(10,10);
    Dijkstra dij(p1, p2, "./tests/TEST_MAP.csv");
    REQUIRE(dij.road[0]->x == (double) 0);
    REQUIRE(dij.road[0]->y == (double) 0);
    delete p1;
    delete p2;
}



TEST_CASE("Test algorithm") {
    Point* p3 = new Point(116.3115702, 39.9746749);
    Point* p4 = new Point(116.3128514, 39.9720423);
    double dis = p3->distance(p4);
    Dijkstra dij(p3,p4,"./tests/s1.csv");
    double estimate = 340;
    REQUIRE(estimate > dis);
    delete p3;
    delete p4;
}
