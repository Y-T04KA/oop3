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

template<class number>
baseMatrix<number>::baseMatrix(int rows_, int cols_, std::vector<number> input) {
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
}

template<class number>
QString baseMatrix<number>::transpose() {
    Matrix cc = m;
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

template<class number>
int baseMatrix<number>::ranking() {
    //check();
    Matrix cc = m;
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

