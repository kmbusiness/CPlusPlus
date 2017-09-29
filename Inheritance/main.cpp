#include "Rectangle.h"
#include "Cube.h"
#include <iostream>

//Prototypes
double getDouble(istream&);
double getDoubled(istream&);

void mainMenu();
void cubeMenu();
void rectMenu();
int checkSMenu();
int checkSSMenu();
int checkMMenu();

int main()
{
    cout << "Enter Rectangle... " << endl;
    Rectangle r1;
    cin >> r1;
    cout << r1;
    
    cout << "\nEnter Cube... " << endl;
    Cube c1;
    cin >> c1;
    cout << c1;
    
    int mDecision;
    bool loop = true;
    while(loop)
    {
        mainMenu();
        if(cin >> mDecision)
        {
            if(mDecision == 1)
            {
                rectMenu();
                int rDecision = 0;
                do
                {
                    rDecision = checkSMenu();
                    switch(rDecision)
                    {
                        case 1:
                        {
                            cout << r1 << endl;
                            break;
                        }
                            
                        case 2:
                        {
                            double d = r1.calculateArea(r1);
                            cout << "Area: " << d << endl;
                            break;
                        }
                            
                        case 3:
                        {
                            double d = r1.calculatePerimeter(r1);
                            cout << "Perimeter: " << d << endl;
                            break;
                        }
                            
                        case 4:
                        {
                            break;
                        }
                        default:
                        {
                            break;
                        }
                    }
                } while (rDecision != 4);
            }
            
            else if(mDecision == 2)
            {
                cubeMenu();
                
                int cDecision = 0;
                do
                {
                    cDecision = checkSSMenu();
                    switch(cDecision)
                    {
                        case 1:
                        {
                            cout << c1 << endl;
                            break;
                        }
                            
                        case 2:
                        {
                            double d = c1.calculateArea(c1);
                            cout << "Area: " << d << endl;
                            break;
                        }
                            
                        case 3:
                        {
                            double d = c1.calculatePerimeter(c1);
                            cout << "Perimeter: " << d << endl;
                            break;
                        }
                            
                        case 4:
                        {
                            double d = c1.calculateVolume(c1);
                            cout << "Volume: " << d << endl;
                            break;
                        }
                            
                        case 5:
                        {
                            break;
                        }
                        default:
                        {
                            break;
                        }
                    }
                } while (cDecision != 5);

            }
            else if(mDecision == 3)
            {
                cout << "Exiting..." << endl;
                loop = false;
            }
            else
            {
                cout << "Try again\n" << endl;
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
    
    
}

/*
 Overload constructor for instream
 @parem instream
 @parem Rectangle r
 @return Valid input
 */
// For Rectangle
istream &operator>>(istream &in, Rectangle &r)
{
    cout << "Enter width: ";
    double wid = getDouble(in);
    cout << "Enter height: ";
    double hei = getDouble(in);
    
    r.width = wid;
    r.height = hei;
    
    return in;
}

/*
 Overload constructor for instream
 @parem instream
 @parem Rectangle r
 @return Valid input
 */
//For Cube
istream &operator>>(istream &in, Cube &c)
{
    cout << "Enter width: ";
    double wid = getDouble(in);
    cout << "Enter height: ";
    double hei = getDouble(in);
    cout << "Enter depth: ";
    double dep = getDouble(in);
    
    
    // passInArgument = TypeOfObject(parameter,parameter,parameter);
    
    c = Cube(wid, hei, dep);
    
    //cin >> one >> two >> three
    //Nested return when returned
    return in;
}

/*
 Overload constructor for ostream
 @parem outstream
 @parem Rectangle r
 @return Valid print
 */
ostream &operator<<(ostream &out, Rectangle r)
{
    out << "Rectangle => Width = " << r.width << ", Height = " << r.height << endl;
    return out;
}

/*
 Overload constructor for ostream
 @parem outstream
 @parem Cube c
 @return Valid print
 */
ostream &operator<<(ostream &out, Cube c)
{
    out << "Cube => Width = " << c.getWidth() << ", Height = " << c.getHeight() << ", Depth = " << c.depth << endl;
    return out;
}



/*
 Check if the input is valid
 @parem the user input
 @return valid input
 */
double getDouble(istream&)
{
    double num = 0;
    bool loop = true;
    while (loop)
    {
        if (cin >> num)
        {
            if(num < 0)
            {
                cout << "Try Again\n" << endl;
            }
            else
            {
                loop = false;
            }

        }
        else
        {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Try Again1\n" << endl;
        }
    }
    return num; //Return the valid input
}

/*
 Check if the input is valid
 @parem the user input
 @return valid input
 */
double getDoubled(istream&)
{
    double num = 0;
    bool loop = true;
    while (loop)
    {
        if (cin >> num)
        {
            if(num < 0)
            {
                cout << "Try Again\n" << endl;
            }
            else
            {
                loop = false;
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
    return num; //Return the valid input
}


/*
 Display main menu
 */
void mainMenu()
{
    cout << "\nPick" << endl;
    cout << "1. Rectangle" << endl;
    cout << "2. Cube" << endl;
    cout << "3. Quit" << endl;
}

/*
 Display Rectangle menu
 */
void rectMenu()
{
    cout << "Rectangle Menu:" << endl;
    cout << "1. Display Rectangle" << endl;
    cout << "2. Display Area" << endl;
    cout << "3. Display Perimeter" << endl;
    cout << "4. Back Main Menu" << endl;
}

/*
 Display Rectangle menu
 */
void cubeMenu()
{
    cout << "Cube Menu:" << endl;
    cout << "1. Display Cube" << endl;
    cout << "2. Display Area" << endl;
    cout << "3. Display Perimeter" << endl;
    cout << "4. Display Volume" << endl;
    cout << "5. Back Main Menu" << endl;
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
 Check if the menu input is valid
 @return valid menu input
 */
int checkSSMenu()
{
    int menu = 0;
    bool loop = true;
    while (loop)
    {
        if (cin >> menu)
        {
            if (menu >= 1 && menu <= 5)
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
int checkMMenu()
{
    int menu = 0;
    bool loop = true;
    while (loop)
    {
        if (cin >> menu)
        {
            if (menu >= 1 && menu <= 2)
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



