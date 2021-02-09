#ifndef _FRACTION_H
#define _FRACTION_H
#include <iostream>

class Fraction {
    private:
        int numerator;
        int denominator;
    public:
        Fraction (int n, int d);
        int getNumerator ();
        int getDenominator();
        void setNumerator (int n);
        void setDenominator (int d);
        Fraction operator+ (const Fraction& num);
        Fraction operator- (const Fraction& num);
        Fraction operator* (const Fraction& num);
        Fraction operator/ (const Fraction& num);
        bool operator == (const Fraction& num);
        friend ostream& operator << (ostream& output, const Fraction& fraction);
        friend istream& operator >> (istream& input, const Fractin& fraction);

};

#endif
