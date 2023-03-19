#pragma once
//файла проекта нет, так как сделано в Visual Studio, он .pro файлы не делает
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qpushbutton.h>
#include "ui_TInterface.h"
#include <matrix.h>

class TInterface : public QWidget
{
    Q_OBJECT
        //я хотел бы сделать матрицу произвольных размеров, но с интерфейсным кодом не совладал
        QLabel* name_a, * del_a, * del_b, * del_c, * del_d, * del_e, * del_f, * del_g, * del_h, * del_i;
    QLineEdit* a_re, * a_im, * b_re, * b_im, * c_im, * c_re, * d_im, * d_re, * e_im, * e_re, * f_im, * f_re, * g_im, * g_re, * h_im, * h_re,
        * i_re, * i_im; 
    QPushButton* btn_det, *btn_rank, *btn_trans;

    QLabel* output;
public:
    TInterface(QWidget *parent = nullptr);
    ~TInterface();
public slots:
    void print_det();
    void print_rank();
    void print_trans();
private:
    Ui::TInterfaceClass ui;
    matrix instance;
    void actualize();
};
