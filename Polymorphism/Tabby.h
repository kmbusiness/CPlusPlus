#include "Cat.h"

#ifndef Tabby_h
#define Tabby_h

class Tabby : public Cat
{
private:
    
public:
    virtual int play();
    virtual int pet();
    virtual int feed();
    Tabby(); //Default
    Tabby(string name, int hunger);
    
};


#endif /* Tabby_h */
