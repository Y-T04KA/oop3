#include "Interface.h"
#include <number.h>
#include <common.h>

TInterface::TInterface(int argc, char* argv[]) : QCoreApplication(argc, argv) {
	TCommParams pars = { QHostAddress("127.0.0.1"),10000, QHostAddress("127.0.0.1"),10001 };
	comm = new TComms(pars, this);
	connect(comm, SIGNAL(received(QByteArray)), this, SLOT(receive(QByteArray)));
}

void TInterface::receive(QByteArray msg) {//msg should be like [size,mode,(data array)]
	QString answer, s;
	int batch_size,mode,re,im,t;
	batch_size = msg.first(sizeof batch_size).toInt();
	mode = msg.sliced(sizeof batch_size, sizeof mode).toInt();
	std::vector<number> data(batch_size);
	for (int i = 0; i < batch_size; i++) {
		if (i == 0) t = 1; else t = i;
		re = msg.sliced(t * 2 * (sizeof mode), sizeof re).toInt();
		im = msg.sliced(t * 2 * (sizeof mode) + (sizeof re), sizeof im).toInt();
		data[i] = (re, im);
	}
	instance.make(data, batch_size);
	switch (mode)
	{
	case 1:
		answer += "определитель - ";
		s << instance.findDet();
		answer += s;
		break;
	case 2:
		answer += "ранг - ";
		s += QString().setNum(instance.ranking());
		answer += s;
		break;
	case 3:
		s = instance.transpose();
		answer += s;
		break;
	default:
		break;
	}
	comm->send(QByteArray().append(answer.toUtf8()));
}

