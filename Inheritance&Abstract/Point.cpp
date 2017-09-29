#include "Point.h"

/*
 Default Constructor
 */
Point::Point()
{
    this->x = 0; // same as x (just x variable)
    this->y = 0;
}

/*
    Constructor
    @parem the x
    @parem the y
    @return the Point
 */
Point::Point(int pX, int pY)
{
    this->x = pX;
    this->y = pY;
}

/*
    Tranlate the shape
    @parem x and y
 */
void Point::translate(int x, int y)
{
    this->x = x;
    this->y = y;
}

/*
    Get the x point
    @return x point
 */
int Point::getX()
{
    int xValue;
    xValue = x;
    return xValue;
}

/*
 Get the y point
 @return y point
 */
int Point::getY()
{
    int yValue;
    yValue = y;
    return yValue;
}
