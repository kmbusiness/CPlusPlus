/*
        John Nguyen
        Assignment 9 - Overload Constructor and Classes
 */

#include <iostream>
#include "Fraction.h"
using namespace std;

//Prototypes
int getInt(istream&);
void displayMenu();
int getMenu();
int getIntd(istream&);

int main()
{
    //  Ask User for the two fractions
    cout << "Enter the first fraction" << endl;
    Fraction f1; //Default Constructed
    cin >> f1;
    cout << "\nEnter the second fraction" << endl;
    Fraction f2; //Default Constrcuted
    cin >> f2;
    
    cout << "\nYour two fractions are: ";
    cout << "\n" << f1 << "   " << f2 << endl;
    
    int decision = 0;
    do
    {
        displayMenu();
        decision = getMenu();
        switch (decision)
        {
            case 1:     // Add
            {
                Fraction f3 = f1 + f2;
                cout << "\nAddition Result: ";
                cout << f3 << endl;
                break;
            }
                
            case 2:     // Subtract
            {
                Fraction f3 = f1 - f2;
                cout << "\nSubtraction Result: ";
                cout << f3 << endl;
                break;
            }
                
            case 3:     // Muliply
            {
                Fraction f3 = f1 * f2;
                cout << "\nMuliplication Result: ";
                cout << f3 << endl;
                break;
            }
                
            case 4:     // Divide
            {
                Fraction f3 = f1 / f2;
                cout << "\nDivision Result: ";
                cout << f3 << endl;
                break;
            }
                
            case 5:     // Equal
            {
                if (f1==f2)
                {
                    cout << "Equal" <<endl;
                    
                }
                else
                {
                    cout << "Not Equal" <<endl;
                }
                break;
            }
                
            case 6:     // New Fractions
            {
                cout << "\nEnter first NEW fraction is: " << endl;
                cin >> f1;
                cout << "\nEnter second NEW fraction is: " << endl;
                cin >> f2;
                
                cout << "\nYour two fractions are: ";
                cout << "\n" << f1 << "   " << f2 << endl;
                
                break;
                
            }
                
            case 7:
            {
                cout << "Quiting..." << endl;
                break;
            }
                
            default:
            {
                break;
            }


        }
    
    }while(decision != 7);
    
}

/*
 Overload constructor for instream
 @parem instream
 @parem Fraction fract
 @return Valid input
 */
istream &operator>>(istream &in, Fraction &fract)
{
    cout << "Enter numerator: ";
    int num = getInt(in);
    cout << "Enter denominator: ";
    int den = getIntd(in);
    
    // Need this so the 0 in the denominator will change according to the restriction
    Fraction f(num, den);
    
    fract.numerator = f.numerator;
    fract.denominator = f.denominator;
    return in;
}


/*
 Overload constructor for ostream
 @parem outstream
 @parem Fraction fract
 @return Valid outstream
 */
ostream &operator<<(ostream &out, Fraction fract)
{
    out << fract.numerator << "/" << fract.denominator;
    return out;
}

/*
 Check if the input is valid
 @parem the user input
 @return valid input
 */
int getInt(istream&)
{
    int num = 0;
    bool loop = true;
    while (loop)
    {
        if (cin >> num)
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
    return num; //Return the valid input
}

/*
 Check if the input is valid
 @parem the user input
 @return valid input
 */
int getIntd(istream&)
{
    int num = 0;
    bool loop = true;
    while (loop)
    {
        if (cin >> num)
        {
            if(num != 0)
            {
                loop = false;
            }
            else
            {
                cout << "Try Again\n" << endl;
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
 Display account menu
 */
void displayMenu()
{
    cout << "\nMenu: " << endl;
    cout << "1. Add" << endl;
    cout << "2. Subtract" << endl;
    cout << "3. Multiply" << endl;
    cout << "4. Divide" << endl;
    cout << "5. Test If Equal" << endl;
    cout << "6. Enter Two New Fractions" << endl;
    cout << "7. Quit" << endl;
}

/*
 Get the correct menu input
 @return the valid menu input
 */
int getMenu()
{
    int menu = 0;
    bool loop = true;
    while (loop)
    {
        if (cin >> menu)
        {
            if (menu >=1 && menu <= 7) //
            {
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
    return menu; //Return the valid menu input
}
