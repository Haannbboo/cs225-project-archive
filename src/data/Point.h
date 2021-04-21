
struct Point {
    unsigned x;
    unsigned y;

    Point(): Point(0, 0) {  }

    Point(unsigned x, unsigned y): Point(x, y) {  }

    bool operator==(const Point &other) const {
        return (x == other.x && y == other.y);
    }
        
}