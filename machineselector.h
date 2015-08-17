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
    int machine =0;

    QString proprio();
    QString serie_machine();
    QString serie_tete();

private:
    Ui::machineSelector *ui;
    QString serieMachine;
    QString serieTete;
    QString proprietaire;
};

#endif // MACHINESELECTOR_H
