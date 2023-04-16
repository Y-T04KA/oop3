#include "Interface.h"
#include <QtCore/QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "Server is up\n";
    TServerInterface w(argc,argv);
    return w.exec();
}
