/****************************************************************************
** Meta object code from reading C++ file 'parameter_set.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "model/parameter_set.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'parameter_set.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ParameterSet_t {
    QByteArrayData data[11];
    char stringdata[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ParameterSet_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ParameterSet_t qt_meta_stringdata_ParameterSet = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 11),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 12),
QT_MOC_LITERAL(4, 39, 8),
QT_MOC_LITERAL(5, 48, 18),
QT_MOC_LITERAL(6, 67, 4),
QT_MOC_LITERAL(7, 72, 10),
QT_MOC_LITERAL(8, 83, 11),
QT_MOC_LITERAL(9, 95, 6),
QT_MOC_LITERAL(10, 102, 5)
    },
    "ParameterSet\0onSetLoaded\0\0loadFromFile\0"
    "filepath\0loadFromBlockArray\0data\0"
    "saveToFile\0saveToBlock\0Block*\0block\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ParameterSet[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    1,   40,    2, 0x0a,
       5,    1,   43,    2, 0x0a,
       7,    1,   46,    2, 0x0a,
       8,    1,   49,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString,    4,
    QMetaType::Bool, QMetaType::QByteArray,    6,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void ParameterSet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ParameterSet *_t = static_cast<ParameterSet *>(_o);
        switch (_id) {
        case 0: _t->onSetLoaded(); break;
        case 1: { bool _r = _t->loadFromFile((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { bool _r = _t->loadFromBlockArray((*reinterpret_cast< const QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: _t->saveToFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->saveToBlock((*reinterpret_cast< Block*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Block* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ParameterSet::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ParameterSet::onSetLoaded)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ParameterSet::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ParameterSet.data,
      qt_meta_data_ParameterSet,  qt_static_metacall, 0, 0}
};


const QMetaObject *ParameterSet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ParameterSet::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ParameterSet.stringdata))
        return static_cast<void*>(const_cast< ParameterSet*>(this));
    return QObject::qt_metacast(_clname);
}

int ParameterSet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ParameterSet::onSetLoaded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
