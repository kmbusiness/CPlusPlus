#include "Rectangle.h"
#include <iostream>
using namespace std;

#ifndef Cube_h
#define Cube_h

class Cube: public Rectangle
{
private:
    double depth;
    
public:
    //Cube(double d = 0); //Default
    Cube(double width = 0, double height = 0, double d = 0);
    double getDepth(){return depth;}
    double calculateVolume(Cube c);
    
    //friend
    friend ostream &operator<<(ostream &out, Cube c);
    friend istream &operator>>(istream &in, Cube &c);
    
    //Overload
    double calculatePerimeter(Cube c);
    
};

#endif /* Cube_h */
