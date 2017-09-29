#include<iostream>
#include "Fraction.h"
using namespace std;

/*
    Default constructor and a constructor
    @parem number for numerator
    @parem number ofr denominator
 */
Fraction::Fraction(int x, int y)
{
    this->numerator = x;
    
    if(y == 0)
    {
        this->denominator = 1;
    }
    else
    {
        this->denominator = y;
        
    }
    
}

/*
 Overload constructor for +
 @parem explicit fraction for add
 @return Fraction
 */
Fraction Fraction::operator+(Fraction exp)
{
    
    Fraction fract;
    fract = Fraction(numerator, denominator);
    
    if(fract.denominator == exp.denominator)
    {
        fract.numerator += exp.numerator;
        //fract.denominator += exp.denominator;
    }
    else
    {
        fract.numerator *= exp.denominator;
        fract.denominator *= exp.denominator;
        
        exp.numerator *= denominator;
        exp.denominator *= denominator;
        
        fract.numerator += exp.numerator;
        
    }
    
    return fract;
}

/*
 Overload constructor for -
 @parem explicit fraction for subtract
 @return Fraction
 */
Fraction Fraction::operator-(Fraction exp)
{
    Fraction fract;
    fract = Fraction(numerator, denominator);
    
    if(fract.denominator == exp.denominator)
    {
        fract.numerator -= exp.numerator;
    }
    else
    {
        fract.numerator *= exp.denominator;
        fract.denominator *= exp.denominator;
        
        exp.numerator *= denominator;
        exp.denominator *= denominator;
        
        fract.numerator -= exp.numerator;
        
    }

    return fract;
}

/*
 Overload constructor for *
 @parem explicit fraction for mulitply
 @return Fraction
 */
Fraction Fraction::operator*(Fraction exp)
{
    Fraction fract(this->numerator * exp.numerator, this->denominator * exp.denominator);
    return fract;
}

/*
 Overload constructor for /
 @parem explicit fraction for divide
 @return Fraction
 */
Fraction Fraction::operator/(Fraction exp)
{
    Fraction fract;
    fract.numerator = numerator * exp.denominator;
    fract.denominator = denominator * exp.numerator;
    return fract;
}

/*
 Overload constructor for ==
 @parem explicit fraction for ==
 @return true if equal or false if not equal
 */
bool Fraction::operator==(Fraction exp)
{
    
    int impNum = this->numerator;
    int impDen = this->denominator;
    double imp = impNum/(double)impDen;
    
    int expNum = exp.numerator;
    int expDen = exp.denominator;
    double ex = expNum/(double)expDen;
    
    
    if (imp == ex)
    {
        //cout << imp << "\n" << ex << endl;
        return true;
    }
    else
    {
        //cout << imp << "\n" << ex << endl;
        return false;
    }
    
}

