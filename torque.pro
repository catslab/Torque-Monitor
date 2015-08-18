TEMPLATE = app
TARGET = torque

QT = core bluetooth widgets

SOURCES = \
    main.cpp \
    torque.cpp \
    remoteselector.cpp \
    torqueclient.cpp \
    machineselector.cpp

HEADERS = \
    torque.h \
    remoteselector.h \
    torqueclient.h \
    machineselector.h

FORMS = \
    torque.ui \
    remoteselector.ui \
    machineselector.ui \
    dialog.ui

target.path = $$[home]/Torque Monitor
INSTALLS += target
