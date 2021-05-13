/* test for navigation algorithm */
#include "../cs225/catch/catch.hpp"
#include "../algorithms/Astar.h"
#include "../data/Road.h"
#include "../data/Map.h"

// ------------------------
// CLAIM: This Tests Case Only Provides Test For Astar Algorithm
// ------------------------

TEST_CASE("TEST Constructor") {
    Point* p1 = new Point(0,0);
    Point* p2 = new Point(10,10);
    Astar star(p1, p2, "./tests/TEST_MAP.csv");
    REQUIRE(star.map_->vertices.size() == 5);
    REQUIRE(star.map_->points.size() == 5);
    REQUIRE(star.map_->roads.size() == 8);
    delete p1;
    delete p2;
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
    double A = 2086132.3405421064;
    Point* p1 = new Point(0,0);
    Point* p2 = new Point(10,10);
    Astar star(p1, p2, "./tests/TEST_MAP.csv");
    double B = star.calcH(p1);
    REQUIRE( A == B);
    delete p1;
    delete p2;
}

TEST_CASE("TEST IsInList with Empty Input") {
    Point* p1 = new Point(0,0);
    Point* p2 = new Point(10,10);
    Astar star(p1, p2, "./tests/TEST_MAP.csv");
    star.ToOpenList(star.map_->findPoint(5,5));
    star.ToOpenList(star.map_->findPoint(7,3));
    bool resultA = star.isInList(star.map_->findPoint(0,0));
    bool resultB = star.isInList(star.map_->findPoint(5,5));
    REQUIRE(resultA == false);
    REQUIRE(resultB == true);
    delete p1;
    delete p2;
}

TEST_CASE("TEST IsInList with Point Input") {
    Point* p1 = new Point(0,0);
    Point* p2 = new Point(10,10);
    Astar star(p1, p2, "./tests/TEST_MAP.csv");
    star.ToOpenList(star.map_->findPoint(5,5));
    star.ToOpenList(star.map_->findPoint(7,3));
    star.ToOpenList(star.map_->findPoint(10,10));
    Point* result = star.isInList();
    REQUIRE(result->x == 10);
    REQUIRE(result->y == 10); 
    delete p1;
    delete p2;
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
    REQUIRE(result->y == 5);
    REQUIRE(result->x == 5);
    delete p1;
    delete p2;
}

TEST_CASE("TEST getPath") {
    Point* p1 = new Point(0,0);
    Point* p2 = new Point(10,10);
    Astar star(p1, p2, "./tests/TEST_MAP.csv");
    Point* result = star.findPath();
    REQUIRE(result->parent == star.map_->findPoint(5,5));

    result = result->parent;
    REQUIRE(result->parent == star.map_->findPoint(0,0));

    result = result->parent;
    REQUIRE(result->parent == nullptr); 
    delete p1;
    delete p2;
}
