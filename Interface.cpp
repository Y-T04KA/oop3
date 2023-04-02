#include "Interface.h"
#include <number.h>
#include <common.h>


TInterface::TInterface(int argc, char* argv[]) : QCoreApplication(argc, argv) {
	TCommParams pars = { QHostAddress("127.0.0.1"),10000, QHostAddress("127.0.0.1"),10001 };
	comm = new TComms(pars, this);
	std::cout << "TInterface is up\n";
	connect(comm, SIGNAL(received(QByteArray)), this, SLOT(receive(QByteArray)));
}

void TInterface::receive(QByteArray msg) {//msg should be like [size,mode,(data array)]
	QString answer, s,input;
	int batch_size,mode,re,im,t;
	input = QString(msg);
	std::cout << "Got message from client\n" << "msg size - " << msg.size() << "\nmessage content - " << input.toStdString() << endl;
	
	QStringList splitted = input.split(separator);
	batch_size = splitted[0].toInt();
	mode = splitted[1].toInt();
	//batch_size = msg.left(sizeof batch_size).toInt();
	//mode = msg.sliced(sizeof batch_size, sizeof mode).toInt();
	std::cout << "batch_size - " << batch_size << "\nmode - " << mode << "\nsplitted size - " << splitted.size() << endl;
	std::vector<number> data;
	for (int i = 2; i < 2+batch_size*batch_size*2; i++) {
		if (i % 2 == 0) {
			//re = splitted[i].toInt();
			re = splitted.at(i).toInt();
		}
		else {
			//im = splitted[i].toInt();
			im = splitted.at(i).toInt();
			number die(re, im);
			data.push_back(die);
		}

		//if (i == 0) t = 1; else t = i;
		//re = splitted[1 + 2 * i + 1].toInt();
		//im = splitted[1 + 2 * i + 2].toInt();
		//re = msg.sliced(t * 2 * (sizeof mode), sizeof re).toInt();
		//im = msg.sliced(t * 2 * (sizeof mode) + (sizeof re), sizeof im).toInt();
		//std::cout << "piece - " << i << "\nre - " << re << "\nim - " << im << endl;
		//number die(re, im);
		//data.push_back(die);
		//data[i] = (re, im);
	}
	instance.make(data, batch_size);
	std::cout << "processed data from request\n"<<data.size()<<endl;
	switch (mode)
	{
	case 1:
		answer += "определитель - ";
		s << instance.findDet();
		answer += s;
		std::cout << "Found determ - " << s.toStdString() << endl;
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

