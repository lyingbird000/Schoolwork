#ifndef CGRAPH_H
#define CGRAPH_H
#include "CPoint.h"
#include <iostream>

class CGragh
{
protected:
    CPoint origin; // Origin point of the graph
public:
    CGragh(const CPoint &p) : origin(p) {};
    virtual void show() const = 0; // Pure virtual function to display the graph
    virtual void area() const = 0; // Pure virtual function to calculate area
    virtual ~CGragh() = default;
};

class CCircle : public CGragh
{
private:
    double radius; // Radius of the circle
public:
    CCircle(const CPoint &org, double r);
    void show() const override;
    void area() const override;
    void setValue(CPoint org, double r);
    CPoint getOrigin() const { return origin; }
    double getRadius() const { return radius; }
    ~CCircle() override;
};

class CRectangle : public CGragh
{
private:
    double width;  // Width of the rectangle
    double height; // Height of the rectangle
public:
    CRectangle(const CPoint &org, double w, double h);
    void show() const override;
    void area() const override;
    void setValue(CPoint org, double w, double h);
    CPoint getOrigin() const { return origin; }
    double getWidth() const { return width; }
    double getHeight() const { return height; }
    ~CRectangle() override;
};

class CTriangle : public CGragh
{
private:
    CPoint vertexA; // Vertex A of the triangle
    CPoint vertexB; // Vertex B of the triangle
public:
    CTriangle(const CPoint &org, const CPoint &a, const CPoint &b);
    void show() const override;
    void area() const override;
    void setValue(CPoint org, CPoint a, CPoint b);
    CPoint getVertexA() const { return vertexA; }
    CPoint getVertexB() const { return vertexB; }
    ~CTriangle() override;
};

class CSquare : public CGragh
{
private:
    double side; // Side length of the square
public:
    CSquare(const CPoint &org, double s);
    void show() const override;
    void area() const override;
    void setValue(CPoint org, double s);
    CPoint getOrigin() const { return origin; }
    double getSide() const { return side; }
    ~CSquare() override;
};

#endif