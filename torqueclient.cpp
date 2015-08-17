/****************************************************************************
**
** Copyright (C) 2015 Cedric Malitte
**
****************************************************************************/

#include "torqueclient.h"

#include <qbluetoothsocket.h>

TorqueClient::TorqueClient(QObject *parent)
:   QObject(parent), socket(0)
{
}

TorqueClient::~TorqueClient()
{
    stopClient();
}

//! [startClient]
void TorqueClient::startClient(const QBluetoothServiceInfo &remoteService)
{
    if (socket)
        return;

    // Connect to service
    socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);
    qDebug() << "Create socket";
    socket->connectToService(remoteService);
    qDebug() << "ConnectToService done";

    connect(socket, SIGNAL(readyRead()), this, SLOT(readSocket()));
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SIGNAL(disconnected()));
}
//! [startClient]

//! [stopClient]
void TorqueClient::stopClient()
{
    delete socket;
    socket = 0;
}
//! [stopClient]

//! [readSocket]
void TorqueClient::readSocket()
{
    if (!socket)
        return;

    QByteArray bytes;
    qint64 bc = socket->bytesAvailable();
    if ((bc>26 && bc <30) || bc>43)
    {
        bytes.resize(bc);
        //socket->read(bytes.data(), bytes.size());
         bytes = socket->readLine().trimmed();
        emit messageRawReceived( bytes );
    }
}
//! [readSocket]

//! [sendMessage]
void TorqueClient::sendMessage(const QString &message)
{
    QByteArray text = message.toUtf8() + '\n';
    socket->write(text);
}
//! [sendMessage]

//! [connected]
void TorqueClient::connected()
{
    emit connected(socket->peerName());
}
//! [connected]
