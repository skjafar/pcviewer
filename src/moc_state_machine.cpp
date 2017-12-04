/****************************************************************************
** Meta object code from reading C++ file 'state_machine.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "model/state_machine.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'state_machine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StateMachine[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      33,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      49,   43,   13,   13, 0x0a,
      82,   13,   13,   13, 0x0a,
     100,   13,   13,   13, 0x08,
     131,   13,   13,   13, 0x08,
     174,  164,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_StateMachine[] = {
    "StateMachine\0\0afterStateChange()\0"
    "onError()\0state\0setState(global_state_machine_t)\0"
    "resetInterlocks()\0onStateMachineRegisterChange()\0"
    "onSequencerStateRegisterChange()\0"
    "errorCode\0onError(request_error_t)\0"
};

void StateMachine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        StateMachine *_t = static_cast<StateMachine *>(_o);
        switch (_id) {
        case 0: _t->afterStateChange(); break;
        case 1: _t->onError(); break;
        case 2: _t->setState((*reinterpret_cast< global_state_machine_t(*)>(_a[1]))); break;
        case 3: _t->resetInterlocks(); break;
        case 4: _t->onStateMachineRegisterChange(); break;
        case 5: _t->onSequencerStateRegisterChange(); break;
        case 6: _t->onError((*reinterpret_cast< request_error_t(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData StateMachine::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject StateMachine::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_StateMachine,
      qt_meta_data_StateMachine, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StateMachine::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StateMachine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StateMachine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StateMachine))
        return static_cast<void*>(const_cast< StateMachine*>(this));
    return QObject::qt_metacast(_clname);
}

int StateMachine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void StateMachine::afterStateChange()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void StateMachine::onError()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
