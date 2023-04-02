#include "Comms.h"
#include <iostream>


TComms::TComms(TCommParams& pars, QObject* parent) :QUdpSocket(parent) {
	params = pars;
	ready = bind(params.rHost, params.rPort, QAbstractSocket::ShareAddress | QAbstractSocket::ReuseAddressHint);
	if (ready) connect(this, SIGNAL(readyRead()), this, SLOT(receive()));
}

bool TComms::isReady(){
	return ready;
}

void TComms::send(QByteArray msg) {
	if (ready) {
		std::cout << "Writing datagram\n";
		writeDatagram(msg, params.sHost, params.sPort);
	}
}

void TComms::receive() {
	if (hasPendingDatagrams()) {
		quint64 size = pendingDatagramSize();
		QByteArray msg(size, '\0');
		readDatagram(msg.data(), size);
		std::cout << "Got datagram\n";
		emit received(msg);
	}
}