#include <QtCore/QCoreApplication>
#include <iostream>
#include <number.h>
#include <matrix.h>

baseMatrix::baseMatrix(int rows_, int cols_, std::vector<number> input) {
    rows = rows_;
    cols = cols_;
    m.clear();
    int c = 0;
    for (size_t i = 0; i < rows; ++i) {
        Row row(rows);
        for (size_t j = 0; j < cols; ++j) {
            row[j] = input[c];
            c++;
        }
        m.push_back(row);
    }
    isUsed = true;
}

//void baseMatrix::make(std::vector<number> s,int isize) {
//    size = isize;
//    m.clear();
//    int c = 0;
//    for (size_t i = 0; i < size; ++i) {
//        Row row(size);
//        for (size_t j = 0; j < size; ++j) {
//            row[j] = s[c];
//            c++;
//        }
//        m.push_back(row);
//    }
//    isUsed = true;
//}

void baseMatrix::show() {
    check();
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j) std::cout << m[i][j] << " ";
        std::cout << std::endl;
    }
    return;
}

//number baseMatrix::findDet() {
//    //check();
//    det = 1;
//    cc = m;//на всякий случай, работаем с копией матрицы
//    for (int i = 0; i < size; i++) {
//        int k = i;
//        for (int j = i + 1; j < size; j++) {
//            number a = cc[j][i], b = cc[k][i];
//            if (abs(a) > abs(b))
//                k = j;
//        }
//        cc[i].swap(cc[k]);//тут должны меняться строки матрицы
//        if (i != k) det *= -1;
//        det *= cc[i][i];
//        for (int j = i + 1; j < size; j++) 
//            cc[i][j] /= cc[i][i];
//        for (int j = 0; j < size; j++)
//            if ((j != i))
//                for (k = i + 1; k < size; k++)
//                    cc[j][k] -= cc[i][k] * cc[j][i];
//    }
//    //std::cout << det << std::endl;
//    return det;
//};

void baseMatrix::transpon() {
    check();
    cc = m;
    number cache;
    for (int i = 0; i < rows; i++)
        for (int j = i; j < cols; j++) {
            cache = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = cache;
        }
    show();
    m = cc;
}

QString baseMatrix::transpose() {
    cc = m;
    number cache;
    for (int i = 0; i < rows; i++)
        for (int j = i; j < cols; j++) {
            cache = cc[i][j];
            cc[i][j] = cc[j][i];
            cc[j][i] = cache;
        }
    QString bwoah = "";
    Matrix what = cc; //somehow it breaks without such copy
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j) {
            bwoah << what[i][j];
            bwoah += "   "; 
        }
        bwoah += "\n";
    }
    return bwoah;
}

int baseMatrix::ranking() {
    check();
    cc = m;
    int rank = min(rows, cols);
    std::vector<bool> line_used(rows);
    for (int i = 0; i < rows; i++) {
        int j;
        for (j = 0; j < cols; j++)
            if (!line_used[j]) break;
        if (j == cols) --rank;
        else
        {
            line_used[j] = true;
            for (int p = i + 1; p < cols; ++p) cc[j][p] /= cc[j][i];
            for (int k = 0; k < rows; ++k)
                if (k != j)
                    for (int p = i + 1; p < cols; ++p)
                        cc[k][p] -= cc[j][p] * cc[k][i];
        }
    }
    return rank;
}

void baseMatrix::check() {
    if (!isUsed) {
        //make(3, true);
        std::cout << "Не введена матрица, используется матрица по умолчанию\n";
    }
};

//void baseMatrix::make(int s, bool based) {//метод когда у нас уже есть значения, should start with make(3,true)
//    size_t x = 0; size = s;
//    for (size_t i = 0; i < s; ++i)
//    {
//        Row row(s);
//        for (size_t j = 0; j < s; ++j, ++x) row[j] = def[x];
//        m.push_back(row);
//    }
//    isUsed = true;
//};