TEMPLATE = app
TARGET = torque

QT = core bluetooth widgets

SOURCES = \
    main.cpp \
    torque.cpp \
    remoteselector.cpp \
    torqueclient.cpp

HEADERS = \
    torque.h \
    remoteselector.h \
    torqueclient.h

FORMS = \
    torque.ui \
    remoteselector.ui

target.path = $$[home]/Torque Monitor
INSTALLS += target
