/****************************************************************************
** Meta object code from reading C++ file 'scanner_window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "view/scanner_window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scanner_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ScannerWindow_t {
    QByteArrayData data[13];
    char stringdata[195];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ScannerWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ScannerWindow_t qt_meta_stringdata_ScannerWindow = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 11),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 2),
QT_MOC_LITERAL(4, 30, 10),
QT_MOC_LITERAL(5, 41, 9),
QT_MOC_LITERAL(6, 51, 36),
QT_MOC_LITERAL(7, 88, 5),
QT_MOC_LITERAL(8, 94, 21),
QT_MOC_LITERAL(9, 116, 18),
QT_MOC_LITERAL(10, 135, 32),
QT_MOC_LITERAL(11, 168, 20),
QT_MOC_LITERAL(12, 189, 4)
    },
    "ScannerWindow\0onCardFound\0\0IP\0onScanDone\0"
    "connectTo\0on_cmbInterfaces_currentIndexChanged\0"
    "index\0on_btnConnect_clicked\0"
    "on_btnScan_clicked\0on_lstCards_itemSelectionChanged\0"
    "on_txtIP_textChanged\0arg1\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScannerWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x08,
       4,    0,   57,    2, 0x08,
       5,    1,   58,    2, 0x08,
       6,    1,   61,    2, 0x08,
       8,    0,   64,    2, 0x08,
       9,    0,   65,    2, 0x08,
      10,    0,   66,    2, 0x08,
      11,    1,   67,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,

       0        // eod
};

void ScannerWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScannerWindow *_t = static_cast<ScannerWindow *>(_o);
        switch (_id) {
        case 0: _t->onCardFound((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->onScanDone(); break;
        case 2: _t->connectTo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->on_cmbInterfaces_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_btnConnect_clicked(); break;
        case 5: _t->on_btnScan_clicked(); break;
        case 6: _t->on_lstCards_itemSelectionChanged(); break;
        case 7: _t->on_txtIP_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ScannerWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ScannerWindow.data,
      qt_meta_data_ScannerWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *ScannerWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScannerWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ScannerWindow.stringdata))
        return static_cast<void*>(const_cast< ScannerWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int ScannerWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
