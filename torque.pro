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
    remoteselector.ui \
    machineselector.ui \
    torque-old.ui \
    torque.ui

target.path = $$[home]/Torque Monitor
INSTALLS += target
