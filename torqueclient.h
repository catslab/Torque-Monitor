/****************************************************************************
**
** Copyright (C) 2015 Cedric Malitte
**
****************************************************************************/

#ifndef TORQUECLIENT_H
#define TORQUECLIENT_H

#include <qbluetoothserviceinfo.h>

#include <QtCore/QObject>

QT_FORWARD_DECLARE_CLASS(QBluetoothSocket)

QT_USE_NAMESPACE

//! [declaration]
class TorqueClient : public QObject
{
    Q_OBJECT

public:
    explicit TorqueClient(QObject *parent = 0);
    ~TorqueClient();

    void startClient(const QBluetoothServiceInfo &remoteService);
    void stopClient();

public slots:
    void sendMessage(const QString &message);

signals:
    void messageReceived(const QString &sender, const QString &message);
    void connected(const QString &name);
    void disconnected();

private slots:
    void readSocket();
    void connected();

private:
    QBluetoothSocket *socket;
};
//! [declaration]

#endif // TORQUECLIENT_H
