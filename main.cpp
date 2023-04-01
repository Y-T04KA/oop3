#include "Interface.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TInterface w(argc,argv);
    return a.exec();
}
