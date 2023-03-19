#include "Interface.h"
#include <number.h>

TInterface::TInterface(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    setWindowTitle("Работа номер 3");
    setFixedSize(300, 250);

    name_a = new QLabel("a =", this);
    name_a->setGeometry(50, 20, 30, 25);

    a_re = new QLineEdit("1", this);
    a_re->setGeometry(90, 20, 30, 25);

    del_a = new QLabel("+i", this);
    del_a->setGeometry(150, 20, 30, 25);

    a_im = new QLineEdit("0", this);
    a_im->setGeometry(190, 20, 30, 25);

    button = new QPushButton("test",this);
    button->setGeometry(150, 200, 30, 20);

    connect(button, SIGNAL(pressed()),this,SLOT(value));
    
    output = new QLabel();

}

TInterface::~TInterface()
{
    delete name_a;
    delete a_re;
    delete del_a;
    delete a_im;
    delete b_re;
    delete del_b;
    delete b_im;
    delete c_re;
    delete del_c;
    delete c_im;
    delete d_re;
    delete del_d;
    delete d_im;
    delete e_re;
    delete del_e;
    delete e_im;
    delete f_re;
    delete del_f;
    delete f_im;
    delete g_re;
    delete del_g;
    delete g_im;
    delete h_re;
    delete del_h;
    delete h_im;
    delete i_re;
    delete del_i;
    delete i_im;
    delete j_re;
    delete del_j;
    delete j_im;
    delete k_re;
    delete del_k;
    delete k_im;
    delete l_re;
    delete del_l;
    delete l_im;
    delete m_re;
    delete del_m;
    delete m_im;
    delete button;
    delete output;
}

void TInterface::value() {
    number a(a_re->text().toInt(), a_im->text().toInt());
    QString s("sample text");
    s<<a;
    s += " sample ";
    output->setText(s);//
}
