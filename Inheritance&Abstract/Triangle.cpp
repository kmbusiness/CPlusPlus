#include "Triangle.h"
#include <cmath>

/*
 Default Constructor
 */
Triangle::Triangle() : Shape()
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
Triangle::Triangle(Point pt1, Point pt2) : Shape(pt1, pt2)
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
double Triangle::findArea()
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
    area = (width * height) / 2;
    return area;
}

/*
 Find perimeter
 @return perimeter
 */
double Triangle::findPerimeter()
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
    int cSquare;
    cSquare = ((width * width) + (height * height));
    double c = sqrt((double)cSquare);
    perimeter = width + height + c;
    return perimeter;
}
