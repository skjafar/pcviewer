/****************************************************************************
** Meta object code from reading C++ file 'plotter_window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "view/plotter_window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plotter_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WaveformGraph_t {
    QByteArrayData data[4];
    char stringdata[40];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_WaveformGraph_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_WaveformGraph_t qt_meta_stringdata_WaveformGraph = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 14),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 8)
    },
    "WaveformGraph\0onGraphUpdated\0\0addPoint\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WaveformGraph[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    0,   25,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void WaveformGraph::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WaveformGraph *_t = static_cast<WaveformGraph *>(_o);
        switch (_id) {
        case 0: _t->onGraphUpdated(); break;
        case 1: _t->addPoint(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WaveformGraph::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WaveformGraph::onGraphUpdated)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject WaveformGraph::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WaveformGraph.data,
      qt_meta_data_WaveformGraph,  qt_static_metacall, 0, 0}
};


const QMetaObject *WaveformGraph::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WaveformGraph::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WaveformGraph.stringdata))
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
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void WaveformGraph::onGraphUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
struct qt_meta_stringdata_PlotterWindow_t {
    QByteArrayData data[14];
    char stringdata[212];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_PlotterWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_PlotterWindow_t qt_meta_stringdata_PlotterWindow = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 8),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 9),
QT_MOC_LITERAL(4, 34, 9),
QT_MOC_LITERAL(5, 44, 11),
QT_MOC_LITERAL(6, 56, 16),
QT_MOC_LITERAL(7, 73, 14),
QT_MOC_LITERAL(8, 88, 20),
QT_MOC_LITERAL(9, 109, 7),
QT_MOC_LITERAL(10, 117, 19),
QT_MOC_LITERAL(11, 137, 22),
QT_MOC_LITERAL(12, 160, 21),
QT_MOC_LITERAL(13, 182, 28)
    },
    "PlotterWindow\0addGraph\0\0Register*\0"
    "register_\0removeGraph\0manualUpdateAxis\0"
    "onGraphUpdated\0on_optManual_toggled\0"
    "checked\0on_btnPause_toggled\0"
    "on_btnSaveData_clicked\0on_btnSavePNG_clicked\0"
    "on_txtTimeSpan_returnPressed\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlotterWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x0a,
       5,    1,   72,    2, 0x0a,
       1,    0,   75,    2, 0x08,
       5,    0,   76,    2, 0x08,
       6,    0,   77,    2, 0x08,
       7,    0,   78,    2, 0x08,
       8,    1,   79,    2, 0x08,
      10,    1,   82,    2, 0x08,
      11,    0,   85,    2, 0x08,
      12,    0,   86,    2, 0x08,
      13,    0,   87,    2, 0x08,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PlotterWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlotterWindow *_t = static_cast<PlotterWindow *>(_o);
        switch (_id) {
        case 0: _t->addGraph((*reinterpret_cast< Register*(*)>(_a[1]))); break;
        case 1: _t->removeGraph((*reinterpret_cast< Register*(*)>(_a[1]))); break;
        case 2: _t->addGraph(); break;
        case 3: _t->removeGraph(); break;
        case 4: _t->manualUpdateAxis(); break;
        case 5: _t->onGraphUpdated(); break;
        case 6: _t->on_optManual_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_btnPause_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_btnSaveData_clicked(); break;
        case 9: _t->on_btnSavePNG_clicked(); break;
        case 10: _t->on_txtTimeSpan_returnPressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Register* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Register* >(); break;
            }
            break;
        }
    }
}

const QMetaObject PlotterWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_PlotterWindow.data,
      qt_meta_data_PlotterWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *PlotterWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlotterWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PlotterWindow.stringdata))
        return static_cast<void*>(const_cast< PlotterWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int PlotterWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
