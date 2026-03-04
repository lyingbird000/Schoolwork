#ifndef CPOINT_H
#define CPOINT_H
class CPoint
{
private:
    int x; // X coordinate
    int y; // Y coordinate
public:
    CPoint();                       // Default constructor initializes point to (0,0)
    CPoint(int xCoord, int yCoord); // Parameterized constructor

    int getX() const; // Getter for x coordinate
    int getY() const; // Getter for y coordinate

    void setX(int xCoord); // Setter for x coordinate
    void setY(int yCoord); // Setter for y coordinate
};

#endif // CPOINT_H