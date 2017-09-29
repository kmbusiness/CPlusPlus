#include "Rectangle.h"
#include <iostream>

double Rectangle::calculateArea(Rectangle r)
{
    double d = r.width * r.height;
    return d;
    
}

double Rectangle::calculatePerimeter(Rectangle r)
{
    double d = r.width + r.height;
    return d;
    
}

Rectangle::Rectangle(double wid, double hei)
{
    width = wid;
    height = hei;
}
