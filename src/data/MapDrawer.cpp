#include "MapDrawer.h"


MapDrawer::MapDrawer() {

}

MapDrawer::MapDrawer(Map* cityMap) {
    this->cityMap = cityMap;
}

typename MapDrawer::Cord MapDrawer::convertCord(Point* point) {
    double px = point->x;
    double py = point->y;

    return Cord(px, py);
}

cs225::PNG* MapDrawer::drawMap(Point* p1, Point* p2) {
    // first determining the size of the canvas
    Point* temp1 = new Point(p1->x, 100);
    Point* temp2 = new Point(p2->x, 100);
    int width = temp1->distance(temp2);
    delete temp1;
    delete temp2;

    temp1 = new Point(100, p1->y);
    temp2 = new Point(100, p2->y);
    int height = temp1->distance(temp2);

    std::cout << width << ", " << height << std::endl;

    cs225::PNG* png = new cs225::PNG(width, height);
    return png;
}

cs225::PNG* MapDrawer::drawMap() {
    double minx, miny, maxx, maxy;
    minx = 10000;
    miny = 10000;
    maxx = 0;
    maxy = 0;
    for (auto r: cityMap->points) {
        if (r->x < minx) {
            minx = r->x;
        } else if (r->x > maxx) {
            maxx = r->x;
        }
        if (r->y < miny) {
            miny = r->y;
        } else if (r->y > maxy) {
            maxy = r->y;
        }
    }
    corner1 = new Point(minx, miny);
    corner2 = new Point(maxx, maxy);

    return drawMap(corner1, corner2);
}