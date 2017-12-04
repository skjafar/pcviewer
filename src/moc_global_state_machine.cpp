/****************************************************************************
** Meta object code from reading C++ file 'global_state_machine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "model/global_state_machine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'global_state_machine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GlobalStateMachine_t {
    QByteArrayData data[12];
    char stringdata[178];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GlobalStateMachine_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GlobalStateMachine_t qt_meta_stringdata_GlobalStateMachine = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 16),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 7),
QT_MOC_LITERAL(4, 45, 8),
QT_MOC_LITERAL(5, 54, 14),
QT_MOC_LITERAL(6, 69, 5),
QT_MOC_LITERAL(7, 75, 15),
QT_MOC_LITERAL(8, 91, 28),
QT_MOC_LITERAL(9, 120, 30),
QT_MOC_LITERAL(10, 151, 15),
QT_MOC_LITERAL(11, 167, 9)
    },
    "GlobalStateMachine\0afterStateChange\0"
    "\0onError\0setState\0global_state_t\0state\0"
    "resetInterlocks\0onStateMachineRegisterChange\0"
    "onSequencerStateRegisterChange\0"
    "request_error_t\0errorCode\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GlobalStateMachine[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06,
       3,    0,   50,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    1,   51,    2, 0x0a,
       7,    0,   54,    2, 0x0a,
       8,    0,   55,    2, 0x08,
       9,    0,   56,    2, 0x08,
       3,    1,   57,    2, 0x08,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void GlobalStateMachine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GlobalStateMachine *_t = static_cast<GlobalStateMachine *>(_o);
        switch (_id) {
        case 0: _t->afterStateChange(); break;
        case 1: _t->onError(); break;
        case 2: _t->setState((*reinterpret_cast< global_state_t(*)>(_a[1]))); break;
        case 3: _t->resetInterlocks(); break;
        case 4: _t->onStateMachineRegisterChange(); break;
        case 5: _t->onSequencerStateRegisterChange(); break;
        case 6: _t->onError((*reinterpret_cast< request_error_t(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GlobalStateMachine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GlobalStateMachine::afterStateChange)) {
                *result = 0;
            }
        }
        {
            typedef void (GlobalStateMachine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GlobalStateMachine::onError)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject GlobalStateMachine::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GlobalStateMachine.data,
      qt_meta_data_GlobalStateMachine,  qt_static_metacall, 0, 0}
};


const QMetaObject *GlobalStateMachine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GlobalStateMachine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GlobalStateMachine.stringdata))
        return static_cast<void*>(const_cast< GlobalStateMachine*>(this));
    return QObject::qt_metacast(_clname);
}

int GlobalStateMachine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void GlobalStateMachine::afterStateChange()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void GlobalStateMachine::onError()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
