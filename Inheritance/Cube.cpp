#include "Cube.h"
#include <iostream>
using namespace std;

double Cube::calculateVolume(Cube c)
{
    double volume = c.depth * c.getWidth() * c.getHeight();
    return volume;
}

double Cube::calculatePerimeter(Cube c)
{
    double wid = getWidth();
    double heig = getHeight();
    double perimeter = (4*wid) + (4*heig) + (4*depth);
    return perimeter;
}

Cube::Cube(double width, double height, double d): Rectangle(width, height)
{
    depth = d;
}
