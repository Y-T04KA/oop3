#include "rational.h"
#include <iostream>

double abs(TRational c) {
	return std::abs(c.re/c.im);
}

TRational::TRational() {
	re = 0;
	im = 1;
}

TRational::TRational(const int& r) {
	re = r;
	im = 1;
}

TRational::TRational(const int& r, const int& i) {
	re = r;
	if (i != 0) im = i; else im = 1;
}

TRational TRational::operator*(TRational c) {
	TRational t;
	t.re = re * c.re;
	t.im = im * c.im;
	return t;
}

void TRational::operator*=(TRational c) {
	TRational t;
	t.re = re * c.re;
	t.im = im * c.im;
	//t = pretty(t);
	re = t.re;
	im = t.im;
}


void TRational::operator/=(TRational c) {
	TRational t;
	t.re = re*c.im;
	t.im = im*c.re;
	if (t.im == 0) {
		t.re = 0;
		t.im = 1;
	}
	//t = pretty(t);
	re = t.re;
	im = t.im;
}

void TRational::operator-=(TRational c) {
	double common = c.re;
	if (im != c.im) {//приведение числителя к общему знаменателю, знаменатель нам тут не нужен, так что считать его не будем 
		common = common * (im/c.im);
	}
	re = re - common;
	TRational t(re, c.im);
}

ostream& operator<<(ostream& os, TRational c) {
	os << c.re << "/" << c.im;
	return os;
};

QString& operator<<(QString& s, TRational c) {
	s += QString().setNum(c.re);
	s += "/";
	s += QString().setNum(c.im);
	return s;
}

istream& operator>>(istream& is, TRational& c) {
	is >> c.re >> c.im;
	return is;
};

//TRational TRational::pretty(TRational c) {
//	double ref = c.re / c.im;
//	for (int chis = 1; chis < c.re; chis++) 
//		for (int zna = 1; zna < c.im; zna++) {
//			if ((chis / zna) == ref) {
//				TRational success(chis,zna);
//				return success;
//			}
//		}
//	return c;
//}