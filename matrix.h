#pragma once
#include <iostream>
#include <number.h>
#include <QtCore/QCoreApplication>

class baseMatrix {
public:
    baseMatrix(int rows_, int cols_, std::vector<number> input);
    //void make(int s);
    void make(std::vector<number>,int);
    void show();
    //number findDet(); going to descendant
    void transpon();
    QString transpose();
    int ranking();//need to get initial rank from rows or cols
protected:
    typedef std::vector<std::vector<number>> Matrix;
    typedef std::vector<number> Row; //can't put typedef to private while keeping Matrix in protected
    Matrix m, cc;
    int cols = 3;//for square matrix we need only one dimension to be visible
private:
    //number det = 1; going to descendant
    //int size = 3, rank = size;
    int rows = 3;
    bool isUsed = false;//показывает иницилизирована ли матрица, если нет возьмем дефолтную
    void check();
    //number def[9] = { 1,2,3,4,1,6,7,8,1 };
    //void make(int s, bool based);
};
