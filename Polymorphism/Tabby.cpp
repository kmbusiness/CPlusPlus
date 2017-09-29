#include "Tabby.h"

Tabby::Tabby()
{
    name = "None";
    hunger = 1;
}

Tabby::Tabby(string oName, int oHunger) : Cat(oName, oHunger) //Only if private do you include the Cat
{
}

/*
 Play with the cat
 @return attack damage
 */
int Tabby::play()
{
    int a = 0;
    if (hunger == 1)
    {
        cout << "Play with you happily" << endl;
        hunger++;
        
    }
    else if (hunger == 2)
    {
        cout << "Runs away" << endl;
        hunger++;
    }
    else
    {
        cout << "Lunges at you" << endl;
        a = 1;
    }
    return a;
}

/*
 Pet the the cat
 @return attack damage
 */
int Tabby::pet()
{
    int a = 0;
    if (hunger == 1)
    {
        cout << "Purr and sleep" << endl;
        
    }
    else if (hunger == 2)
    {
        cout << "Let you pet and licks you" << endl;
    }
    else
    {
        cout << "Lunges at you" << endl;
        a = 3;
    }
    return a;
    
}

/*
 Feed the cat
 @return attack damage
 */
int Tabby::feed()
{
    int a = 0;
    if (hunger == 1)
    {
        cout << "Lunges at you" << endl;
        a = 1;
        
    }
    else if (hunger == 2)
    {
        cout << "Food Eaten" << endl;
        hunger = 1;
    }
    else
    {
        cout << "Food Eaten" << endl;
        hunger = 2;
    }
    return a;
}
