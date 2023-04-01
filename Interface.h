#pragma once
//файла проекта нет, так как сделано в Visual Studio, он .pro файлы не делает
#include <qobject.h>
#include <qcoreapplication.h>
#include <matrix.h>
#include <Comms.h>

class TInterface : public QCoreApplication
{
	Q_OBJECT
		TComms* comm;
public:
	TInterface(int, char**);
signals:

public slots:
	void receive(QByteArray);
private:
	matrix instance;
};
