#include <iostream>
using namespace std;

#ifndef Rectangle_h
#define Rectangle_h

class Rectangle
{
private:
    double width, height;
    
public:
    double getWidth(){return width;}
    double getHeight(){return height;}
    Rectangle(double width = 0, double height = 0); // Default constuctor and declaring constructor
    double calculateArea(Rectangle r);
    double calculatePerimeter(Rectangle r);
    //friend
    friend ostream &operator<<(ostream &out, Rectangle rect);
    friend istream &operator>>(istream &in, Rectangle &rect);
};


#endif /* Rectangle_h */
