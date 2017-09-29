#include "Point.h"
#include "Shape.h"
#include <iostream>
using namespace std;

#ifndef Triangle_h
#define Triangle_h

class Triangle : public Shape
{
private:
    int width;
    int height;
    
public:
    Triangle(); //Default constructor
    Triangle(Point pt1, Point pt2);
    
    //Abstract/virtual functions
    virtual double findArea();
    virtual double findPerimeter();
    
    //friend
    friend ostream &operator<<(ostream &out, Triangle tri);
    
};

#endif /* Triangle_h */
