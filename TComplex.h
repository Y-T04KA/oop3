#pragma once
#include <iostream>
#include <qstring.h>
using namespace std;


class TComplex {
public:
    double re, im;
    TComplex();
    TComplex(const int&);
    TComplex(const int&, const int&);
    TComplex operator* (TComplex);
    void operator*= (TComplex);
    void operator/= (TComplex);
    void operator-= (TComplex);
    friend ostream& operator<<(ostream&, TComplex);
    friend istream& operator>>(istream&, TComplex&);
    friend QString& operator<<(QString&, TComplex);
private:

};

double abs(TComplex);


