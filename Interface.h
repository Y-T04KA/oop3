#pragma once
//файла проекта нет, так как сделано в Visual Studio, он .pro файлы не делает
#include <qobject.h>
#include <qcoreapplication.h>
#include <SqMatrix.h>
#include <Comms.h>
#include "rational.h"
#include "TComplex.h"
#include "myDouble.h"

class TServerInterface : public QCoreApplication
{
	Q_OBJECT
		TComms* comm;
public:
	TServerInterface(int, char**);
signals:

public slots:
	void receive(QByteArray);
private:
	//std::vector 
};
