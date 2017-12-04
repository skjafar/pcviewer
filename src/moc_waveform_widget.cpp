/****************************************************************************
** Meta object code from reading C++ file 'waveform_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "view/waveform_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'waveform_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WaveformWidget_t {
    QByteArrayData data[22];
    char stringdata[277];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_WaveformWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_WaveformWidget_t qt_meta_stringdata_WaveformWidget = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 12),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 14),
QT_MOC_LITERAL(4, 44, 12),
QT_MOC_LITERAL(5, 57, 13),
QT_MOC_LITERAL(6, 71, 10),
QT_MOC_LITERAL(7, 82, 12),
QT_MOC_LITERAL(8, 95, 10),
QT_MOC_LITERAL(9, 106, 11),
QT_MOC_LITERAL(10, 118, 12),
QT_MOC_LITERAL(11, 131, 6),
QT_MOC_LITERAL(12, 138, 5),
QT_MOC_LITERAL(13, 144, 4),
QT_MOC_LITERAL(14, 149, 12),
QT_MOC_LITERAL(15, 162, 16),
QT_MOC_LITERAL(16, 179, 13),
QT_MOC_LITERAL(17, 193, 15),
QT_MOC_LITERAL(18, 209, 7),
QT_MOC_LITERAL(19, 217, 18),
QT_MOC_LITERAL(20, 236, 18),
QT_MOC_LITERAL(21, 255, 20)
    },
    "WaveformWidget\0onSizeChange\0\0"
    "onPeriodChange\0onGainChange\0onDelayChange\0"
    "changeSize\0changePeriod\0changeGain\0"
    "changeDelay\0plotWaveform\0Block*\0block\0"
    "data\0saveWaveform\0waveformUploaded\0"
    "waveformError\0request_error_t\0errCode\0"
    "on_btnPlot_clicked\0on_btnSave_clicked\0"
    "on_btnUpload_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WaveformWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08,
       3,    0,   90,    2, 0x08,
       4,    0,   91,    2, 0x08,
       5,    0,   92,    2, 0x08,
       6,    0,   93,    2, 0x08,
       7,    0,   94,    2, 0x08,
       8,    0,   95,    2, 0x08,
       9,    0,   96,    2, 0x08,
      10,    2,   97,    2, 0x08,
      14,    2,  102,    2, 0x08,
      15,    1,  107,    2, 0x08,
      16,    2,  110,    2, 0x08,
      19,    0,  115,    2, 0x08,
      20,    0,  116,    2, 0x08,
      21,    0,  117,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11, QMetaType::QByteArray,   12,   13,
    QMetaType::Void, 0x80000000 | 11, QMetaType::QByteArray,   12,   13,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 17,   12,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WaveformWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WaveformWidget *_t = static_cast<WaveformWidget *>(_o);
        switch (_id) {
        case 0: _t->onSizeChange(); break;
        case 1: _t->onPeriodChange(); break;
        case 2: _t->onGainChange(); break;
        case 3: _t->onDelayChange(); break;
        case 4: _t->changeSize(); break;
        case 5: _t->changePeriod(); break;
        case 6: _t->changeGain(); break;
        case 7: _t->changeDelay(); break;
        case 8: _t->plotWaveform((*reinterpret_cast< Block*(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 9: _t->saveWaveform((*reinterpret_cast< Block*(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 10: _t->waveformUploaded((*reinterpret_cast< Block*(*)>(_a[1]))); break;
        case 11: _t->waveformError((*reinterpret_cast< Block*(*)>(_a[1])),(*reinterpret_cast< request_error_t(*)>(_a[2]))); break;
        case 12: _t->on_btnPlot_clicked(); break;
        case 13: _t->on_btnSave_clicked(); break;
        case 14: _t->on_btnUpload_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Block* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Block* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Block* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Block* >(); break;
            }
            break;
        }
    }
}

const QMetaObject WaveformWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WaveformWidget.data,
      qt_meta_data_WaveformWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *WaveformWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WaveformWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WaveformWidget.stringdata))
        return static_cast<void*>(const_cast< WaveformWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int WaveformWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
