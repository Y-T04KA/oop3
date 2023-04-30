#pragma once
#include <qstring.h>
class myDouble
{
	double value;
public:
	myDouble(double);
	myDouble();
	double get();
	myDouble operator* (myDouble);
	void operator*= (myDouble);
	void operator/= (myDouble);
	void operator-= (myDouble);
	friend QString& operator<<(QString&, myDouble);
};

double abs(myDouble);

