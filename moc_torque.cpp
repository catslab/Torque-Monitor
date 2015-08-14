/****************************************************************************
** Meta object code from reading C++ file 'torque.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "torque.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'torque.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Torque_t {
    QByteArrayData data[15];
    char stringdata0[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Torque_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Torque_t qt_meta_stringdata_Torque = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Torque"
QT_MOC_LITERAL(1, 7, 11), // "sendMessage"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 7), // "message"
QT_MOC_LITERAL(4, 28, 14), // "connectClicked"
QT_MOC_LITERAL(5, 43, 11), // "zeroClicked"
QT_MOC_LITERAL(6, 55, 11), // "showMessage"
QT_MOC_LITERAL(7, 67, 6), // "sender"
QT_MOC_LITERAL(8, 74, 14), // "showRawMessage"
QT_MOC_LITERAL(9, 89, 5), // "bytes"
QT_MOC_LITERAL(10, 95, 18), // "clientDisconnected"
QT_MOC_LITERAL(11, 114, 9), // "connected"
QT_MOC_LITERAL(12, 124, 4), // "name"
QT_MOC_LITERAL(13, 129, 18), // "newAdapterSelected"
QT_MOC_LITERAL(14, 148, 10) // "createMenu"

    },
    "Torque\0sendMessage\0\0message\0connectClicked\0"
    "zeroClicked\0showMessage\0sender\0"
    "showRawMessage\0bytes\0clientDisconnected\0"
    "connected\0name\0newAdapterSelected\0"
    "createMenu"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Torque[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   62,    2, 0x08 /* Private */,
       5,    0,   63,    2, 0x08 /* Private */,
       6,    2,   64,    2, 0x08 /* Private */,
       8,    1,   69,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    1,   73,    2, 0x08 /* Private */,
      13,    0,   76,    2, 0x08 /* Private */,
      14,    0,   77,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    7,    3,
    QMetaType::Void, QMetaType::QByteArray,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Torque::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Torque *_t = static_cast<Torque *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->connectClicked(); break;
        case 2: _t->zeroClicked(); break;
        case 3: _t->showMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->showRawMessage((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 5: _t->clientDisconnected(); break;
        case 6: _t->connected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->newAdapterSelected(); break;
        case 8: _t->createMenu(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Torque::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Torque::sendMessage)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject Torque::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Torque.data,
      qt_meta_data_Torque,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Torque::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Torque::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Torque.stringdata0))
        return static_cast<void*>(const_cast< Torque*>(this));
    return QDialog::qt_metacast(_clname);
}

int Torque::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Torque::sendMessage(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
