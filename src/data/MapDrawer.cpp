#include "MapDrawer.h"
#include <stdlib.h>
#include <cmath>
#include <cstdlib>
#include <type_traits>

MapDrawer::MapDrawer(unsigned width, unsigned height) {
    canvas = new cs225::PNG(width, height);
}

MapDrawer::MapDrawer(Map* cityMap) {
    this->cityMap = cityMap;
}

MapDrawer::~MapDrawer() {
    clear();
}

void MapDrawer::clear() {
    delete corner1;
    delete corner2;
    roadsDrawn.clear();

    delete canvas;
    delete cityMap;
}

typename MapDrawer::Cord MapDrawer::convertCord(Point* point) {
    Point* temp = new Point(corner1->x, point->y);
    double x = point->distance(temp);
    delete temp;

    temp = new Point(point->x, corner1->y);
    double y = point->distance(temp);
    delete temp;

    return Cord(x, y);
}

bool MapDrawer::withinCanvas(Point* point) {
    return !(point->x < corner1->x || point->x > corner2->x || point->y > corner1->y || point->y < corner2->y);
}

void MapDrawer::save(std::string fpath) {
    canvas->writeToFile(fpath);
}

void MapDrawer::findEdgePoints(std::vector<Point*> points) {
    double minx, miny, maxx, maxy;
    minx = 10000;
    miny = 10000;
    maxx = 0;
    maxy = 0;
    for (auto r: points) {
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
    corner1 = new Point(minx, maxy);
    corner2 = new Point(maxx, miny);
    corner3 = new Point(maxx, maxy);
    corner4 = new Point(minx, miny);
}

void MapDrawer::drawMap(Point* p1, Point* p2) {
    /*
    // set corners
    if (p1->x < p2->x && p1->y > p2->y) {
        corner1 = p1;
        corner2 = p2;
    } else if (p1->x > p2->x && p1->y < p2->y) {
        corner1 = p2;
        corner2 = p1;
    } else {
        std::cout << p1->x << ", " << p1->y << std::endl;
        std::cout << p2->x << ", " << p2->y << std::endl;
        return;
    }
    */

    // first determining the size of the canvas
    width = corner1->distance(corner3);
    height = corner2->distance(corner3);

    std::cout << width << ", " << height << std::endl;
    canvas = new cs225::PNG(width, height);
    
    int size = cityMap->points.size();
    std::cout << "Total points to draw: " << size << std::endl;
    int cnt = 0;
    int cnt2 = 1;
    for (auto p: cityMap->points) {
        if (!withinCanvas(p)) {
            continue;
        }
        std::vector<Road*> roads = cityMap->incidentRoads(p);
        for (auto road: roads) {
            if (roadsDrawn.find(road) == roadsDrawn.end()) {
                drawLine(p, road->otherSide(p), Color());
                roadsDrawn[road] = true;
            }
        }
        if (cnt / size > cnt2 * 0.05) {
            std::cout << cnt2 * 0.05 << " percentage drawn" << std::endl;
            cnt2++;
        }
        cnt++;
    }
}

void MapDrawer::drawMap() {
    findEdgePoints(cityMap->points);

    drawMap(corner1, corner2);
}

void MapDrawer::drawMapWithSolution(std::vector<Point*> points) {
    if (points.size() < 2) {
        return;
    }
    
    findEdgePoints(points);
    if (corner1->distance(corner2) < MINDIAG) {
        // when the start & destination are too close
        double currentWidth = corner1->distance(corner3);
        if (currentWidth < MINWIDTH) {
            // we need to find two Point that have a distance about MINWIDTH

        }
        double currentHeight = corner1->distance(corner2);
    }

    drawMap(corner1, corner2);

    Color color(0, 1, 0.5, 1);
    
    for (size_t i = 0; i < points.size() - 1; i++) {
        drawLine(points[i], points[i+1], color);
    }
}

void MapDrawer::drawLine(Point* p1, Point* p2, Color color) {
    Cord c1 = convertCord(p1);
    Cord c2 = convertCord(p2);

    if (c1.x == c2.x) {  // draw a vertical line
        drawVerticalLine(c1, c2, color);
    } else if (c1.y == c2.y) {  // draw a horizontal line
        drawHorizontalLine(c1, c2, color);
    } else {
        drawZigZags(c1, c2, color);  // draw slash line
    }
}

void MapDrawer::drawLine(MapDrawer::Cord c1, MapDrawer::Cord c2, MapDrawer::Color color) {
    if (c1.x == c2.x) {  // draw a vertical line
        drawVerticalLine(c1, c2, color);
    } else if (c1.y == c2.y) {  // draw a horizontal line
        drawHorizontalLine(c1, c2, color);
    } else {
        drawZigZags(c1, c2, color);  // draw slash line
    } 
}

void MapDrawer::drawVerticalLine(MapDrawer::Cord c1, MapDrawer::Cord c2, MapDrawer::Color color) {
    // c1.x == c2.x now
    if (c1.y > c2.y) {
        double temp = c1.y;
        c1.y = c2.y;
        c2.y = temp;
    }

    // drawing vertically downwards
    for (size_t i = 0; i <= c2.y - c1.y; i++) {
        if (c1.x >= width || c1.y+i >= height) {
            continue;
        }
        cs225::HSLAPixel& pixel = canvas->getPixel(c1.x, c1.y+i);
        pixel.h = color.h;
        pixel.s = color.s;
        pixel.l = color.l;
        pixel.a = color.a;
    }
}

void MapDrawer::drawHorizontalLine(MapDrawer::Cord c1, MapDrawer::Cord c2, MapDrawer::Color color) {
    // c1.y == c2.y now
    if (c1.x > c2.x) {
        double temp = c1.x;
        c1.x = c2.x;
        c2.x = temp;
    }

    // drawing horizontally rightwards
    for (size_t i = 0; i <= c2.x - c1.x; i++) {
        if (c1.x+i >= width || c1.y >= height) {
            continue;
        }
        cs225::HSLAPixel& pixel = canvas->getPixel(c1.x+i, c1.y);
        pixel.h = color.h;
        pixel.s = color.s;
        pixel.l = color.l;
        pixel.a = color.a;
    }
}

void MapDrawer::drawZigZags(MapDrawer::Cord c1, MapDrawer::Cord c2, MapDrawer::Color color) {
    // always draw from c1 to c2
    
    bool opposite;
    if ((c1.x < c2.x && c1.y < c2.y) != (c2.x < c1.x && c2.y < c1.y)) {  
        // when c1 < c2 or c1 > c2 for both x and y
        // drawing y = kx for k < 0
        opposite = false;
        if (c2.x < c1.x) {
            Cord ctemp(c1.x, c1.y);
            c1 = c2;
            c2 = ctemp;
        }
    } else {
        // drawing y = kx for k > 0
        opposite = true;
        if (c1.x < c2.x && c1.y > c2.y) {
            Cord ctemp(c1.x, c1.y);
            c1 = c2;
            c2 = ctemp;
        }
    }
    int dx = abs(c2.x - c1.x);
    int dy = abs(c2.y - c1.y);

    int x = c1.x;
    int y = c1.y;

    while (dx >= 0 && dy >= 0) {
        if (x < width && y < height) {
            cs225::HSLAPixel& pixel = canvas->getPixel(x, y);
            pixel.h = color.h;
            pixel.s = color.s;
            pixel.l = color.l;
            pixel.a = color.a;
        }
        if (dx > dy) {
            dx--;
            if (opposite) x--;
            else x++;
        } else {
            dy--;
            y++;
        }
    }

}
