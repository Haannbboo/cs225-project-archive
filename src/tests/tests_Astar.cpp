/* test for navigation algorithm */
#include "../cs225/catch/catch.hpp"
#include "../algorithms/Astar.h"
#include "../data/Road.h"
#include "../data/Map.h"



// ------------------------
// CLAIM: This Tests Cases Provides Only A Simple Test For Astar Algorithm
// ------------------------


TEST_CASE("TEST Constructor") {
    Point* p1 = new Point(0,0);
    Point* p2 = new Point(10,10);
    Astar star(p1, p2, "./tests/TEST_MAP.csv");
    REQUIRE(star.map_->vertices.size() == 5);
    REQUIRE(star.map_->points.size() == 5);
    REQUIRE(star.map_->roads.size() == 8);

}

TEST_CASE("TEST getSurroundPoints") {
    Point* p1 = new Point(0,0);
    Point* p2 = new Point(10,10);
    Astar star(p1, p2, "./tests/TEST_MAP.csv");
    std::vector<Road*> test_road = star.getSurroundPoints(star.map_->findPoint(5,5));
    std::vector<int> test_vec = {3,5,8};
    std::vector<int> test_vec2;
    for (Road* r : test_road) {
        test_vec2.push_back(r->id_);
    }
    REQUIRE(test_vec == test_vec2);
    delete p1;
    delete p2;
}


TEST_CASE("TEST calcH") {
    double A = 1568520.5567985761;
    Point* p1 = new Point(0,0);
    Point* p2 = new Point(10,10);
    Astar star(p1, p2, "./tests/TEST_MAP.csv");
    double B = star.calcH(p1);
    REQUIRE( A == B);

}

TEST_CASE("TEST IsInList") {
    Point* p1 = new Point(0,0);
    Point* p2 = new Point(10,10);
    Astar star(p1, p2, "./tests/TEST_MAP.csv");
    star.ToOpenList(star.map_->findPoint(5,5));
    star.ToOpenList(star.map_->findPoint(7,3));
    bool resultA = star.isInList(star.map_->findPoint(0,0));
    bool resultB = star.isInList(star.map_->findPoint(5,5));
    REQUIRE(resultA == false);
    REQUIRE(resultB == true);
}

TEST_CASE("TEST getLeastFPoint") {
    Point* p1 = new Point(0,0);
    Point* p2 = new Point(10,10);
    Astar star(p1, p2, "./tests/TEST_MAP.csv");
    star.ToOpenList(star.map_->findPoint(5,5));
    star.ToOpenList(star.map_->findPoint(7,3));
    star.map_->findPoint(5,5)->F = 1;
    star.map_->findPoint(7,3)->F = 2;
    Point* result = star.getLeastFpoint();
    REQUIRE(result->x == star.map_->findPoint(5,5)->x);

}
/***
TEST_CASE("findPath") {


    REQUIRE());

}
***/

TEST_CASE("getPath") {
    Point* p1 = new Point(0,0);
    Point* p2 = new Point(10,10);
    Astar star(p1, p2, "./tests/TEST_MAP.csv");
    star.ToPath(star.map_->findPoint(5,5));
    star.ToPath(star.map_->findPoint(7,3));
    star.map_->findPoint(10,10)->parent = star.map_->findPoint(7,3);
    star.map_->findPoint(7,3)->parent = star.map_->findPoint(5,5);
    star.map_->findPoint(5,5)->parent = star.map_->findPoint(0,0);

    REQUIRE());

}
