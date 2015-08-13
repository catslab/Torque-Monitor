/********************************************************************************
** Form generated from reading UI file 'torque.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TORQUE_H
#define UI_TORQUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Torque
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *localAdapterBox;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *firstAdapter;
    QRadioButton *secondAdapter;
    QHBoxLayout *horizontalLayout_4;
    QLCDNumber *torque_val;
    QTextEdit *chat;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLabel *battLabel;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *zeroButton;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_6;
    QLabel *pressLbl;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_8;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *quitButton;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *connectButton;

    void setupUi(QDialog *Torque)
    {
        if (Torque->objectName().isEmpty())
            Torque->setObjectName(QStringLiteral("Torque"));
        Torque->resize(800, 600);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Light, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        QBrush brush2(QColor(104, 106, 107, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        QBrush brush3(QColor(127, 127, 127, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        QBrush brush4(QColor(148, 148, 148, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        Torque->setPalette(palette);
        verticalLayout = new QVBoxLayout(Torque);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        localAdapterBox = new QGroupBox(Torque);
        localAdapterBox->setObjectName(QStringLiteral("localAdapterBox"));
        localAdapterBox->setEnabled(true);
        localAdapterBox->setCheckable(false);
        horizontalLayout_3 = new QHBoxLayout(localAdapterBox);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        firstAdapter = new QRadioButton(localAdapterBox);
        firstAdapter->setObjectName(QStringLiteral("firstAdapter"));

        horizontalLayout_3->addWidget(firstAdapter);

        secondAdapter = new QRadioButton(localAdapterBox);
        secondAdapter->setObjectName(QStringLiteral("secondAdapter"));

        horizontalLayout_3->addWidget(secondAdapter);


        verticalLayout->addWidget(localAdapterBox);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        torque_val = new QLCDNumber(Torque);
        torque_val->setObjectName(QStringLiteral("torque_val"));
        QFont font;
        font.setPointSize(20);
        font.setBold(false);
        font.setWeight(50);
        font.setKerning(true);
        torque_val->setFont(font);
        torque_val->setFrameShape(QFrame::NoFrame);
        torque_val->setFrameShadow(QFrame::Plain);
        torque_val->setSmallDecimalPoint(false);
        torque_val->setSegmentStyle(QLCDNumber::Filled);

        horizontalLayout_4->addWidget(torque_val);


        verticalLayout->addLayout(horizontalLayout_4);

        chat = new QTextEdit(Torque);
        chat->setObjectName(QStringLiteral("chat"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(chat->sizePolicy().hasHeightForWidth());
        chat->setSizePolicy(sizePolicy);
        chat->setMaximumSize(QSize(16777215, 50));
        chat->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(chat);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label = new QLabel(Torque);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_5->addWidget(label);

        battLabel = new QLabel(Torque);
        battLabel->setObjectName(QStringLiteral("battLabel"));

        horizontalLayout_5->addWidget(battLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        zeroButton = new QPushButton(Torque);
        zeroButton->setObjectName(QStringLiteral("zeroButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(zeroButton->sizePolicy().hasHeightForWidth());
        zeroButton->setSizePolicy(sizePolicy1);
        zeroButton->setMaximumSize(QSize(200, 50));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        zeroButton->setFont(font1);

        horizontalLayout_5->addWidget(zeroButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        pushButton_6 = new QPushButton(Torque);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        horizontalLayout->addWidget(pushButton_6);

        pressLbl = new QLabel(Torque);
        pressLbl->setObjectName(QStringLiteral("pressLbl"));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        pressLbl->setFont(font2);

        horizontalLayout->addWidget(pressLbl);

        pushButton = new QPushButton(Torque);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);

        pushButton_8 = new QPushButton(Torque);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(0, 50));
        QFont font3;
        font3.setPointSize(16);
        font3.setBold(true);
        font3.setWeight(75);
        pushButton_8->setFont(font3);

        horizontalLayout_6->addWidget(pushButton_8);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        quitButton = new QPushButton(Torque);
        quitButton->setObjectName(QStringLiteral("quitButton"));

        horizontalLayout_2->addWidget(quitButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        connectButton = new QPushButton(Torque);
        connectButton->setObjectName(QStringLiteral("connectButton"));

        horizontalLayout_2->addWidget(connectButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Torque);

        QMetaObject::connectSlotsByName(Torque);
    } // setupUi

    void retranslateUi(QDialog *Torque)
    {
        Torque->setWindowTitle(QApplication::translate("Torque", "Torque Monitor", 0));
        localAdapterBox->setTitle(QApplication::translate("Torque", "Dongle bluetooth local", 0));
        firstAdapter->setText(QApplication::translate("Torque", "Default", 0));
        secondAdapter->setText(QString());
        label->setText(QApplication::translate("Torque", "Batt:", 0));
        battLabel->setText(QApplication::translate("Torque", "0.00V", 0));
        zeroButton->setText(QApplication::translate("Torque", "ZERO", 0));
        pushButton_6->setText(QApplication::translate("Torque", "<-", 0));
        pressLbl->setText(QApplication::translate("Torque", "Pression", 0));
        pushButton->setText(QApplication::translate("Torque", "->", 0));
        pushButton_8->setText(QApplication::translate("Torque", "Enregistrer", 0));
        quitButton->setText(QApplication::translate("Torque", "Quitter", 0));
        connectButton->setText(QApplication::translate("Torque", "Connecter", 0));
    } // retranslateUi

};

namespace Ui {
    class Torque: public Ui_Torque {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TORQUE_H
