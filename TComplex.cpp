#include "TComplex.h"

#include <iostream>

double abs(TComplex c) {
	double i = std::sqrt(c.re * c.re + c.im * c.im);
	return i;
}

TComplex::TComplex() {
	re = 0;
	im = 0;
}

TComplex::TComplex(const int& r) {
	re = r;
	im = 0;
}

TComplex::TComplex(const int& r, const int& i) {
	re = r;
	im = i;
}

TComplex TComplex::operator*(TComplex c) {
	TComplex t;
	t.re = re * c.re - im * c.im;
	t.im = re * c.im + im * c.re;
	return t;
}

void TComplex::operator*=(TComplex c) {
	TComplex t;
	t.re = re * c.re - im * c.im;
	t.im = re * c.im + im * c.re;
	re = t.re;
	im = t.im;
}

void TComplex::operator/=(TComplex c) {
	TComplex t;
	t.re = (re * c.re + im * c.im) / (c.re * c.re + c.im * c.im);
	t.im = (c.re * im - re * c.im) / (c.re * c.re + c.im * c.im);
	re = t.re;
	im = t.im;
}

void TComplex::operator-=(TComplex c) {
	TComplex t;
	t.re = re - c.re;
	t.im = im - c.im;
	re = t.re;
	im = t.im;
}

QString& operator<<(QString& s, TComplex c) {
	s += QString().setNum(c.re);
	s += "+";
	s += QString().setNum(c.im);
	s += "i";
	return s;
}

ostream& operator<<(ostream& os, TComplex c) {
	os << c.re << "+" << c.im << "i";
	return os;
};

istream& operator>>(istream& is, TComplex& c) {
	is >> c.re >> c.im;
	return is;
};