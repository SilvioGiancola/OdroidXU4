/****************************************************************************
** Meta object code from reading C++ file 'adafruit_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../adafruit_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adafruit_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AdafruitWidget_t {
    QByteArrayData data[7];
    char stringdata[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_AdafruitWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_AdafruitWidget_t qt_meta_stringdata_AdafruitWidget = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 26),
QT_MOC_LITERAL(2, 42, 0),
QT_MOC_LITERAL(3, 43, 27),
QT_MOC_LITERAL(4, 71, 32),
QT_MOC_LITERAL(5, 104, 26),
QT_MOC_LITERAL(6, 131, 27)
    },
    "AdafruitWidget\0on_pushButton_Open_clicked\0"
    "\0on_pushButton_Close_clicked\0"
    "on_pushButton_Quaternion_clicked\0"
    "on_pushButton_Init_clicked\0"
    "on_pushButton_Calib_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdafruitWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08,
       3,    0,   40,    2, 0x08,
       4,    0,   41,    2, 0x08,
       5,    0,   42,    2, 0x08,
       6,    0,   43,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AdafruitWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AdafruitWidget *_t = static_cast<AdafruitWidget *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_Open_clicked(); break;
        case 1: _t->on_pushButton_Close_clicked(); break;
        case 2: _t->on_pushButton_Quaternion_clicked(); break;
        case 3: _t->on_pushButton_Init_clicked(); break;
        case 4: _t->on_pushButton_Calib_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject AdafruitWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AdafruitWidget.data,
      qt_meta_data_AdafruitWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *AdafruitWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdafruitWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AdafruitWidget.stringdata))
        return static_cast<void*>(const_cast< AdafruitWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int AdafruitWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
