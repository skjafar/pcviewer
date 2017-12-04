/****************************************************************************
** Meta object code from reading C++ file 'write_register_widget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "view/write_register_widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'write_register_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WriteRegisterWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x08,
      39,   20,   20,   20, 0x08,
      60,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_WriteRegisterWidget[] = {
    "WriteRegisterWidget\0\0onWriteError(int)\0"
    "onAddressChange(int)\0onWriteRequest()\0"
};

void WriteRegisterWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        WriteRegisterWidget *_t = static_cast<WriteRegisterWidget *>(_o);
        switch (_id) {
        case 0: _t->onWriteError((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onAddressChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->onWriteRequest(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData WriteRegisterWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject WriteRegisterWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WriteRegisterWidget,
      qt_meta_data_WriteRegisterWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WriteRegisterWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WriteRegisterWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WriteRegisterWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WriteRegisterWidget))
        return static_cast<void*>(const_cast< WriteRegisterWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int WriteRegisterWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
