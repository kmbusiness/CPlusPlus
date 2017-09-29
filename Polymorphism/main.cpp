/*
    John Nguyen
 */


#include "Cat.h"
#include "Tabby.h"
#include "Tiger.h"
#include "Ocelot.h"
#include <iostream>
using namespace std;

//prototypes
void displayMain();
void displayCat();
int checkMMenu();
int checkSSMenu();

int main()
{
    int hp = 10;
    
    Cat *arr[3];
    arr[0] = new Ocelot("Vinh", 2);
    arr[1] = new Tiger("Tinh", 3);
    arr[2] = new Tabby("Binh", 1);
    
    int mDecision;
    bool loop = true;
    while(loop && hp > 0)
    {

        displayMain();
        if(cin >> mDecision)
        {
            if(hp <= 0)
            {
                cout << "You dead" << endl;
                loop = false;
            }
            else if(mDecision == 1) //Tiger
            {
                cout << *arr[1] << endl;
                cout << "Your current HP " << hp << endl;
                //displayCat();
                int rDecision = 0;
                do
                {
                    displayCat();
                    rDecision = checkSSMenu();
                    switch(rDecision)
                    {
                        case 1: //Play
                        {
                            hp -= arr[1]->play(); //arrow dereference than point / (*arr[1]).
                            cout << *arr[1] << endl;
                            if(hp >= 0)
                            {
                                cout << "\nYour current HP " << hp << endl;
                            }
                            
                            break;
                        }
                            
                        case 2: // Feed
                        {
                            hp -= arr[1]->feed();
                            cout << *arr[1];
                            if(hp >= 0)
                            {
                                cout << "\nYour current HP " << hp << endl;
                            }
                            break;
                        }
                            
                        case 3: // Pet
                        {
                            hp -= arr[1]->pet();
                            
                            if(hp >= 0)
                            {
                                cout << "\nYour current HP " << hp << endl;
                            }
                            break;
                        }
                            
                        case 4: // Leave
                        {
                            break;
                        }
                        default:
                        {
                            break;
                        }
                    }
                } while (rDecision != 4 && hp > 0);
            }
            
            else if(mDecision == 2) //Ocelot
            {
                cout << *arr[0] << endl;
                cout << "Your current HP " << hp << endl;
                displayCat();
                int rDecision = 0;
                do
                {
                    displayCat();
                    rDecision = checkSSMenu();
                    switch(rDecision)
                    {
                        case 1: //Play
                        {
                            hp -= arr[0]->play(); //arrow dereference than point / (*arr[1]).
                            cout << *arr[0] << endl;
                            if(hp >= 0)
                            {
                                cout << "\nYour current HP " << hp << endl;
                            }
                            break;
                        }
                            
                        case 2: // Feed
                        {
                            hp -= arr[0]->feed();
                            cout << *arr[0];
                            if(hp >= 0)
                            {
                                cout << "\nYour current HP " << hp << endl;
                            }
                            break;
                        }
                            
                        case 3: // Pet
                        {
                            hp -= arr[0]->pet();
                            if(hp >= 0)
                            {
                                cout << "\nYour current HP " << hp << endl;
                            }
                            break;
                        }
                            
                        case 4: // Leave
                        {
                            break;
                        }
                        default:
                        {
                            break;
                        }
                    }
                } while (rDecision != 4 && hp > 0);
            }
            
            else if(mDecision == 3) //Tabby
            {
                cout << *arr[2] << endl;
                cout << "Your current HP " << hp << endl;
                //displayCat();
                int rDecision = 0;
                do
                {
                    displayCat();
                    rDecision = checkSSMenu();
                    switch(rDecision)
                    {
                        case 1: //Play
                        {
                            hp -= arr[2]->play(); //arrow dereference than point / (*arr[1]).
                            cout << *arr[2] << endl;
                            if(hp >= 0)
                            {
                                cout << "\nYour current HP " << hp << endl;
                            }
                            break;
                        }
                            
                        case 2: // Feed
                        {
                            hp -= arr[2]->feed();
                            cout << *arr[2];
                            if(hp >= 0)
                            {
                                cout << "\nYour current HP " << hp << endl;
                            }
                            break;
                        }
                            
                        case 3: // Pet
                        {
                            hp -= arr[2]->pet();
                            if(hp >= 0)
                            {
                                cout << "\nYour current HP " << hp << endl;
                            }
                            break;
                        }
                            
                        case 4: // Leave
                        {
                            break;
                        }
                        default:
                        {
                            break;
                        }
                    }
                } while (rDecision != 4 && hp > 0);
            }
                
            else if(mDecision == 4)
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

    if(hp <= 0)
    {
        cout << "\nYou're dead" << endl;
    }
    
    
}


/*
 Overload constructor for ostream
 @parem outstream
 @parem Cube c
 @return Valid print
 */
ostream &operator<<(ostream &out, Cat &c)
{
    out << c.name << " is ";
    if(c.hunger == 1)
    {
        cout << "full" << endl;
    }
    else if(c.hunger == 2)
    {
        cout << "hungry" << endl;
    }
    else
    {
        cout << "very hungry" << endl;
    }
    return out;
}

/*
 Display main menu
 */
void displayMain()
{
    cout << "Cat List:" << endl;
    cout << "1. Tiger" << endl;
    cout << "2. Ocelot" << endl;
    cout << "3. Tabby" << endl;
    cout << "4. Quit" << endl;
}

/*
 Display cat menu
 */
void displayCat()
{
    cout << "Cat Interactions:" << endl;
    cout << "1. Play with the cat" << endl;
    cout << "2. Feed the cat" << endl;
    cout << "3. Pet the cat" << endl;
    cout << "4. Leave the cat" << endl;
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

