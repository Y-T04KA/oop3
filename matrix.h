#pragma once
#include <iostream>
#include <number.h>
#include <QtCore/QCoreApplication>

class baseMatrix {
public:
    baseMatrix(int rows_, int cols_, std::vector<number> input);
    QString transpose();
    int ranking();//need to get initial rank from rows or cols
protected:
    typedef std::vector<std::vector<number>> Matrix;
    typedef std::vector<number> Row; //can't put typedef to private while keeping Matrix in protected
    Matrix m;
    int cols = 3;//for square matrix we need only one dimension to be visible
private:
    int rows = 3;
    bool isUsed = false;//показывает иницилизирована ли матрица, если нет возьмем дефолтную
};
