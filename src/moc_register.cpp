/****************************************************************************
** Meta object code from reading C++ file 'register.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "model/register.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'register.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Register_t {
    QByteArrayData data[16];
    char stringdata[157];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Register_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Register_t qt_meta_stringdata_Register = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 8),
QT_MOC_LITERAL(2, 18, 0),
QT_MOC_LITERAL(3, 19, 11),
QT_MOC_LITERAL(4, 31, 11),
QT_MOC_LITERAL(5, 43, 15),
QT_MOC_LITERAL(6, 59, 9),
QT_MOC_LITERAL(7, 69, 12),
QT_MOC_LITERAL(8, 82, 7),
QT_MOC_LITERAL(9, 90, 4),
QT_MOC_LITERAL(10, 95, 5),
QT_MOC_LITERAL(11, 101, 7),
QT_MOC_LITERAL(12, 109, 5),
QT_MOC_LITERAL(13, 115, 8),
QT_MOC_LITERAL(14, 124, 16),
QT_MOC_LITERAL(15, 141, 14)
    },
    "Register\0onChange\0\0onReadReply\0"
    "onReadError\0request_error_t\0errorCode\0"
    "onWriteError\0onError\0read\0write\0int32_t\0"
    "value\0uint32_t\0RegisterRequest*\0"
    "onHandlingDone\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Register[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06,
       3,    0,   80,    2, 0x06,
       4,    1,   81,    2, 0x06,
       7,    1,   84,    2, 0x06,
       8,    1,   87,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       9,    0,   90,    2, 0x0a,
      10,    1,   91,    2, 0x0a,
      10,    1,   94,    2, 0x0a,
      10,    1,   97,    2, 0x0a,
       3,    1,  100,    2, 0x08,
       4,    2,  103,    2, 0x08,
       7,    2,  108,    2, 0x08,
      15,    1,  113,    2, 0x08,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 13,   12,
    QMetaType::Void, QMetaType::Float,   12,
    QMetaType::Void, 0x80000000 | 14,    2,
    QMetaType::Void, 0x80000000 | 14, 0x80000000 | 5,    2,    2,
    QMetaType::Void, 0x80000000 | 14, 0x80000000 | 5,    2,    2,
    QMetaType::Void, 0x80000000 | 14,    2,

       0        // eod
};

void Register::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Register *_t = static_cast<Register *>(_o);
        switch (_id) {
        case 0: _t->onChange(); break;
        case 1: _t->onReadReply(); break;
        case 2: _t->onReadError((*reinterpret_cast< request_error_t(*)>(_a[1]))); break;
        case 3: _t->onWriteError((*reinterpret_cast< request_error_t(*)>(_a[1]))); break;
        case 4: _t->onError((*reinterpret_cast< request_error_t(*)>(_a[1]))); break;
        case 5: _t->read(); break;
        case 6: _t->write((*reinterpret_cast< int32_t(*)>(_a[1]))); break;
        case 7: _t->write((*reinterpret_cast< uint32_t(*)>(_a[1]))); break;
        case 8: _t->write((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 9: _t->onReadReply((*reinterpret_cast< RegisterRequest*(*)>(_a[1]))); break;
        case 10: _t->onReadError((*reinterpret_cast< RegisterRequest*(*)>(_a[1])),(*reinterpret_cast< request_error_t(*)>(_a[2]))); break;
        case 11: _t->onWriteError((*reinterpret_cast< RegisterRequest*(*)>(_a[1])),(*reinterpret_cast< request_error_t(*)>(_a[2]))); break;
        case 12: _t->onHandlingDone((*reinterpret_cast< RegisterRequest*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< RegisterRequest* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< RegisterRequest* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< RegisterRequest* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< RegisterRequest* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Register::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Register::onChange)) {
                *result = 0;
            }
        }
        {
            typedef void (Register::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Register::onReadReply)) {
                *result = 1;
            }
        }
        {
            typedef void (Register::*_t)(request_error_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Register::onReadError)) {
                *result = 2;
            }
        }
        {
            typedef void (Register::*_t)(request_error_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Register::onWriteError)) {
                *result = 3;
            }
        }
        {
            typedef void (Register::*_t)(request_error_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Register::onError)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject Register::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Register.data,
      qt_meta_data_Register,  qt_static_metacall, 0, 0}
};


const QMetaObject *Register::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Register::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Register.stringdata))
        return static_cast<void*>(const_cast< Register*>(this));
    return QObject::qt_metacast(_clname);
}

int Register::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Register::onChange()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Register::onReadReply()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Register::onReadError(request_error_t _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Register::onWriteError(request_error_t _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Register::onError(request_error_t _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
