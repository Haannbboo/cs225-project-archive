/* test for navigation algorithm */
#include "../cs225/catch/catch.hpp"
#include "../algorithms/Astar.h"

#include "../data/Map.h"


/***
bool almostEqual(double x, double target) {
    double TOLERANCE = 0.1;
    return abs(x - target) / target < TOLERANCE;
}
***/
/***

TEST_CASE("Test Astar Initialize") {
    // cordinates and distacne info from Google Map
    Point* p1 = new Point(39.907637673875094, 116.39943696144262);
    Point* p2 = new Point(39.90059254163761, 116.39960862282466);
    REQUIRE( almostEqual(distance, 63) );
}

TEST_CASE("Test calcH Function") {
    Point* p1 = new Point(116.3894407, 39.9062721);
    Point* p2 = new Point(116.5352315, 39.922418);
    Astar A(p1, p2, "./DataLoader/shape.csv");
    Point* p4 = new Point(116.3395358, 39.8471243);
    double test = 18678.9;

    REQUIRE(distanceequal(p1->distance(p4),test));
    delete p1;
    delete p2;
    delete p4;
}
***/

// ------------------------
// CLAIM: This Tests Cases Provides Only A Simple Test For Astar Algorithm
// ------------------------

Map m("TEST_MAP.csv");

TEST_CASE("TEST Constructor") {


    REQUIRE());

}

TEST_CASE("TEST getSurroundPoints") {


    REQUIRE());

}

TEST_CASE("TEST calcG") {


    REQUIRE());

}

TEST_CASE("TEST calcH") {


    REQUIRE());

}

TEST_CASE("TEST calcF") {


    REQUIRE());

}

TEST_CASE("TEST IsInList") {


    REQUIRE());

}

TEST_CASE("TEST getLeastFPoint") {


    REQUIRE());

}

TEST_CASE("findPath") {


    REQUIRE());

}

TEST_CASE("getPath") {


    REQUIRE());

}