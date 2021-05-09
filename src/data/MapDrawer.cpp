#include "MapDrawer.h"


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

void MapDrawer::drawMap(Point* p1, Point* p2) {
    // set corners
    if (p1->x < p2->x && p1->y > p2->y) {
        corner1 = p1;
        corner2 = p2;
    } else if (p1->x > p2->x && p1->y < p2->y) {
        corner1 = p2;
        corner2 = p1;
    } else {
        return;
    }

    // first determining the size of the canvas
    Point* temp2 = new Point(p2->x, p1->y);
    int width = p1->distance(temp2);
    delete temp2;

    Point* temp1 = new Point(p2->x, p1->y);
    int height = temp1->distance(p2);
    delete temp1;

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
                drawLine(p, road->otherSide(p));
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

    drawMap(corner1, corner2);
}

void MapDrawer::drawLine(Point* p1, Point* p2) {
    Cord c1 = convertCord(p1);
    Cord c2 = convertCord(p2);

    if (c1.x == c2.x) {  // draw a vertical line
        drawVerticalLine(c1, c2);
    } else if (c1.y == c2.y) {  // draw a horizontal line
        drawHorizontalLine(c1, c2);
    } else {
        drawZigZags(c1, c2);  // draw slash line
    }
}

void MapDrawer::drawLine(MapDrawer::Cord c1, MapDrawer::Cord c2) {
    if (c1.x == c2.x) {  // draw a vertical line
        drawVerticalLine(c1, c2);
    } else if (c1.y == c2.y) {  // draw a horizontal line
        drawHorizontalLine(c1, c2);
    } else {
        drawZigZags(c1, c2);  // draw slash line
    } 
}

void MapDrawer::drawVerticalLine(MapDrawer::Cord c1, MapDrawer::Cord c2) {
    // c1.x == c2.x now
    if (c1.y > c2.y) {
        double temp = c1.y;
        c1.y = c2.y;
        c2.y = temp;
    }

    // drawing vertically downwards
    for (size_t i = 0; i <= c2.y - c1.y; i++) {
        cs225::HSLAPixel& pixel = canvas->getPixel(c1.x, c1.y+i);
        pixel.h = 0;
        pixel.s = 1;
        pixel.l = 0.5;
        pixel.a = 1;
    }
}

void MapDrawer::drawHorizontalLine(MapDrawer::Cord c1, MapDrawer::Cord c2) {
    // c1.y == c2.y now
    if (c1.x > c2.x) {
        double temp = c1.x;
        c1.x = c2.x;
        c2.x = temp;
    }

    // drawing horizontally rightwards
    for (size_t i = 0; i <= c2.x - c1.x; i++) {
        cs225::HSLAPixel& pixel = canvas->getPixel(c1.x+i, c1.y);
        pixel.h = 0;
        pixel.s = 1;
        pixel.l = 0.5;
        pixel.a = 1;
    }
}

void MapDrawer::drawZigZags(MapDrawer::Cord c1, MapDrawer::Cord c2) {
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
        cs225::HSLAPixel& pixel = canvas->getPixel(x, y);
        pixel.h = 0;
        pixel.s = 1;
        pixel.l = 0.5;
        pixel.a = 1;
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
