#define _USE_MATH_DEFINES
#include "Oval.h"
#include <cmath>

/*
 Default Constructor
 */
Oval::Oval():Shape()
{
    width = 0;
    height = 0;
}

/*
 Constructor
 @parem p1
 @parem p2
 @return constructor
 */
Oval::Oval(Point pt1, Point pt2):Shape(pt1, pt2)
{
    int x1 = pt1.getX();
    int x2 = pt2.getX();
    int y1 = pt1.getY();
    int y2 = pt2.getY();
    
    //user input where pt2 !< pt1
    width = x2 - x1;
    height = (y2 - y1); //Height can't be negative
    if (height < 0)
    {
        height *= -1;
    }

}

/*
 Find area
 @return area
 */
double Oval::findArea()
{
    //Need to update width and height
    Point x = getPointOne();
    Point y = getPointTwo();
    
    width = y.getX() - x.getX();
    height = y.getY() - x.getY();
    if (height < 0)
    {
        height *= -1;
    }
    
    double area;
    double r1 = (double) width / 2;
    double r2 = (double) height / 2;
    area = r1 * r2 * M_PI;
    return area;
}

/*
 Find perimeter
 @return perimeter
 */
double Oval::findPerimeter()
{
    //Need to update width and height
    Point x = getPointOne();
    Point y = getPointTwo();
    
    width = y.getX() - x.getX();
    height = y.getY() - x.getY();
    if (height < 0)
    {
        height *= -1;
    }
    
    double perimeter;
    double r1 = (double)(width * width) / 2;
    double r2 = (double)(height * height)/2;
    double r = sqrt(r1+r2);
    perimeter = 2 * M_PI * r;
    return perimeter;
}
