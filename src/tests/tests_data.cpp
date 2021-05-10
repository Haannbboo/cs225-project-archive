#include "../cs225/catch/catch.hpp"

#include "../data/Map.h"


bool almostEqual(double x, double target) {
    double TOLERANCE = 0.1;
    return abs(x - target) / target < TOLERANCE;
}

/***
TEST_CASE("Test Point - distance") {
    // cordinates and distacne info from Google Map
    Point* p1 = new Point(116.39943696144262, 39.907637673875094);
    Point* p2 = new Point(116.39960862282466, 39.90059254163761);

    double distance = p1->distance(p2);

    REQUIRE( almostEqual(distance, 850) );  // actual distance is 850m

    // two close points
    p1->setNewCords(116.35651420148747, 39.91847555732769);
    p2->setNewCords(116.35723854503502, 39.91855345474758);
    distance = p1->distance(p2);

    REQUIRE( almostEqual(distance, 63) );

    delete p1;
    delete p2;
}

TEST_CASE("Test Road - split_geometry") {
    Road* r1 = new Road();
    std::string geometry;

    // empty geometry
    geometry = "LINESTRING ()";
    r1->geometry_to_cordiantes(geometry);

    REQUIRE( r1->cordinates_.empty() );
    delete r1;

    // lost entry
    geometry = "";
    r1 = new Road();
    r1->geometry_to_cordiantes(geometry);

    REQUIRE( r1->cordinates_.empty() );
    delete r1;

    // normal entry with multiple cords
    geometry = "LINESTRING (116.315387 39.9062149, 116.315548 39.9065059, 116.3156185 39.9066426, 116.31561 39.909336, 116.3156094 39.9095281, 116.3156087 39.9097712)";
    r1 = new Road();
    r1->geometry_to_cordiantes(geometry);

    REQUIRE( r1->cordinates_.size() == 6 );
    REQUIRE( r1->cordinates_[0]->x == 116.315387);
    REQUIRE( r1->cordinates_[5]->y == 39.9097712);
    delete r1;
}

TEST_CASE("Test Road - loadLine") {
    Road* r1 = new Road();
    Line line;
    line << "1,4231223,weirdtype,1,0,\"LINESTRING (116.3934609 39.8988716, 116.3933824 39.9002251, 116.39337 39.9003531, 116.393354 39.9005829, 116.3933161 39.9015519, 116.3933038 39.9018332, 116.3932139 39.903728, 116.3930952 39.90588, 116.3930805 39.9061466)\"";

    r1->loadLine(line);

    REQUIRE(r1->level_ == 10);  // default level_ for weird type names
    REQUIRE(r1->cordinates_[2]->x == 116.39337);

    Point start = Point(116.3934609, 39.8988716);
    REQUIRE(*(r1->start_) == start);

    Point end = Point(116.3930805, 39.9061466);
    REQUIRE(*(r1->end_) == end);

    REQUIRE(almostEqual(r1->length_, 800));
}

TEST_CASE("Test Map - insertPoint") {
    // Assuming everything is perfect for vertices and pointsMap in Map
    Map m;
    double x = 101.2345;
    double y = 35.0123;

    m.insertPoint(x, y);
    REQUIRE( m.points.size() == 1 );
    
    m.insertPoint(x, y);
    REQUIRE( m.points.size() == 1 );

    m.insertPoint(1234565.1234, 0.0001234);
    REQUIRE( m.points.size() == 2 );
}

TEST_CASE("Test Map - insertRoad") {
    Map m;
    m.insertPoint(100, 10);
    m.insertPoint(101, 11);
    m.insertPoint(102, 12);
    m.insertPoint(103, 13);

    Road* road = new Road();
    m.insertRoad(m.points[0], m.points[1], road);
    REQUIRE( road->start_ == m.points[0] );

    delete road;
}

TEST_CASE("Test Map - areAdjacent") {
    Map m;
    m.insertPoint(100, 10);
    m.insertPoint(101, 11);
    m.insertPoint(102, 12);
    m.insertPoint(103, 13);

    Road* r1 = new Road();
    m.insertRoad(m.points[0], m.points[1], r1);
    REQUIRE( m.areAdjacent(m.points[0], m.points[1]) );

    Road* r2 = new Road();
    m.insertRoad(m.points[0], m.points[2], r2);
    REQUIRE( m.areAdjacent(m.points[0], m.points[2]) );

    delete r1;
    delete r2;
}

***/