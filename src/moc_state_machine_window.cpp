/****************************************************************************
** Meta object code from reading C++ file 'state_machine_window.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "view/state_machine_window.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'state_machine_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Waveform[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      27,    9,    9,    9, 0x08,
      44,    9,    9,    9, 0x08,
      63,    9,    9,    9, 0x08,
      81,    9,    9,    9, 0x08,
      99,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Waveform[] = {
    "Waveform\0\0updateSizeText()\0updateGainText()\0"
    "updatePeriodText()\0updateSizeValue()\0"
    "updateGainValue()\0updatePeriodValue()\0"
};

void Waveform::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Waveform *_t = static_cast<Waveform *>(_o);
        switch (_id) {
        case 0: _t->updateSizeText(); break;
        case 1: _t->updateGainText(); break;
        case 2: _t->updatePeriodText(); break;
        case 3: _t->updateSizeValue(); break;
        case 4: _t->updateGainValue(); break;
        case 5: _t->updatePeriodValue(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Waveform::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Waveform::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Waveform,
      qt_meta_data_Waveform, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Waveform::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Waveform::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Waveform::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Waveform))
        return static_cast<void*>(const_cast< Waveform*>(this));
    return QObject::qt_metacast(_clname);
}

int Waveform::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
static const uint qt_meta_data_StateMachineWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x08,
      40,   19,   19,   19, 0x08,
      64,   19,   19,   19, 0x08,
      83,   19,   19,   19, 0x08,
     108,   19,   19,   19, 0x08,
     130,   19,   19,   19, 0x08,
     152,   19,   19,   19, 0x08,
     176,   19,   19,   19, 0x08,
     199,   19,   19,   19, 0x08,
     220,   19,   19,   19, 0x08,
     246,   19,   19,   19, 0x08,
     269,   19,   19,   19, 0x08,
     296,   19,   19,   19, 0x08,
     312,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_StateMachineWindow[] = {
    "StateMachineWindow\0\0on_btnOff_clicked()\0"
    "on_btnStandby_clicked()\0on_btnDC_clicked()\0"
    "on_btnWaveform_clicked()\0on_btnReset_clicked()\0"
    "on_btnPause_clicked()\0on_btnTrigger_clicked()\0"
    "on_btnResume_clicked()\0on_btnStop_clicked()\0"
    "on_btnAutomatic_clicked()\0"
    "on_btnManual_clicked()\0"
    "on_txtIREF_returnPressed()\0onIREFChanged()\0"
    "onStateChanged()\0"
};

void StateMachineWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        StateMachineWindow *_t = static_cast<StateMachineWindow *>(_o);
        switch (_id) {
        case 0: _t->on_btnOff_clicked(); break;
        case 1: _t->on_btnStandby_clicked(); break;
        case 2: _t->on_btnDC_clicked(); break;
        case 3: _t->on_btnWaveform_clicked(); break;
        case 4: _t->on_btnReset_clicked(); break;
        case 5: _t->on_btnPause_clicked(); break;
        case 6: _t->on_btnTrigger_clicked(); break;
        case 7: _t->on_btnResume_clicked(); break;
        case 8: _t->on_btnStop_clicked(); break;
        case 9: _t->on_btnAutomatic_clicked(); break;
        case 10: _t->on_btnManual_clicked(); break;
        case 11: _t->on_txtIREF_returnPressed(); break;
        case 12: _t->onIREFChanged(); break;
        case 13: _t->onStateChanged(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData StateMachineWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject StateMachineWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_StateMachineWindow,
      qt_meta_data_StateMachineWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StateMachineWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StateMachineWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StateMachineWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StateMachineWindow))
        return static_cast<void*>(const_cast< StateMachineWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int StateMachineWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
