#pragma once
#include <iostream>
#include <QtCore/QCoreApplication>
#include <rational.h>
#include <TComplex.h>

template<class number>
class baseMatrix {
public:
    baseMatrix(int rows_, int cols_, std::vector<number> input);
    QString transpose();
    int ranking();//need to get initial rank from rows or cols
protected:
    //typedef std::vector<std::vector<number>> Matrix;
    //typedef std::vector<number> Row; //can't put typedef to private while keeping Matrix in protected
    using Matrix = std::vector<std::vector<number>>;
    using Row = std::vector<number>;
    Matrix m;
    int cols = 3;//for square matrix we need only one dimension to be visible
private:
    int rows = 3;
};
