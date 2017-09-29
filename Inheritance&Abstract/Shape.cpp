#include "Point.h"
#include "Shape.h"

/*
 Default Constructor
 */
Shape::Shape()
{
}

/*
 Constructor
 @parem the point1
 @parem the point2
 @return the Point
 */
Shape::Shape(Point point1, Point point2)
{
    this->point1 = point1;
    this->point2 = point2;
}

/*
    Scale the shape
    @parem the amount to scale
 */
void Shape::scale(int num)
{
    //First Point
    int x1 = point1.getX();
    
    
    int y1 = point1.getY();
    
    
    //Set new value to old point
    Point pointTemp1(x1, y1);
    
    //Second Point
    
    int oldWidth = abs(point2.getX() - point1.getX());
    int oldHeight = abs(point2.getY() - point1.getY());
    
    int newWidth = num * oldWidth;
    int newHeight = num * oldHeight;
    
    int x2;
    x2 = x1 + newWidth;
    
    int y2;
    y2 = y1 - newHeight;
    
    Point pointTemp2(x2, y2);
    point2 = pointTemp2;
    
}

void Shape::translate(int newX, int newY)
{
    Point pt1 = getPointOne();
    Point pt2 = getPointTwo();
    
    int x1 = pt1.getX();
    int x2 = pt2.getX();
    
    int y1 = pt1.getY();
    int y2 = pt2.getY();
    
    x1 += newX;
    x2 += newX;
    
    y1 += newY;
    y2 += newY;
    
    Point ptemp1 (x1, y1);
    Point ptemp2 (x2, y2);
    
    point1 = ptemp1;
    point2 = ptemp2;
}
    
/*
 Translate the shape
 @parem p1
 @parem p2
*/
//void Shape::translate(Point p1, Point p2)
//{
//    point1 = p1;
//    point2 = p2;
//}

/*
    Get the first point
    @return the first point
 */
Point Shape::getPointOne()
{
    Point pt = point1;
    return pt;
}

/*
 Get the second point
 @return the second point
 */
Point Shape::getPointTwo()
{
    Point pt = point2;
    return pt;
}
