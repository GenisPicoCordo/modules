#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
Point a(0.0f, 0.0f);
Point b(5.0f, 0.0f);
Point c(0.0f, 5.0f);


Point p1(1.0f, 1.0f);
Point p2(5.0f, 0.0f);
Point p3(2.5f, 2.5f);
Point p4(3.0f, 1.0f);
Point p5(4.0f, 3.0f);

std::cout << std::boolalpha;
std::cout << "p1 inside? " << bsp(a,b,c,p1) << std::endl;
std::cout << "p2 inside? " << bsp(a,b,c,p2) << std::endl;
std::cout << "p3 inside? " << bsp(a,b,c,p3) << std::endl;
std::cout << "p4 inside? " << bsp(a,b,c,p4) << std::endl;
std::cout << "p5 inside? " << bsp(a,b,c,p5) << std::endl;

return 0;
}