#include "Point.h"

/*
    Default Constructor
 */
Point::Point()
{
    x = 0;
    y = 0;
}

/*
    Constructor
    @parem int x
    @parem int y
    @return Point based on int x and y
 */
Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

/*
    Get X
    @return X
 */
int Point::getX()
{
    return x;
}

/*
    Get Y
    @return Y
 */
int Point::getY()
{
    return y;
}
