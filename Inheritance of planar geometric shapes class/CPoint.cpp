#include <iostream>
#include "CPoint.h"

CPoint::CPoint() : x(0), y(0)
{
    // Default constructor initializes point to (0,0)
}

CPoint::CPoint(int xCoord, int yCoord) : x(xCoord), y(yCoord)
{
    // Parameterized constructor
}

int CPoint::getX() const
{
    return x;
}

int CPoint::getY() const
{
    return y;
}

void CPoint::setX(int xCoord)
{
    x = xCoord;
}

void CPoint::setY(int yCoord)
{
    y = yCoord;
}