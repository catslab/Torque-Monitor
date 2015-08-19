#include "machineselector.h"
#include "ui_machineselector.h"
#include <QDebug>

machineSelector::machineSelector(QString txt_proprio, QString txt_tete, QString txt_machine, int type_machine, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::machineSelector)
{
    ui->setupUi(this);
    ui->machineGroup->setId(ui->radio_R2D,0);
    ui->machineGroup->setId(ui->radio_EM1,1);
    ui->machineGroup->setId(ui->radio_ET1,2);
    machine = type_machine;
    proprietaire = txt_proprio;
    serieMachine = txt_machine;
    serieTete = txt_tete;
    updateFields();
    connect(ui->effacerButton,SIGNAL(clicked()),this,SLOT(effacer()));
}

machineSelector::~machineSelector()
{
    delete ui;
}

int machineSelector::get_type_machine()
{
    qDebug()<<"Appel proprio";
    machine = ui->machineGroup->checkedId();
    return machine;
}

QString machineSelector::get_proprio()
{
    qDebug()<<"Appel proprio";
    proprietaire = ui->proprioEdit->text();
    return proprietaire;
}

QString machineSelector::get_serie_machine()
{
    qDebug()<<"Appel serie_machine";
    serieMachine = ui->machineEdit->text();
    return serieMachine;
}

QString machineSelector::get_serie_tete()
{
    qDebug()<<"Appel serie_tete";
    serieTete = ui->teteEdit->text();
    return serieTete;
}

void machineSelector::updateFields()
{
    ui->machineGroup->button(machine)->setChecked(true);
    ui->proprioEdit->setText(proprietaire);
    ui->machineEdit->setText(serieMachine);
    ui->teteEdit->setText(serieTete);
}

void machineSelector::effacer()
{
    machine = 0;
    proprietaire="";
    serieMachine="";
    serieTete="";
    updateFields();
}

