/****************************************************************************
** Meta object code from reading C++ file 'logger_window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "view/logger_window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logger_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LoggerWindow_t {
    QByteArrayData data[9];
    char stringdata[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_LoggerWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_LoggerWindow_t qt_meta_stringdata_LoggerWindow = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 11),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 10),
QT_MOC_LITERAL(4, 37, 6),
QT_MOC_LITERAL(5, 44, 19),
QT_MOC_LITERAL(6, 64, 18),
QT_MOC_LITERAL(7, 83, 19),
QT_MOC_LITERAL(8, 103, 18)
    },
    "LoggerWindow\0onIndexRead\0\0onDataRead\0"
    "Block*\0loggerStatusChanged\0"
    "on_btnDump_clicked\0on_btnStart_clicked\0"
    "on_btnStop_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoggerWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08,
       3,    2,   45,    2, 0x08,
       5,    0,   50,    2, 0x08,
       6,    0,   51,    2, 0x08,
       7,    0,   52,    2, 0x08,
       8,    0,   53,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::QByteArray,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LoggerWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LoggerWindow *_t = static_cast<LoggerWindow *>(_o);
        switch (_id) {
        case 0: _t->onIndexRead(); break;
        case 1: _t->onDataRead((*reinterpret_cast< Block*(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 2: _t->loggerStatusChanged(); break;
        case 3: _t->on_btnDump_clicked(); break;
        case 4: _t->on_btnStart_clicked(); break;
        case 5: _t->on_btnStop_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Block* >(); break;
            }
            break;
        }
    }
}

const QMetaObject LoggerWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_LoggerWindow.data,
      qt_meta_data_LoggerWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *LoggerWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoggerWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LoggerWindow.stringdata))
        return static_cast<void*>(const_cast< LoggerWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int LoggerWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
