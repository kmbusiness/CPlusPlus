#include "Cat.h"
#ifndef Tiger_h
#define Tiger_h

class Tiger : public Cat
{
private:
    
public:
    int play();
    int pet();
    int feed();
    Tiger(); //Default
    Tiger(string oName, int oHunger) : Cat(oName, oHunger){};
    
};

#endif /* Tiger_h */
