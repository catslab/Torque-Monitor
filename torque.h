/****************************************************************************
**
** Copyright (C) 2015 Cedric Malitte
**
****************************************************************************/

#include "ui_torque.h"

#include <QDialog>

#include <qbluetoothserviceinfo.h>
#include <qbluetoothsocket.h>
#include <qbluetoothhostinfo.h>

#include <QDebug>

QT_BEGIN_NAMESPACE
class QMenu;
class QMenuBar;
QT_END_NAMESPACE

QT_USE_NAMESPACE

//class TorqueServer;
class TorqueClient;

//! [declaration]
class Torque : public QDialog
{
    Q_OBJECT

public:
    Torque(QWidget *parent = 0);
    ~Torque();

signals:
    void sendMessage(const QString &message);

private slots:
    void connectClicked();
    void zeroClicked();
    void showMessage(const QString &sender, const QString &message);

   /* void clientConnected(const QString &name);
    void clientDisconnected(const QString &name);
    */
    void clientDisconnected();
    void connected(const QString &name);

    void newAdapterSelected();

    void createMenu();


private:
    int adapterFromUserSelection() const;
    int currentAdapterIndex;
    Ui_Torque *ui;
    int zeroValue;
    unsigned int parsedValue;
    //TorqueServer *server;
    QList<TorqueClient *> clients;
    QList<QBluetoothHostInfo> localAdapters;

    QString localName;

    QMenuBar *menuBar;
    QMenu *fileMenu;
    QAction *exitAction;
};
//! [declaration]
