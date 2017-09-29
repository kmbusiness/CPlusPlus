#include "Point.h"
#include "Shape.h"
#include <iostream>
using namespace std;

#ifndef Rectangle_h
#define Rectangle_h

class Rectangle : public Shape
{
private:
    int width;
    int height;
    
public:
    Rectangle(); //Default constructor
    Rectangle(Point pt1, Point pt2);
    
    //abstract/virtual functions
    virtual double findArea();
    virtual double findPerimeter();
    
    //friend
    friend ostream &operator<<(ostream &out, Rectangle rec);
};

#endif /* Rectangle_h */
