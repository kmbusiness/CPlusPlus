#include <iostream>
using namespace std;

#ifndef Fraction_h
#define Fraction_h

class Fraction
{
private:
    int numerator;
    int denominator;
    
public:
    Fraction (int x = 0, int y = 0);    //Short in creating default constructor
    Fraction operator+(Fraction);
    Fraction operator-(Fraction);
    Fraction operator*(Fraction);
    Fraction operator/(Fraction);
    bool operator==(Fraction);
    //friend for instream and outstream
    friend istream &operator>>(istream &in, Fraction &fract);
    friend ostream &operator<<(ostream &out, Fraction fract);
    
};


#endif /* Fraction_h */
