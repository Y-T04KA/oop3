#pragma once
#include <iostream>
#include <number.h>
#include <QtCore/QCoreApplication>

class matrix {
public:
    void make(int s);
    void make(std::vector<number>,int);
    void show();
    number findDet();
    void transpon();
    QString transpose();
    int ranking();
private:
    number det = 1;
    typedef std::vector<std::vector<number>> Matrix;
    typedef std::vector<number> Row;
    Matrix m, cc;
    int size = 3, rank = size;
    bool isUsed = false;//показывает иницилизирована ли матрица, если нет возьмем дефолтную
    void check();
    number def[9] = { 1,2,3,4,1,6,7,8,1 };
    void make(int s, bool based);
};
