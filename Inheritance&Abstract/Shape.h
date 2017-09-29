#include "Point.h"

#ifndef Shape_h
#define Shape_h

class Shape : public Point
{
    protected:Point point1;
    protected:Point point2;
public:
    Shape(Point point1, Point point2); //Constructor
    Shape(); //default constructor
    void scale(int num);
    //void translate(Point p1, Point p2);
    void translate(int x, int y);
    Point getPointOne();
    Point getPointTwo();
    
    //Pure Abstraction
    virtual double findArea() = 0;
    virtual double findPerimeter() = 0;
    
};

#endif /* Shape_h */
