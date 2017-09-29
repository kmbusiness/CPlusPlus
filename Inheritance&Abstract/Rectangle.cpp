#include "Rectangle.h"

/*
    Default Constructor
 */
Rectangle::Rectangle(): Shape()
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
Rectangle::Rectangle(Point pt1, Point pt2):Shape(pt1, pt2)
{
    //user input where pt2 !< pt1
    //width = x2 - x1;
    width = pt2.getX() - pt1.getX();
    //height = (y2 - y1);
    height = pt2.getY() - pt1.getY();
    if (height < 0)
    {
        height *= -1;
    }
}

/*
    Find area
    @return area
 */
double Rectangle::findArea()
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
    area = width * height;
    return area;
}

/*
    Find perimeter
    @return perimeter
 */
double Rectangle::findPerimeter()
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
    perimeter = (2 * width) + (2 * height);
    return perimeter;
}
