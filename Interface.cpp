#include "Interface.h"
#include <number.h>

TInterface::TInterface(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    setWindowTitle("Работа номер 3");
    setFixedSize(400, 300);

    name_a = new QLabel("Роженко Кирилл, Матвеев Сергей, группа 0375", this);
    name_a->setGeometry(10, 10, 360, 25);

    a_re = new QLineEdit("1", this);
    a_re->setGeometry(20, 40, 30, 25);
    del_a = new QLabel("/", this);
    del_a->setGeometry(55, 40, 30, 25);
    a_im = new QLineEdit("1", this);
    a_im->setGeometry(60, 40, 30, 25);

    b_re = new QLineEdit("1", this);
    b_re->setGeometry(110, 40, 30, 25);
    del_b = new QLabel("/", this);
    del_b->setGeometry(145, 40, 30, 25);
    b_im = new QLineEdit("1", this);
    b_im->setGeometry(150, 40, 30, 25);

    c_re = new QLineEdit("1", this);
    c_re->setGeometry(200, 40, 30, 25);
    del_c = new QLabel("/", this);
    del_c->setGeometry(235, 40, 30, 25);
    c_im = new QLineEdit("1", this);
    c_im->setGeometry(240, 40, 30, 25);
    //мне кажется, есть более цивилизованные способы делать подобное
    d_re = new QLineEdit("1", this);
    d_re->setGeometry(20, 80, 30, 25);
    del_d = new QLabel("/", this);
    del_d->setGeometry(55, 80, 30, 25);
    d_im = new QLineEdit("1", this);
    d_im->setGeometry(60, 80, 30, 25);

    e_re = new QLineEdit("1", this);
    e_re->setGeometry(110, 80, 30, 25);
    del_e = new QLabel("/", this);
    del_e->setGeometry(145, 80, 30, 25);
    e_im = new QLineEdit("1", this);
    e_im->setGeometry(150, 80, 30, 25);

    f_re = new QLineEdit("1", this);
    f_re->setGeometry(200, 80, 30, 25);
    del_f = new QLabel("/", this);
    del_f->setGeometry(235, 80, 30, 25);
    f_im = new QLineEdit("1", this);
    f_im->setGeometry(240, 80, 30, 25);

    g_re = new QLineEdit("1", this);
    g_re->setGeometry(20, 120, 30, 25);
    del_g = new QLabel("/", this);
    del_g->setGeometry(55, 120, 30, 25);
    g_im = new QLineEdit("1", this);
    g_im->setGeometry(60, 120, 30, 25);

    h_re = new QLineEdit("1", this);
    h_re->setGeometry(110, 120, 30, 25);
    del_h = new QLabel("/", this);
    del_h->setGeometry(145, 120, 30, 25);
    h_im = new QLineEdit("1", this);
    h_im->setGeometry(150, 120, 30, 25);

    i_re = new QLineEdit("1", this);
    i_re->setGeometry(200, 120, 30, 25);
    del_i = new QLabel("/", this);
    del_i->setGeometry(235, 120, 30, 25);
    i_im = new QLineEdit("1", this);
    i_im->setGeometry(240, 120, 30, 25);

    btn_det = new QPushButton("Определитель",this);
    btn_det->setGeometry(20, 150, 100, 30);

    btn_rank = new QPushButton("Ранг", this);
    btn_rank->setGeometry(130, 150, 50, 30);

    btn_trans = new QPushButton("Транспонирование", this);
    btn_trans->setGeometry(190, 150, 120, 30);
    
    
    output = new QLabel("", this);
    output->setGeometry(20, 200, 250, 70);

    connect(btn_det, SIGNAL(pressed()), this, SLOT(print_det()));
    connect(btn_rank, SIGNAL(pressed()), this, SLOT(print_rank()));
    connect(btn_trans, SIGNAL(pressed()), this, SLOT(print_trans()));
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
    /*delete j_re;
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
    delete n_re;
    delete del_n;
    delete n_im;
    delete o_re;
    delete del_o;
    delete o_im;
    delete p_re;
    delete del_p;
    delete p_im;*/
    delete btn_det;
    delete output;
}

void TInterface::print_det() {
    actualize();
    QString s("определитель - ");
    s << instance.findDet();
    //s += QString().setNum(instance.findDet().re);
    //s += "/";
    //s += QString().setNum(instance.findDet().im);
    output->setText(s);//
}

void TInterface::print_rank() {
    actualize();
    QString s("ранг - ");
    s += QString().setNum(instance.ranking());
    output->setText(s);
}

void TInterface::print_trans() {
    actualize();
    QString s=instance.transpose();
    output->setText(s);
}

void TInterface::actualize() {
    number a(a_re->text().toInt(), a_im->text().toInt()), b(b_re->text().toInt(), b_im->text().toInt()), c(c_re->text().toInt(), c_im->text().toInt()),
        d(d_re->text().toInt(), d_im->text().toInt()), e(e_re->text().toInt(), e_im->text().toInt()), f(f_re->text().toInt(), f_im->text().toInt()),
        g(g_re->text().toInt(), g_im->text().toInt()), h(h_re->text().toInt(), h_im->text().toInt()), i(i_re->text().toInt(), i_im->text().toInt());
    number cat[9];
    cat[0] = a; cat[1] = b; cat[2] = c; cat[3] = d; cat[4] = e; cat[5] = f; cat[6] = g; cat[7] = h; cat[8] = i;
    instance.make(cat);
}
