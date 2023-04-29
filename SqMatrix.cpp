#include "SqMatrix.h"

template<class number>
number SqMatrix<number>::findDet() {
    number det = 1;
    baseMatrix<number>::template Matrix cc = m;//на всякий случай, работаем с копией матрицы
    for (int i = 0; i < cols; i++) {
        int k = i;
        for (int j = i + 1; j < cols; j++) {
            number a = cc[j][i], b = cc[k][i];
            if (abs(a) > abs(b))
                k = j;
        }
        cc[i].swap(cc[k]);
        if (i != k) det *= -1;
        det *= cc[i][i];
        for (int j = i + 1; j < cols; j++) 
            cc[i][j] /= cc[i][i];
        for (int j = 0; j < cols; j++)
            if ((j != i))
                for (k = i + 1; k < cols; k++)
                    cc[j][k] -= cc[i][k] * cc[j][i];
    }
    //std::cout << det << std::endl;
    return det;
};