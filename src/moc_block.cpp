/****************************************************************************
** Meta object code from reading C++ file 'block.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "model/block.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'block.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Block_t {
    QByteArrayData data[14];
    char stringdata[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Block_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Block_t qt_meta_stringdata_Block = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 10),
QT_MOC_LITERAL(2, 17, 0),
QT_MOC_LITERAL(3, 18, 6),
QT_MOC_LITERAL(4, 25, 11),
QT_MOC_LITERAL(5, 37, 7),
QT_MOC_LITERAL(6, 45, 15),
QT_MOC_LITERAL(7, 61, 9),
QT_MOC_LITERAL(8, 71, 4),
QT_MOC_LITERAL(9, 76, 5),
QT_MOC_LITERAL(10, 82, 17),
QT_MOC_LITERAL(11, 100, 20),
QT_MOC_LITERAL(12, 121, 18),
QT_MOC_LITERAL(13, 140, 14)
    },
    "Block\0onReadDone\0\0Block*\0onWriteDone\0"
    "onError\0request_error_t\0errorCode\0"
    "read\0write\0onMachineReadDone\0"
    "BlockRequestMachine*\0onMachineWriteDone\0"
    "onMachineError\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Block[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06,
       4,    1,   59,    2, 0x06,
       5,    2,   62,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       8,    0,   67,    2, 0x0a,
       9,    1,   68,    2, 0x0a,
      10,    1,   71,    2, 0x08,
      12,    1,   74,    2, 0x08,
      13,    2,   77,    2, 0x08,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray,    2,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 6,    2,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 6,    2,    7,

       0        // eod
};

void Block::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Block *_t = static_cast<Block *>(_o);
        switch (_id) {
        case 0: _t->onReadDone((*reinterpret_cast< Block*(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 1: _t->onWriteDone((*reinterpret_cast< Block*(*)>(_a[1]))); break;
        case 2: _t->onError((*reinterpret_cast< Block*(*)>(_a[1])),(*reinterpret_cast< request_error_t(*)>(_a[2]))); break;
        case 3: _t->read(); break;
        case 4: _t->write((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: _t->onMachineReadDone((*reinterpret_cast< BlockRequestMachine*(*)>(_a[1]))); break;
        case 6: _t->onMachineWriteDone((*reinterpret_cast< BlockRequestMachine*(*)>(_a[1]))); break;
        case 7: _t->onMachineError((*reinterpret_cast< BlockRequestMachine*(*)>(_a[1])),(*reinterpret_cast< request_error_t(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Block* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Block* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Block* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< BlockRequestMachine* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< BlockRequestMachine* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< BlockRequestMachine* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Block::*_t)(Block * , QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Block::onReadDone)) {
                *result = 0;
            }
        }
        {
            typedef void (Block::*_t)(Block * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Block::onWriteDone)) {
                *result = 1;
            }
        }
        {
            typedef void (Block::*_t)(Block * , request_error_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Block::onError)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject Block::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Block.data,
      qt_meta_data_Block,  qt_static_metacall, 0, 0}
};


const QMetaObject *Block::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Block::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Block.stringdata))
        return static_cast<void*>(const_cast< Block*>(this));
    return QObject::qt_metacast(_clname);
}

int Block::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Block::onReadDone(Block * _t1, QByteArray _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Block::onWriteDone(Block * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Block::onError(Block * _t1, request_error_t _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
