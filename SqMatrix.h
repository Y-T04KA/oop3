#pragma once
#include "matrix.h"
class SqMatrix :
    public baseMatrix
{
public:
    SqMatrix(int size, std::vector<number> input) : baseMatrix(size, size, input) {

    }

    number findDet();
private:

};

