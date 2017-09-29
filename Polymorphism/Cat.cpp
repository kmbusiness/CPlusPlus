#include "Cat.h"

/*
    Constructor
    @parem cat name
    @parem cat hunger
 */
Cat::Cat(string cName, int cHunger)
{
    name = cName;
    hunger = cHunger;
}

/*
    Default Constructor
 */
Cat::Cat()
{
    name = "Nameless";
    hunger = 1;
}
