#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
  private:
    Fixed const _x;
    Fixed const _y;

  public:
    Point();                    // (0,0)
    Point(const float x, const float y);
    Point(const Point& other);
    Point& operator=(const Point& other); // no-op por ser inmutable
    ~Point();

    Fixed const & getX() const;
    Fixed const & getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif