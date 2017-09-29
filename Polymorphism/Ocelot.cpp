//#include "Cat.h"
#include "Ocelot.h"


/*
    Default Constructor
 */
Ocelot::Ocelot()
{
    name = "None";
    hunger = 1;
}

/*
    Constructor
    @parem cat name
    @parem cat hunger
 */
Ocelot::Ocelot(string oName, int oHunger) : Cat(oName, oHunger) //Only if private do you include the Cat
{
}

/*
    Play with the cat
    @return attack damage
 */
int Ocelot::play()
{
    int attackpts = 0;
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
        cout << "Lunge at you" << endl;
        attackpts = 3;
    }
    return attackpts;
}

/*
 Pet the the cat
 @return attack damage
 */
int Ocelot::pet()
{
    int attackpts = 0;
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
        cout << "Lunge at you" << endl;
        attackpts = 0;
    }
    return attackpts;

}

/*
    Feed the cat
    @return attack damage
 */
int Ocelot::feed()
{
    int attackpts = 0;
    if (hunger == 1)
    {
        cout << "Lunge at you" << endl;
        attackpts = 0;
        
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
    return attackpts;
}
