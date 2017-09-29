#include "Point.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Oval.h"
#include <iostream>
using namespace std;

//Prototypes
int getFirstPt();
int getSecondPtX(Point pt1);
int getSecondPtY(Point pt1);
int threeOptions();
void displayMain();
void functionMenu();
int checkSMenu();
int checkFMenu();
int checkScale();

int translateX();
int translateY();

void switchMenu(int *keep, int, Shape *arr[]);




Shape *makeShape();     //Get the array of shape (Not in use but for testing purposes)
Point getThefirstPoint();
Point getThesecondPoint(Point p);

int main()
{
//    Point p1(0,6);
//    Point p2(3,0);
//    Oval rec(p1, p2);
//    cout << rec;
//    cout << rec.findArea() << endl;
//    rec.scale(2);
//    Point pt = rec.getPointTwo();
//    cout << pt;
//    cout << rec.findArea() << endl;
//    cout << rec;

    
    
    Shape *arr[3];
    int *keep = new int[3];    //Keep track of user input of type of shape
    for(int i = 0; i < 3; i++)
    {
        int opt = 0;
        cout << "What should the " << i + 1 << " shape be?";
        cout << "\n1. Rectangle" << endl;
        cout << "2. Triangle" << endl;
        cout << "3. Oval" << endl;
        opt = threeOptions();
        keep[i] = opt;
        if(opt == 1)
        {
            Point p1 = getThefirstPoint();
            Point p2 = getThesecondPoint(p1);
            
//            Point p1(0,6);
//            Point p2(3,0);
            
            Rectangle rec(p1,p2);
            arr[i] = &rec;
            
            cout << "\n" << rec << endl;
        }
        else if(opt == 2)
        {
            Point p1 = getThefirstPoint();
            Point p2 = getThesecondPoint(p1);
            Triangle tri(p1,p2);
            arr[i] = &tri;
            cout << "\n" << tri << endl;
        }
        else
        {
            Point p1 = getThefirstPoint();
            Point p2 = getThesecondPoint(p1);
//            Point p1(0,6);
//            Point p2(3,0);
            //Oval o(p1,p2);
            //arr[i] = &o;
            arr[i] = new Oval(p1,p2);
            Oval *o = (Oval *) arr[i];
            
            cout << "\n" << *o << endl;
        }
    }

    //int decision;
    bool loop = true;
    while(loop)
    {
        displayMain();
        int decision = checkSMenu();
        if(decision == 1) //Rectangle
        {
            switchMenu(keep, decision, arr);
        }
        else if(decision == 2) //Triangle
        {
            switchMenu(keep, decision, arr);
        }
        else if(decision == 3)  //Oval
        {
            switchMenu(keep, decision, arr);
        }
        else
        {
            cout << "Exiting..." << endl;
            loop = false;
        }
        
    }
    
}

/*
 Check if input is valid
 @return valid input
 */
int translateX()
{
    int x = 0;
    bool loop = true;
    cout << "Enter the X amount to be tranlate over: ";
    while (loop)
    {
        if (cin >> x)
        {
            if (x > 0)
            {
                loop = false;
            }
            else
            {
                cout << "Try Again \n" << endl;
            }
        }
        else
        {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Try Again\n" << endl;
        }
    }
    return x; //Return the valid input
}

/*
 Check if input is valid
 @return valid input
 */
int translateY()
{
    int y = 0;
    bool loop = true;
    cout << "Enter the Y amount to be tranlate over: ";
    while (loop)
    {
        if (cin >> y)
        {
            if (y > 0)
            {
                loop = false;
            }
            else
            {
                cout << "Try Again \n" << endl;
            }
        }
        else
        {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Try Again\n" << endl;
        }
    }
    return y; //Return the valid input
}


/*
 Check if input is valid
 @return valid input
 */
int checkScale()
{
    int scale = 0;
    bool loop = true;
    while (loop)
    {
        if (cin >> scale)
        {
            if (scale > 0)
            {
                loop = false;
            }
            else
            {
                cout << "Try Again \n" << endl;
            }
        }
        else
        {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Try Again\n" << endl;
        }
    }
    return scale; //Return the valid input
}



/*
 Check if the menu input is valid
 @return valid menu input
 */
int checkFMenu()
{
    int menu = 0;
    bool loop = true;
    while (loop)
    {
        if (cin >> menu)
        {
            if (menu >= 1 && menu <= 6)
            {
                loop = false;
            }
            else
            {
                cout << "Try Again \n" << endl;
            }
        }
        else
        {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Try Again\n" << endl;
        }
    }
    return menu; //Return the valid menu input
}


/*
 Check if the menu input is valid
 @return valid menu input
 */
int checkSMenu()
{
    int menu = 0;
    bool loop = true;
    while (loop)
    {
        if (cin >> menu)
        {
            if (menu >= 1 && menu <= 4)
            {
                loop = false;
            }
            else
            {
                cout << "Try Again \n" << endl;
            }
        }
        else
        {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Try Again\n" << endl;
        }
    }
    return menu; //Return the valid menu input
}


/*
 Display main menu
 */
void displayMain()
{
    cout << "Shapes Menu:" << endl;
    cout << "1. Shape 1" << endl;
    cout << "2. Shape 2" << endl;
    cout << "3. Shape 3" << endl;
    cout << "4. Quit" << endl;
}

/*
 Display function menu
 */
void functionMenu()
{
    cout << "Functions Menu:" << endl;
    cout << "1. Scale" << endl;
    cout << "2. Translate" << endl;
    cout << "3. Calculate Area" << endl;
    cout << "4. Calculate Perimeter" << endl;
    cout << "5. Display Shape" << endl;
    cout << "6. Back to Shape menu" << endl;
}


/*
    Create the first point in the shape
    @parem return the point
 */
Point getThefirstPoint()
{
    int x1;
    int y1;
    cout << "X of the first point: ";
    x1 = getFirstPt();
    cout << "Y of the first point: ";
    y1 = getFirstPt();

    Point p(x1, y1);
    
    return p;
}

/*
 Create the second point in the shape
 @parem return the point
 */
Point getThesecondPoint(Point p)
{
    int x2;
    int y2;
    
    cout << "X of the second point: ";
    x2 = getSecondPtX(p);
    cout << "Y of the second point: ";
    y2 = getSecondPtY(p);
    
    Point p2(x2, y2);
    
    return p2;
}

/*
 Check if the input is valid
 @return valid input
 */
int threeOptions()
{
    int opt = 0;
    bool loop = true;
    while (loop)
    {
        if (cin >> opt)
        {
            if(opt < 4 && opt >0)
            {
                loop = false;
            }
            else
            {
                cout << "Try Again \n" << endl;
            }
        }
        else
        {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Try Again\n" << endl;
        }
    }
    return opt; //Return the valid menu input
}

/*
 Check if the point input is valid
 @return valid point input
 */
int getFirstPt()
{
    int pt = 0;
    bool loop = true;
    while (loop)
    {
        if (cin >> pt)
        {
            loop = false;
        }
        else
        {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Try Again\n" << endl;
        }
    }
    return pt; //Return the valid menu input
}

/*
 Check if the point input is valid
 @return valid point input
 */
int getSecondPtX(Point pt1)
{
    int pt2 = 0;
    int pX = pt1.getX();
    
    bool loop = true;
    while (loop)
    {
        if (cin >> pt2)
        {
            if(pt2 > pX)
            {
                loop = false;
            }
            else
            {
                cout << "Try Again \n" << endl;
            }
        }
        else
        {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Try Again\n" << endl;
        }
    }
    return pt2; //Return the valid input
}

/*
 Check if the point input is valid
 @return valid point input
 */
int getSecondPtY(Point pt1)
{
    int pt2 = 0;
    int pY = pt1.getY();
    
    bool loop = true;
    while (loop)
    {
        if (cin >> pt2)
        {
            if(pt2 < pY)
            {
                loop = false;
            }
            else
            {
                cout << "Try Again \n" << endl;
            }
        }
        else
        {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Try Again\n" << endl;
        }
    }
    return pt2; //Return the valid input
}

/*
    Create the array of shapes 
    @return array of shapes
 */
Shape *makeShape()
{
    Shape *arr[3];
    for(int i = 0; i < 3; i++)
    {
        int opt = 0;
        cout << "What should the " << i + 1 << " shape be?";
        cout << "\n1. Rectangle" << endl;
        cout << "2. Triangle" << endl;
        cout << "3. Oval" << endl;
        opt = threeOptions();
        
        if(opt == 1)
        {
            Point p1 = getThefirstPoint();
            Point p2 = getThesecondPoint(p1);
            arr[i] = new Rectangle(p1, p2);
        }
        else if(opt == 2)
        {
            Point p1 = getThefirstPoint();
            Point p2 = getThesecondPoint(p1);
            arr[i] = new Triangle(p1, p2);
        }
        else
        {
            Point p1 = getThefirstPoint();
            Point p2 = getThesecondPoint(p1);
            arr[i] = new Oval(p1, p2);
        }
    }
    
    return *arr;
}

/*
 Overload constructor for ostream
 @parem outstream
 @parem Point pt
 @return Valid print
 */
ostream &operator<<(ostream &out, Point pt)
{
    out << "("<< pt.x << "," << pt.y << ")" <<endl;
    return out;
}

/*
 Overload constructor for ostream
 @parem outstream
 @parem Rectangle rec
 @return Valid print
 */
ostream &operator<<(ostream &out, Rectangle rec)
{
    Point pt = rec.getPointOne(); //Uses the abstract class by using inheritance function
    out << "P = ("<< pt.getX() << "," << pt.getY() << "), W = " << rec.width << ", H = " << rec.height <<endl;
    return out;
}

/*
 Overload constructor for ostream
 @parem outstream
 @parem Triangle tri
 @return Valid print
 */
ostream &operator<<(ostream &out, Triangle tri)
{
    Point pt = tri.getPointOne(); //Uses the abstract class by using inheritance function
    out << "P = ("<< pt.getX() << "," << pt.getY() << "), W = " << tri.width << ", H = " << tri.height <<endl;
    return out;
}

/*
 Overload constructor for ostream
 @parem outstream
 @parem Oval o
 @return Valid print
 */
ostream &operator<<(ostream &out, Oval o)
{
    Point pt = o.getPointOne(); //Uses the abstract class by using inheritance function
    out << "P = ("<< pt.getX() << "," << pt.getY() << "), W = " << o.width << ", H = " << o.height <<endl;
    return out;
}


/*
    Switch Menu function
    @parem keep array that stores the user shape decision
    @parem num is the decision for the function menu
    @parem arr is the array that stores the shapes
 */
void switchMenu(int *keep, int num, Shape *arr[])
{

        int decision = 0;
        do
        {
            functionMenu();
            decision = checkFMenu();
            switch(decision)
            {
                case 1: //Scale
                {
                    cout << "How much you want to scale by? " << endl;
                    int scale = checkScale();
                    arr[num - 1]->scale(scale);
                    

                    
                    break;
                }
                    
                case 2: // Translate
                {
                    //Translate X and Y
                    int newX = translateX();
                    int newY = translateY();
                    
                    arr[num - 1]->translate(newX, newY);
                    break;
                }
                    
                case 3: // Calculate Area
                {
                    cout << arr[num - 1]->findArea() << endl;
                    break;
                }
                    
                case 4: // Calculate Perimeter
                {
                    cout << arr[num - 1]->findPerimeter() << endl;
                    break;
                }
                    
                case 5: // Display
                {
                    if(keep[num - 1] == 1)
                    {
                        Rectangle * rec = (Rectangle *) arr[num -1];
                        cout << "\n" << *rec;
                        
                    }
                    else if(keep[num - 1] == 2)
                    {
                        Triangle * tri = (Triangle *) arr[num -1];
                        cout << "\n" << *tri;
                    }
                    else if(keep[num - 1] == 3)
                    {
                        Oval * o = (Oval *) arr[num-1];
                        cout << "\n"<< *o;
                    }
                    
//                    else
//                    {
//                        Oval * o = (Oval *) arr[num];
//                        cout << *o;
//                    }
                    break;
                }
                  
                case 6: // Exit Function menu
                {
                    break;
                }
                default:
                {
                    break;
                }
            }
        } while (decision != 6);
}

















