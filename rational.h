#pragma once
#include <iostream>
#include <qstring.h>
//несмотря на имя, теперь это будет 
using namespace std;


class TRational {
public:
    double re, im;
    TRational();
    TRational(const int&);
    TRational(const int&, const int&);
    TRational operator* (TRational);
    void operator*= (TRational);
    void operator/= (TRational);
    void operator-= (TRational);
    friend ostream& operator<<(ostream&, TRational);
    friend istream& operator>>(istream&, TRational&);
    friend QString& operator<<(QString&, TRational);
};

double abs(TRational);
