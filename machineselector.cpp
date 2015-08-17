#include "machineselector.h"
#include "ui_machineselector.h"
#include <QDebug>

machineSelector::machineSelector(QString txt_proprio, QString txt_tete, QString txt_machine, int type_machine, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::machineSelector)
{
    ui->setupUi(this);
    if ( type_machine == 0)
        ui->radio_R2D->setChecked(true);
    else if ( type_machine == 1)
        ui->radio_EM1->setChecked(true);
    else
        ui->radio_ET1->setChecked(true);
}

machineSelector::~machineSelector()
{
    delete ui;
}

QString machineSelector::proprio()
{
    qDebug()<<"Appel proprio";
    proprietaire = ui->proprioEdit->text();
    return proprietaire;
}

QString machineSelector::serie_machine()
{
    qDebug()<<"Appel serie_machine";
    serieMachine = ui->machineEdit->text();
    return serieMachine;
}

QString machineSelector::serie_tete()
{
    qDebug()<<"Appel serie_tete";
    serieTete = ui->teteEdit->text();
    return serieTete;
}
