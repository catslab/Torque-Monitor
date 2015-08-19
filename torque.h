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
#include <QTimer>

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


    const int pressionPas = 250;
    const int pression_max[3]= {2400,2300,3000};
    const int pression_min[3] = {1000,1000,750};
    const int arrondi = 50;

public:
    Torque(QWidget *parent = 0);
    ~Torque();

signals:
    void sendMessage(const QString &message);

private slots:
    void connectClicked();
    void zeroClicked();
    void moinsClicked();
    void plusClicked();
    void recordClicked();
    void configureClicked();
    void showRawMessage(const QByteArray &bytes);
    void clientDisconnected();
    void connected(const QString &name);
    void newAdapterSelected();
    void createMenu();
    void stopRecord();
    void sauverClicked();


private:
    int adapterFromUserSelection() const;
    int currentAdapterIndex;
    Ui_Torque *ui;
    int zeroValue;
    unsigned int parsedValue;
    QList<TorqueClient *> clients;
    QList<QBluetoothHostInfo> localAdapters;

    QString localName;

    QMenuBar *menuBar;
    QMenu *fileMenu;
    QAction *exitAction;

    int machine;
    int pressionCourant;
    int pressionCompteur;
    QString serieMachine;
    QString serieTete;
    QString proprietaire;

    QTimer *recordTimer;
    int compteurSamples[100];
    int32_t sommeTorque;
    int torqueArray[15][100];
    int pressionCompteurMin;
    int pressionCompteurMax;

    QString fichierSauvegarde;

};
//! [declaration]
