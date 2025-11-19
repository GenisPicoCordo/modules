#include "Point.hpp"


static Fixed sign(Point const &p1, Point const &p2, Point const &p3) {
    Fixed x1 = p1.getX();
    Fixed y1 = p1.getY();
    Fixed x2 = p2.getX();
    Fixed y2 = p2.getY();
    Fixed x3 = p3.getX();
    Fixed y3 = p3.getY();
    return (x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3);
}

bool bsp(Point const a, Point const b, Point const c, Point const point);

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed d1 = sign(point, a, b);
    Fixed d2 = sign(point, b, c);
    Fixed d3 = sign(point, c, a);

    bool hasNeg = (d1 < Fixed(0)) || (d2 < Fixed(0)) || (d3 < Fixed(0));
    bool hasPos = (d1 > Fixed(0)) || (d2 > Fixed(0)) || (d3 > Fixed(0));

    if (d1 == Fixed(0) || d2 == Fixed(0) || d3 == Fixed(0))
    return false;

    return !(hasNeg && hasPos);
}