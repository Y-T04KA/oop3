#include "myDouble.h"

myDouble::myDouble(double v) : value(v){}

myDouble::myDouble() : value(0){}

QString& operator<<(QString& s, myDouble c) {
	s += QString::number(c.get());
	return s;
}

double myDouble::get() { return value; }

double abs(myDouble c) {
	return std::abs(c.get());
}

myDouble myDouble::operator* (myDouble d) {
	return value * d.value;
};
void myDouble::operator*= (myDouble d) {
	value *= d.value;
};

void myDouble::operator/= (myDouble d) {
	//if (d.value != 0) value /= d.value;
	//else value = 0;
	value /= d.value;
};
void myDouble::operator-= (myDouble d) {
	value -= d.value;
};