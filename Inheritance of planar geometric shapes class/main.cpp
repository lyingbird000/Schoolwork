#include <iostream>
#include "CPoint.h"
#include "CGraph.h"

int main()
{
    CPoint p1(2, 3);
    CCircle circle(p1, 5.0);
    circle.show();
    circle.area();

    CPoint p2(0, 0);
    CRectangle rectangle(p2, 4.0, 6.0);
    rectangle.show();
    rectangle.area();

    CPoint a(1, 1);
    CPoint b(4, 1);
    CTriangle triangle(p2, a, b);
    triangle.show();
    triangle.area();

    return 0;
}