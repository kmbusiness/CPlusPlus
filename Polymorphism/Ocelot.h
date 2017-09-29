#include "Cat.h"

#ifndef Ocelot_h
#define Ocelot_h

class Ocelot : public Cat
{
private:
    
public:
    virtual int play();
    virtual int pet();
    virtual int feed();
    Ocelot(); //Default
    Ocelot(string name, int hunger);
    
};

#endif /* Ocelot_h */
