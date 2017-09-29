#include <iostream>
using namespace std;
#ifndef Point_h
#define Point_h

class Point
{
private:
    int x;
    int y;
    
public:
    Point();
    Point(int x, int y);
    void translate(int x, int y);
    void translate();
    int getX();
    int getY();
    
    //friend
    friend ostream &operator<<(ostream &out, Point p);
};


#endif /* Point_h */
