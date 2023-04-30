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

	if ((mode % 3)==1) {
		std::vector<myDouble> data;
		for (int i = 2; i < 2 + batch_size * batch_size; i++) {
			myDouble d = splitted.at(i).toDouble();
			std::cout << d.get() << endl;
			data.push_back(d);
		}
		SqMatrix<myDouble> sq(batch_size, data);
		std::cout << "processed data from request\n" << data.size() << endl;
		switch (mode)
		{
		case 4:
			answer += "ранг вещественной матрицы - ";
			s += QString().setNum(sq.ranking());
			break;
		case 7:
			s = sq.transpose();
			break;
		default:
			answer += "определитель вещественной матрицы - ";
			s << sq.findDet();
			break;
		}
	}
	else if ((mode % 3) == 2) {
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
		switch (mode)
		{
		case 5:
			answer += "ранг комплексной матрицы - ";
			s += QString().setNum(sq.ranking());
			break;
		case 8:
			s = sq.transpose();
			break;
		default://2
			answer += "определитель комплексной матрицы - ";
			s << sq.findDet();
			break;
		}
	}
	else {
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
		switch (mode)
		{
		case 6:
			answer += "ранг комплексной матрицы - ";
			s += QString().setNum(sq.ranking());
			break;
		case 9:
			s = sq.transpose();
			break;
		default:
			answer += "определитель рациональной матрицы - ";
			s << sq.findDet();
			break;
		}
		
	}
	answer += s;
	comm->send(QByteArray().append(answer.toUtf8()));
}

