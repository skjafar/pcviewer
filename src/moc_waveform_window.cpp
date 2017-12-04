/****************************************************************************
** Meta object code from reading C++ file 'waveform_window.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "view/waveform_window.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'waveform_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WaveformGraph[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      32,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_WaveformGraph[] = {
    "WaveformGraph\0\0onGraphUpdated()\0"
    "addPoint()\0"
};

void WaveformGraph::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        WaveformGraph *_t = static_cast<WaveformGraph *>(_o);
        switch (_id) {
        case 0: _t->onGraphUpdated(); break;
        case 1: _t->addPoint(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData WaveformGraph::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject WaveformGraph::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WaveformGraph,
      qt_meta_data_WaveformGraph, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WaveformGraph::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WaveformGraph::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WaveformGraph::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WaveformGraph))
        return static_cast<void*>(const_cast< WaveformGraph*>(this));
    return QObject::qt_metacast(_clname);
}

int WaveformGraph::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void WaveformGraph::onGraphUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_WaveformWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      26,   16,   15,   15, 0x0a,
      46,   16,   15,   15, 0x0a,
      69,   15,   15,   15, 0x08,
      80,   15,   15,   15, 0x08,
      94,   15,   15,   15, 0x08,
     113,   15,   15,   15, 0x08,
     138,  130,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_WaveformWindow[] = {
    "WaveformWindow\0\0register_\0addGraph(Register*)\0"
    "removeGraph(Register*)\0addGraph()\0"
    "removeGraph()\0manualUpdateAxis()\0"
    "onGraphUpdated()\0checked\0"
    "on_optManual_toggled(bool)\0"
};

void WaveformWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        WaveformWindow *_t = static_cast<WaveformWindow *>(_o);
        switch (_id) {
        case 0: _t->addGraph((*reinterpret_cast< Register*(*)>(_a[1]))); break;
        case 1: _t->removeGraph((*reinterpret_cast< Register*(*)>(_a[1]))); break;
        case 2: _t->addGraph(); break;
        case 3: _t->removeGraph(); break;
        case 4: _t->manualUpdateAxis(); break;
        case 5: _t->onGraphUpdated(); break;
        case 6: _t->on_optManual_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData WaveformWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject WaveformWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_WaveformWindow,
      qt_meta_data_WaveformWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WaveformWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WaveformWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WaveformWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WaveformWindow))
        return static_cast<void*>(const_cast< WaveformWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int WaveformWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
