#pragma once
#include "matrix.h"

template<class number>
class SqMatrix :
    public baseMatrix<number>
{
public:
    SqMatrix(int size, std::vector<number> input) : baseMatrix<number>(size, size, input) {
        cols = size;

    }

    number findDet();
private:
    int cols;
    using baseMatrix<number>::m;
    
};

