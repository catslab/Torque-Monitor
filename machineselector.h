#ifndef MACHINESELECTOR_H
#define MACHINESELECTOR_H

#include <QDialog>

namespace Ui {
class machineSelector;
}

class machineSelector : public QDialog
{
    Q_OBJECT

public:
    explicit machineSelector(QString txt_proprio, QString txt_tete, QString txt_machine, int type_machine, QWidget *parent = 0);
    ~machineSelector();

    int get_type_machine();
    QString get_proprio();
    QString get_serie_machine();
    QString get_serie_tete();

private slots:
    void effacer();
    void fichier();

private:
    Ui::machineSelector *ui;

    int machine;
    QString serieMachine;
    QString serieTete;
    QString proprietaire;
    void updateFields();


};

#endif // MACHINESELECTOR_H
