#include "Interface.h"
#include <common.h>

TServerInterface::TServerInterface(int argc, char* argv[]) : QCoreApplication(argc, argv) {
	TCommParams pars = { QHostAddress("127.0.0.1"),10000, QHostAddress("127.0.0.1"),10001 };
	comm = new TComms(pars, this);
	std::cout << "TInterface is up\n";
	connect(comm, SIGNAL(received(QByteArray)), this, SLOT(receive(QByteArray)));
}

void TServerInterface::receive(QByteArray msg) {//msg should be like [size,mode,(data array)]
	QString answer, s,input;
	int batch_size,mode,re,im;
	input = QString(msg);
	std::cout << "Got message from client\n" << "msg size - " << msg.size() << "\nmessage content - " << input.toStdString() << endl;
	QStringList splitted = input.split(separator);
	batch_size = splitted[0].toInt();
	mode = splitted[1].toInt();
	std::cout << "batch_size - " << batch_size << "\nmode - " << mode << "\nsplitted size - " << splitted.size() << endl;
	switch (mode)
	{
	case 1: {//deter for double
		std::vector<myDouble> data;
		for (int i = 2; i < 2 + batch_size*batch_size; i++) {
			myDouble d = splitted.at(i).toDouble();
			std::cout << d.get() << endl;
			data.push_back(d);
		}
		SqMatrix<myDouble> sq(batch_size, data);
		std::cout << "processed data from request\n" << data.size() << endl;
		answer += "определитель вещественной матрицы - ";
		s << sq.findDet();
		answer += s;
		std::cout << "Found determ - " << s.toStdString() << endl;
		break;
	}
	case 2: {//deter for complex
		std::vector<TComplex> data;
		for (int i = 2; i < 2 + batch_size * batch_size * 2; i++) {
			if (i % 2 == 0) {
				re = splitted.at(i).toInt();
			}
			else {
				im = splitted.at(i).toInt();
				TComplex die(re, im);
				data.push_back(die);
			}
		}
		SqMatrix<TComplex> sq(batch_size, data);
		answer += "определитель комплексной матрицы - ";
		s << sq.findDet();
		answer += s;
	}
		break;
	
	case 3: {//deter for rational
		std::vector<TRational> data;
		for (int i = 2; i < 2 + batch_size * batch_size * 2; i++) {
			if (i % 2 == 0) {
				re = splitted.at(i).toInt();
			}
			else {
				im = splitted.at(i).toInt();
				TRational die(re, im);
				data.push_back(die);
			}
		}
		SqMatrix<TRational> sq(batch_size, data);
		answer += "определитель рациональной матрицы - ";
		s << sq.findDet();
		answer += s; }
		break;
	
	case 4: {//rank for double
		std::vector<myDouble> data;
		for (int i = 2; i < 2 + batch_size * batch_size; i++) {
			myDouble d = splitted.at(i).toDouble();
			std::cout << d.get() << endl;
			data.push_back(d);
		}
		SqMatrix<myDouble> sq(batch_size, data);
		std::cout << "processed data from request\n" << data.size() << endl;
		answer += "ранг вещественной матрицы - ";
		s += QString().setNum(sq.ranking());
		answer += s;
		std::cout << "Found rank - " << s.toStdString() << endl;
	}
		  break;
	case 5: {//rank for complex
		std::vector<TComplex> data;
		for (int i = 2; i < 2 + batch_size * batch_size * 2; i++) {
			if (i % 2 == 0) {
				re = splitted.at(i).toInt();
			}
			else {
				im = splitted.at(i).toInt();
				TComplex die(re, im);
				data.push_back(die);
			}
		}
		SqMatrix<TComplex> sq(batch_size, data);
		answer += "ранг комплексной матрицы - ";
		s += QString().setNum(sq.ranking());
		answer += s;
	}
		break;
	case 6: {//rank for rational
		std::vector<TRational> data;
		for (int i = 2; i < 2 + batch_size * batch_size * 2; i++) {
			if (i % 2 == 0) {
				re = splitted.at(i).toInt();
			}
			else {
				im = splitted.at(i).toInt();
				TRational die(re, im);
				data.push_back(die);
			}
		}
		SqMatrix<TRational> sq(batch_size, data);
		answer += "ранг комплексной матрицы - ";
		s += QString().setNum(sq.ranking());
		answer += s;
	}
		break;
	case 7:{//trans for double
		std::vector<myDouble> data;
		for (int i = 2; i < 2 + batch_size * batch_size; i++) {
			myDouble d = splitted.at(i).toDouble();
			std::cout << d.get() << endl;
			data.push_back(d);
		}
		SqMatrix<myDouble> sq(batch_size, data);
		std::cout << "processed data from request\n" << data.size() << endl;
		s = sq.transpose();
		answer += s;
	}
		break;
	case 8:{//trans for complex
		std::vector<TComplex> data;
		for (int i = 2; i < 2 + batch_size * batch_size * 2; i++) {
			if (i % 2 == 0) {
				re = splitted.at(i).toInt();
			}
			else {
				im = splitted.at(i).toInt();
				TComplex die(re, im);
				data.push_back(die);
			}
		}
		SqMatrix<TComplex> sq(batch_size, data);
		s = sq.transpose();
		answer += s;
	}
		break;
	case 9:{//trans for rational
		std::vector<TRational> data;
		for (int i = 2; i < 2 + batch_size * batch_size * 2; i++) {
			if (i % 2 == 0) {
				re = splitted.at(i).toInt();
			}
			else {
				im = splitted.at(i).toInt();
				TRational die(re, im);
				data.push_back(die);
			}
		}
		SqMatrix<TRational> sq(batch_size, data);
		s = sq.transpose();
		answer += s;
	}
		break;
	default:
		answer = "error: incorrect mode value";
		break;
	}
	comm->send(QByteArray().append(answer.toUtf8()));
}