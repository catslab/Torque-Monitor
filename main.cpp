/****************************************************************************
**
** Copyright (C) 2015 Cedric Malitte
**
****************************************************************************/

#include "torque.h"

#include <QApplication>
//#include <QtCore/QLoggingCategory>

int main(int argc, char *argv[])
{
    //QLoggingCategory::setFilterRules(QStringLiteral("qt.bluetooth* = true"));
    QApplication app(argc, argv);

    Torque d;
    QObject::connect(&d, SIGNAL(accepted()), &app, SLOT(quit()));

    d.show();

    app.exec();

    return 0;
}

