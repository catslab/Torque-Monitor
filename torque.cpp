/****************************************************************************
**
** Copyright (C) 2015 Cedric Malitte
**
****************************************************************************/

#include "torque.h"
#include "remoteselector.h"
#include "torqueclient.h"
#include "machineselector.h"

#include <qbluetoothuuid.h>
#include <qbluetoothserver.h>
#include <qbluetoothservicediscoveryagent.h>
#include <qbluetoothdeviceinfo.h>
#include <qbluetoothlocaldevice.h>

#include <QTimer>

#include <QDebug>
#include <QDialog>
#include <QMenuBar>
#include <QtMath>

static const QLatin1String serviceUuid("00001101-0000-1000-8000-00805f9b34fb");

Torque::Torque(QWidget *parent)
    : QDialog(parent),  currentAdapterIndex(0), ui(new Ui_Torque)
{
    //! [Construct UI]
    ui->setupUi(this);
    zeroValue = 0;
    machine=0;
    proprietaire="";
    serieMachine="";
    serieTete="";
    ui->recordButton->setDisabled(true);
    ui->pressionPlusButton->setDisabled(true);
    ui->pressionMoinsButton->setDisabled(true);
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(ui->connectButton, SIGNAL(clicked()), this, SLOT(connectClicked()));
    connect(ui->zeroButton, SIGNAL(clicked()), this, SLOT(zeroClicked()));
    connect(ui->pressionMoinsButton, SIGNAL(clicked()), this, SLOT(moinsClicked()));
    connect(ui->pressionPlusButton, SIGNAL(clicked()), this, SLOT(plusClicked()));
    connect(ui->configureButton, SIGNAL(clicked()), this, SLOT(configureClicked()));
    connect(ui->recordButton,SIGNAL(clicked()),this,SLOT(recordClicked()));
    connect(ui->envoyerButton,SIGNAL(clicked()),this, SLOT(envoyerClicked()));

    recordTimer = new QTimer(this);
        connect(recordTimer, SIGNAL(timeout()), this, SLOT(stopRecord()));

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
        parsedValue = round(couple[1].toInt()/arrondi)*arrondi;
        int displayValue = parsedValue - zeroValue;
        ui->torque_val->display(displayValue);
    }
    if ( bytes.size() == 44 )
    {
        parsedValue = round(couple[1].toInt()/arrondi)*arrondi;
        int displayValue = parsedValue - zeroValue;
        ui->torque_val->display(displayValue);
        QStringList battery = couple[5].split(' ');
        ui->battLabel->setText(QString::fromUtf8("%1 %2").arg(battery[0], "V"));
    }
    if (recordTimer->isActive())
    {
        torqueArray[pressionCompteur][compteurSamples[pressionCompteur]] = parsedValue;
        compteurSamples[pressionCompteur]++;
    }
}
//! [showMessage]

//! [zeroClicked]
void Torque::zeroClicked()
{
    zeroValue = parsedValue;
}
//! [zeroClicked]

//! [moinsClicked]
void Torque::moinsClicked()
{
    qDebug()<<"moinsClicked";
    if ( !ui->pressionPlusButton->isEnabled())
        ui->pressionPlusButton->setDisabled(false);
    pressionCompteur --;
    pressionCourant = pressionCompteur*pressionPas;
    qDebug()<<"Pression demandée:"<<pressionCourant;
    if ( pressionCourant <= pression_min[machine] )
    {
        pressionCourant = pression_min[machine];
        ui->pressionMoinsButton->setDisabled(true);
        pressionCompteurMin = pressionCompteur;
    }
    ui->pressLbl->setText(QString::number(pressionCourant));
}
//! [moinsClicked]

//! [plusClicked]
void Torque::plusClicked()
{
    qDebug()<<"plusClicked";
    if ( !ui->pressionMoinsButton->isEnabled())
        ui->pressionMoinsButton->setDisabled(false);

    pressionCompteur ++;
    pressionCourant = pressionCompteur*pressionPas;
    if ( pressionCourant >= pression_max[machine] )
    {
        pressionCourant = pression_max[machine];
        ui->pressionPlusButton->setDisabled(true);
        pressionCompteurMax = pressionCompteur;
    }
    ui->pressLbl->setText(QString::number(pressionCourant));
}
//! [plusClicked]

//! [recordClicked]
void Torque::recordClicked()
{
    qDebug()<<"recordClicked";
    ui->recordButton->setDisabled(true);
    compteurSamples[pressionCompteur]=0;
    sommeTorque =0;
    recordTimer->setSingleShot(true);
    recordTimer->start(1000);

}
//! [recordClicked]

//! [stopRecord]
void Torque::stopRecord()
{
    qDebug()<<"stopRecord";
    ui->recordButton->setDisabled(false);
    qDebug()<<"stopRecord";
    qDebug()<<"Samples comptés:"<<compteurSamples[pressionCompteur];
    qDebug()<<"Pour pression no:"<<pressionCompteur;
    if (compteurSamples[pressionCompteur] > 0 )
    {
        for (int a=0; a<compteurSamples[pressionCompteur]; a++)
        {
            sommeTorque +=torqueArray[pressionCompteur][a];
        }
        sommeTorque = round(sommeTorque / compteurSamples[pressionCompteur]);
        ui->torqueMoyen->display(sommeTorque);

    }

}
//! [stopRecord]

//! [configureClicked]
void Torque::configureClicked()
{
    qDebug()<<"configureClicked";
    ui->configureButton->setEnabled(false);
    machineSelector MachineSelector(proprietaire,serieTete,serieMachine,machine);
    if (MachineSelector.exec() == QDialog::Accepted)
    {
        qDebug()<<"machineSelector accepté fermé";
        proprietaire = MachineSelector.get_proprio();
        qDebug()<<"proprio:"<<proprietaire;
        serieMachine = MachineSelector.get_serie_machine();
        qDebug()<<"machine:"<<serieMachine;
        serieTete = MachineSelector.get_serie_tete();
        qDebug()<<"tete:"<<serieTete;
        machine = MachineSelector.get_type_machine();
        qDebug()<<"machine:"<<machine;
        ui->pressLbl->setText(QString::number(pression_min[machine]));
        qDebug()<<"P min:"<<pression_min[machine];
        qDebug()<<"P max:"<<pression_max[machine];
        ui->recordButton->setDisabled(false);
        ui->pressionPlusButton->setDisabled(false);
        ui->pressionMoinsButton->setDisabled(true);
        ui->proprioLabel->setText(proprietaire);
        ui->machine_label->setText(serieMachine);
        ui->tete_label->setText(serieTete);

        pressionCourant = pression_min[machine];
        pressionCompteur = qFloor(pression_min[machine]/pressionPas);
        pressionCompteurMin = pressionCompteur;
        pressionCompteurMax = qCeil(pression_max[machine]/pressionPas);
        if ( pressionCompteurMax*pressionPas < pression_max[machine])
            pressionCompteurMax++;
        qDebug()<<"Palier max:"<<pressionCompteurMax;
        for ( int i = 0; i < pressionCompteurMax+1 ; i++ )
        {
            compteurSamples[i] = 0;
        }
    }
    ui->configureButton->setEnabled(true);
}
//! [configureClicked]

//! [envoyerClicked]
void Torque::envoyerClicked()
{
    qDebug()<<"envoyerClicked";
    qDebug()<<"Min pression:"<<pressionCompteurMin;
    qDebug()<<"Max pression:"<<pressionCompteurMax;
    int palierpression = 0;

    for ( int i=pressionCompteurMin; i < pressionCompteurMax+1; i++ )
    {
        qDebug()<<"Nb samples "<<compteurSamples[i]<<" pour palier:"<<i;
        sommeTorque = 0;

        for (int j=0; j<compteurSamples[i]; j++)
        {
            sommeTorque +=torqueArray[i][j];
        }

        if (compteurSamples[i]>0)
            sommeTorque = round(sommeTorque / compteurSamples[i]);

        palierpression = i*pressionPas;

        if ( palierpression >= pression_max[machine] )
        {
            palierpression = pression_max[machine];
        }
        qDebug()<<"Torque moy:"<<sommeTorque<<" pour palier no:"<<i<<" et pression:"<<palierpression;
    }

}
//! [envoyerClicked]
