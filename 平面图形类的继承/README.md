# 1.概述
- 通过对平面图形类的继承，巩固对c++面向对象编程中封装继承等知识的理解
- 包含了如下类，其中CPoint类作为所有平面图形的成员对象，CGragh为所有具体平面图形的父类，其他均为具体的平面图形类

| class CPoint                                                                      |
| --------------------------------------------------------------------------------- |
| private:                                                                          |
| int x; // X coordinate                                                            |
| int y; // Y coordinate                                                            |
| public:                                                                           |
| CPoint();                       // Default constructor initializes point to (0,0) |
| CPoint(int xCoord, int yCoord); // Parameterized constructor                      |
|                                                                                   |
| int getX() const; // Getter for x coordinate                                      |
| int getY() const; // Getter for y coordinate                                      |
|                                                                                   |
| void setX(int xCoord); // Setter for x coordinate                                 |
| void setY(int yCoord); // Setter for y coordinate                                 |

| class CGragh                                                                 |
| ---------------------------------------------------------------------------- |
| protected:                                                                   |
| CPoint origin; // Origin point of the graph                                  |
| public:                                                                      |
| CGragh(const CPoint &p) : origin(p) {};                                      |
| virtual void show() const = 0; // Pure virtual function to display the graph |
| virtual void area() const = 0; // Pure virtual function to calculate area    |
| virtual ~CGragh() = default;                                                 |
其他类继承了CGragh的origin成员，并增加私有成员以实现具体平面图形：
- CCircle类增加了半径成员
- CRectangle类增加了宽和高成员
- CTriangle类增加了另两个顶点成员A和B（三点确定三角形）
- CSquare类增加了边长成员
# 2.知识点
- 类继承时，private成员不能继承，protected成员继承为private成员，public成员继承为private成员
- 父类CGragh中show函数和area函数设置为纯虚函数，起到子类间形式统一的作用，在子类中再具体实现这两个函数
- 父类CGragh的析构函数为虚函数，确保**通过基类指针删除派生类成员**时不会只调用基类析构函数造成子类成员的内存无法释放；现在子类析构顺序为：子类析构函数->父类析构函数->父类的父类的析构函数->成员对象的析构函数
# 3.运行结果
见附图