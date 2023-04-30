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

template<class number>
number SqMatrix<number>::findDet() {
    number det = 1; 
    double eps = 0.01;
    baseMatrix<number>::template Matrix cc = m;//на всякий случай, работаем с копией матрицы
    for (int i = 0; i < cols; i++) {
        int k = i;
        for (int j = i + 1; j < cols; j++) {
            number a = cc[j][i], b = cc[k][i];
            if (abs(a) > abs(b))
                k = j;
        }
        if (abs(cc[k][i]) < eps) {
            det = 0;
            break;
        }
        cc[i].swap(cc[k]);
        if (i != k) det *= -1;
        det *= cc[i][i];
        for (int j = i + 1; j < cols; j++)
            cc[i][j] /= cc[i][i];
        for (int j = 0; j < cols; j++)
            if ((j != i) && (abs(cc[j][i]) > eps) )
                for (k = i + 1; k < cols; k++)
                    cc[j][k] -= cc[i][k] * cc[j][i];
    }
    //std::cout << det << std::endl;
    return det;
};

/*template<>
myDouble SqMatrix<myDouble>::findDet() {
    myDouble det = 1;
    double eps = 0.001;
    baseMatrix<myDouble>::template Matrix cc = m;//на всякий случай, работаем с копией матрицы
    for (int i = 0; i < cols; i++) {
        int k = i;
        for (int j = i + 1; j < cols; j++) {
            myDouble a = cc[j][i], b = cc[k][i];
            if (abs(a) > abs(b))
                k = j;
        }
        if (abs(cc[k][i]) < eps) {
            det = 0;
            break;
        }
        cc[i].swap(cc[k]);
        if (i != k) det *= -1;
        det *= cc[i][i];
        for (int j = i + 1; j < cols; j++)
            cc[i][j] /= cc[i][i];
        for (int j = 0; j < cols; j++)
            if ((j != i) && abs(cc[j][i]) > eps)
                for (k = i + 1; k < cols; k++)
                    cc[j][k] -= cc[i][k] * cc[j][i];
    }
    //std::cout << det << std::endl;
    return det;
}*/

