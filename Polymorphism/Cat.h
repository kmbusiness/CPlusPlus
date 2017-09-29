#include <iostream>
using namespace std;

#ifndef Cat_h
#define Cat_h

class Cat
{
private:
protected: string name; //Protect allow for the subclasses to have access
protected: int hunger;
    
public:
    Cat(string name, int hunger); // default constructor
    Cat();
    virtual int feed() = 0; //pure abstract class
    virtual int play() = 0;
    virtual int pet() = 0;
    
    friend ostream &operator<<(ostream &out, Cat &c);
};


#endif /* Cat_h */
