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

bool test_getSurroundPoints(std::vector<Road*> test1, std::vector<Roads*> test2) {
    for (int i = 0; i < test1.size(); i++) {
        if (test1[i]->id_ != test2[i]->id_) return false;
    }
    return true;
}

Map m("TEST_MAP.csv");

TEST_CASE("TEST Constructor") {
    Point* p1 = new Point(0,0);
    Point* p2 = new Point(10,10);
    Astar star(p1, p2, "TEST_MAP.csv")
    REQUIRE());

}

TEST_CASE("TEST getSurroundPoints") {
    Point* p1 = new Point(0,0);
    Point* p2 = new Point(10,10);
    Astar star(p1, p2, "TEST_MAP.csv")
    std::vector<Road*> test_road = star.getsurroundpoints(p1);
    std::vector


    REQUIRE());

}
/***
TEST_CASE("TEST calcG") {


    REQUIRE());

}

TEST_CASE("TEST calcH") {
    double = 1.56852e+06;



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
***/