#include <iostream>
#include "CPoint.h"
#include "CGraph.h"

CCircle::CCircle(const CPoint &org, double r) : radius(r), CGragh(org)
{
}

void CCircle::show() const
{
    std::cout << "Circle: Center(" << origin.getX() << ", " << origin.getY() << "), Radius: " << radius << std::endl;
}

void CCircle::area() const
{
    double area = 3.14159 * radius * radius;
    std::cout << "Circle Area: " << area << std::endl;
}

CCircle::~CCircle()
{
    // Destructor
}

void CCircle::setValue(CPoint org, double r)
{
    origin = org;
    radius = r;
}

CRectangle::CRectangle(const CPoint &org, double w, double h) : width(w), height(h), CGragh(org)
{
}

void CRectangle::show() const
{
    std::cout << "Rectangle: Origin(" << origin.getX() << ", " << origin.getY() << "), Width: " << width << ", Height: " << height << std::endl;
}

void CRectangle::area() const
{
    double area = width * height;
    std::cout << "Rectangle Area: " << area << std::endl;
}

CRectangle::~CRectangle()
{
    // Destructor
}

CTriangle::CTriangle(const CPoint &org, const CPoint &a, const CPoint &b) : CGragh(org), vertexA(a), vertexB(b)
{
}

void CTriangle::show() const
{
    std::cout << "Triangle: Origin(" << origin.getX() << ", " << origin.getY() << "), VertexA(" << vertexA.getX() << ", " << vertexA.getY() << "), VertexB(" << vertexB.getX() << ", " << vertexB.getY() << ")" << std::endl;
}

void CTriangle::area() const
{
    double area = 0.5 * std::abs((vertexA.getX() - origin.getX()) * (vertexB.getY() - origin.getY()) - (vertexB.getX() - origin.getX()) * (vertexA.getY() - origin.getY()));
    std::cout << "Triangle Area: " << area << std::endl;
}

CTriangle::~CTriangle()
{
    // Destructor
}

CSquare::CSquare(const CPoint &org, double s) : side(s), CGragh(org)
{
}

void CSquare::show() const
{
    std::cout << "Square: Origin(" << origin.getX() << ", " << origin.getY() << "), Side: " << side << std::endl;
}

void CSquare::area() const
{
    double area = side * side;
    std::cout << "Square Area: " << area << std::endl;
}

CSquare::~CSquare()
{
    // Destructor
}