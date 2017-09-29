#include "Tiger.h"

Tiger::Tiger()
{
    name = "None";
    hunger = 1;
}

/*
 Play with the cat
 @return attack damage
 */
int Tiger::play()
{
    int a = 0;
    if (hunger == 1)
    {
        cout << "Chases its tail" << endl;
        hunger++;
        
    }
    else if (hunger == 2)
    {
        cout << "Pet your head" << endl;
        hunger++;
    }
    else
    {
        cout << "Lunges at you and bite your neck" << endl;
        a = 10;
    }
    return a;
}

/*
 Pet the the cat
 @return attack damage
 */
int Tiger::pet()
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
        cout << "Lunges at you and bite your neck" << endl;
        a = 10;
    }
    return a;
    
}


/*
 Feed the cat
 @return attack damage
 */
int Tiger::feed()
{
    int a = 0;
    if (hunger == 1)
    {
        cout << "Lunge at you and bite your neck" << endl;
        a = 10;
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
