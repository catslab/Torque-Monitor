/****************************************************************************
**
** Copyright (C) 2015 Cedric Malitte
**
****************************************************************************/

#include "torque.h"
#include "remoteselector.h"
#include "torqueclient.h"

#include <qbluetoothuuid.h>
#include <qbluetoothserver.h>
#include <qbluetoothservicediscoveryagent.h>
#include <qbluetoothdeviceinfo.h>
#include <qbluetoothlocaldevice.h>

#include <QTimer>

#include <QDebug>
#include <QDialog>
#include <QMenuBar>

static const QLatin1String serviceUuid("00001101-0000-1000-8000-00805f9b34fb");

Torque::Torque(QWidget *parent)
    : QDialog(parent),  currentAdapterIndex(0), ui(new Ui_Torque)
{
    //! [Construct UI]
    ui->setupUi(this);
    zeroValue = 0;
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(ui->connectButton, SIGNAL(clicked()), this, SLOT(connectClicked()));
    connect(ui->zeroButton, SIGNAL(clicked()), this, SLOT(zeroClicked()));
    //createMenu();
    //! [Construct UI]

    localAdapters = QBluetoothLocalDevice::allDevices();
    if (localAdapters.count() < 2) {
        ui->localAdapterBox->setVisible(false);
    } else {
        //we ignore more than two adapters
        ui->localAdapterBox->setVisible(true);
        ui->firstAdapter->setText(tr("Default (%1)", "%1 = Bluetooth address").
                                  arg(localAdapters.at(0).address().toString()));
        ui->secondAdapter->setText(localAdapters.at(1).address().toString());
        ui->firstAdapter->setChecked(true);
        connect(ui->firstAdapter, SIGNAL(clicked()), this, SLOT(newAdapterSelected()));
        connect(ui->secondAdapter, SIGNAL(clicked()), this, SLOT(newAdapterSelected()));
        QBluetoothLocalDevice adapter(localAdapters.at(0).address());
        adapter.setHostMode(QBluetoothLocalDevice::HostDiscoverable);
    }

    //! [Get local device name]
    localName = QBluetoothLocalDevice().name();
    //! [Get local device name]
}

void Torque::createMenu()
{
    menuBar = new QMenuBar;
    menuBar->setMaximumHeight(30);

    fileMenu = new QMenu(tr("&File"), this);
    exitAction = fileMenu->addAction(tr("E&xit"));
    menuBar->addMenu(fileMenu);
    ui->verticalLayout->insertWidget(0,menuBar);
    connect(exitAction, SIGNAL(triggered()), this, SLOT(zeroClicked()));
}

Torque::~Torque()
{
    qDeleteAll(clients);
}


//! [connected]
void Torque::connected(const QString &name)
{
    ui->chat->insertPlainText(QString::fromUtf8("Connecté à %1.\n").arg(name));
}

void Torque::newAdapterSelected()
{
    const int newAdapterIndex = adapterFromUserSelection();
    if (currentAdapterIndex != newAdapterIndex) {
        currentAdapterIndex = newAdapterIndex;
        const QBluetoothHostInfo info = localAdapters.at(currentAdapterIndex);
        QBluetoothLocalDevice adapter(info.address());
        adapter.setHostMode(QBluetoothLocalDevice::HostDiscoverable);
        localName = info.name();
    }
}

int Torque::adapterFromUserSelection() const
{
    int result = 0;
    QBluetoothAddress newAdapter = localAdapters.at(0).address();

    if (ui->secondAdapter->isChecked()) {
        newAdapter = localAdapters.at(1).address();
        result = 1;
    }
    return result;
}
//! [connected]

//! [clientDisconnected]
void Torque::clientDisconnected()
{
    TorqueClient *client = qobject_cast<TorqueClient *>(sender());
    if (client) {
        clients.removeOne(client);
        client->deleteLater();
    }
}
//! [clientDisconnected]

//! [Connect to remote service]
void Torque::connectClicked()
{
    ui->connectButton->setEnabled(false);

    // scan for services
    const QBluetoothAddress adapter = localAdapters.isEmpty() ?
                                           QBluetoothAddress() :
                                           localAdapters.at(currentAdapterIndex).address();

    RemoteSelector remoteSelector(adapter);
    remoteSelector.startDiscovery(QBluetoothUuid(serviceUuid));
    if (remoteSelector.exec() == QDialog::Accepted) {
        QBluetoothServiceInfo service = remoteSelector.service();

        qDebug() << "Connecting to service 2" << service.serviceName()
                 << "on" << service.device().name();

        // Create client
        qDebug() << "Going to create client";
        TorqueClient *client = new TorqueClient(this);
qDebug() << "Connecting...";

        connect(client, SIGNAL(messageRawReceived(QByteArray)),
                this, SLOT(showRawMessage(QByteArray)));
        connect(client, SIGNAL(messageReceived(QString,QString)),
                this, SLOT(showMessage(QString,QString)));
        connect(client, SIGNAL(disconnected()), this, SLOT(clientDisconnected()));
        connect(client, SIGNAL(connected(QString)), this, SLOT(connected(QString)));
        connect(this, SIGNAL(sendMessage(QString)), client, SLOT(sendMessage(QString)));
qDebug() << "Start client";
        client->startClient(service);

        clients.append(client);
    }

    ui->connectButton->setEnabled(true);
}
//! [Connect to remote service]


//! [showMessage]
void Torque::showMessage(const QString &sender, const QString &message)
{
    //ui->chat->insertPlainText(QString::fromUtf8("%1: %2").arg(sender, message));
    ui->chat->ensureCursorVisible();
    ui->chat->setText(QString::fromUtf8("%1").arg(message));
    QString subString = message.left(4);
    bool ok;
    parsedValue = subString.toUInt(&ok, 16);
    if (!ok)
    {
        qDebug()<< "erreur parsing:"<<subString;
    }
    int displayValue = parsedValue - zeroValue;
    ui->torque_val->display(displayValue);
    subString = message.mid(18,4);
    qDebug()<<"batt:"<<subString;
    float valbatt = subString.toUInt(&ok, 16)/2000;
    QString labelBat;
      labelBat.setNum (valbatt, 'f',2);
    ui->battLabel->setText(labelBat);
}
//! [showMessage]

//! [showRawMessage]
void Torque::showRawMessage(const QByteArray &bytes)
{
    //ui->chat->insertPlainText(QString::fromUtf8("%1: %2").arg(sender, message));
    ui->chat->ensureCursorVisible();
    //ui->chat->setText(QString::fromUtf8("%d:%2").arg(bytes,message));

    QString chaine(bytes);
    chaine = chaine.simplified();
    qDebug()<<bytes.size()<<" bytes :"<<chaine;
    QStringList couple = chaine.split(',');
    if ( bytes.size() == 27 )
    {
        parsedValue = couple[1].toInt();
        int displayValue = parsedValue - zeroValue;
        ui->torque_val->display(displayValue);
    }
    if ( bytes.size() == 44 )
    {
        parsedValue = couple[1].toInt();
        int displayValue = parsedValue - zeroValue;
        ui->torque_val->display(displayValue);

        for( int i=1; i<chaine.size();i++ )
        {
            if ( couple[i] == "$B" )
            {
                ui->battLabel->setText(couple[i+1]);
                break;
            }
        }

    }
}
//! [showMessage]

//! [zeroClicked]
void Torque::zeroClicked()
{
    zeroValue = parsedValue;
}
//! [zeroClicked]
