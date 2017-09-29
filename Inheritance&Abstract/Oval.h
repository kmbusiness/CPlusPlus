#include "Point.h"
#include "Shape.h"
#include <iostream>
using namespace std;

#ifndef Oval_h
#define Oval_h

class Oval : public Shape
{
private:
    int width;
    int height;
    
public:
    Oval(); // Default constructor
    Oval(Point pt1, Point pt2);
    
    //Abstract/Virtual Functions
    virtual double findArea();
    virtual double findPerimeter();
    
    //Friend
    friend ostream &operator<<(ostream &out, Oval o);
};

#endif /* Oval_h */
