/****************************************************************************
** Meta object code from reading C++ file 'register_request.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "model/register_request.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'register_request.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RegisterRequest_t {
    QByteArrayData data[16];
    char stringdata[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_RegisterRequest_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_RegisterRequest_t qt_meta_stringdata_RegisterRequest = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 7),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 16),
QT_MOC_LITERAL(4, 42, 7),
QT_MOC_LITERAL(5, 50, 10),
QT_MOC_LITERAL(6, 61, 11),
QT_MOC_LITERAL(7, 73, 7),
QT_MOC_LITERAL(8, 81, 15),
QT_MOC_LITERAL(9, 97, 9),
QT_MOC_LITERAL(10, 107, 14),
QT_MOC_LITERAL(11, 122, 9),
QT_MOC_LITERAL(12, 132, 7),
QT_MOC_LITERAL(13, 140, 8),
QT_MOC_LITERAL(14, 149, 5),
QT_MOC_LITERAL(15, 155, 7)
    },
    "RegisterRequest\0onReply\0\0RegisterRequest*\0"
    "request\0onReadDone\0onWriteDone\0onError\0"
    "request_error_t\0errorCode\0onHandlingDone\0"
    "onTimeout\0setData\0uint32_t\0value\0"
    "int32_t\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RegisterRequest[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06,
       5,    1,   62,    2, 0x06,
       6,    1,   65,    2, 0x06,
       7,    2,   68,    2, 0x06,
      10,    1,   73,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      11,    0,   76,    2, 0x0a,
      12,    1,   77,    2, 0x0a,
      12,    1,   80,    2, 0x0a,
      12,    1,   83,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 8,    4,    9,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 15,   14,
    QMetaType::Void, QMetaType::Float,   14,

       0        // eod
};

void RegisterRequest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RegisterRequest *_t = static_cast<RegisterRequest *>(_o);
        switch (_id) {
        case 0: _t->onReply((*reinterpret_cast< RegisterRequest*(*)>(_a[1]))); break;
        case 1: _t->onReadDone((*reinterpret_cast< RegisterRequest*(*)>(_a[1]))); break;
        case 2: _t->onWriteDone((*reinterpret_cast< RegisterRequest*(*)>(_a[1]))); break;
        case 3: _t->onError((*reinterpret_cast< RegisterRequest*(*)>(_a[1])),(*reinterpret_cast< request_error_t(*)>(_a[2]))); break;
        case 4: _t->onHandlingDone((*reinterpret_cast< RegisterRequest*(*)>(_a[1]))); break;
        case 5: _t->onTimeout(); break;
        case 6: _t->setData((*reinterpret_cast< uint32_t(*)>(_a[1]))); break;
        case 7: _t->setData((*reinterpret_cast< int32_t(*)>(_a[1]))); break;
        case 8: _t->setData((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< RegisterRequest* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< RegisterRequest* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< RegisterRequest* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< RegisterRequest* >(); break;
            }
            break;
        case 4:
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
            typedef void (RegisterRequest::*_t)(RegisterRequest * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RegisterRequest::onReply)) {
                *result = 0;
            }
        }
        {
            typedef void (RegisterRequest::*_t)(RegisterRequest * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RegisterRequest::onReadDone)) {
                *result = 1;
            }
        }
        {
            typedef void (RegisterRequest::*_t)(RegisterRequest * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RegisterRequest::onWriteDone)) {
                *result = 2;
            }
        }
        {
            typedef void (RegisterRequest::*_t)(RegisterRequest * , request_error_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RegisterRequest::onError)) {
                *result = 3;
            }
        }
        {
            typedef void (RegisterRequest::*_t)(RegisterRequest * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RegisterRequest::onHandlingDone)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject RegisterRequest::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RegisterRequest.data,
      qt_meta_data_RegisterRequest,  qt_static_metacall, 0, 0}
};


const QMetaObject *RegisterRequest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RegisterRequest::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RegisterRequest.stringdata))
        return static_cast<void*>(const_cast< RegisterRequest*>(this));
    return QObject::qt_metacast(_clname);
}

int RegisterRequest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void RegisterRequest::onReply(RegisterRequest * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RegisterRequest::onReadDone(RegisterRequest * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RegisterRequest::onWriteDone(RegisterRequest * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void RegisterRequest::onError(RegisterRequest * _t1, request_error_t _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void RegisterRequest::onHandlingDone(RegisterRequest * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
