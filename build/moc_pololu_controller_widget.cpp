/****************************************************************************
** Meta object code from reading C++ file 'pololu_controller_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pololu_controller_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pololu_controller_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PololuControllerWidget_t {
    QByteArrayData data[17];
    char stringdata[446];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_PololuControllerWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_PololuControllerWidget_t qt_meta_stringdata_PololuControllerWidget = {
    {
QT_MOC_LITERAL(0, 0, 22),
QT_MOC_LITERAL(1, 23, 26),
QT_MOC_LITERAL(2, 50, 0),
QT_MOC_LITERAL(3, 51, 27),
QT_MOC_LITERAL(4, 79, 30),
QT_MOC_LITERAL(5, 110, 5),
QT_MOC_LITERAL(6, 116, 30),
QT_MOC_LITERAL(7, 147, 30),
QT_MOC_LITERAL(8, 178, 30),
QT_MOC_LITERAL(9, 209, 30),
QT_MOC_LITERAL(10, 240, 30),
QT_MOC_LITERAL(11, 271, 28),
QT_MOC_LITERAL(12, 300, 28),
QT_MOC_LITERAL(13, 329, 28),
QT_MOC_LITERAL(14, 358, 28),
QT_MOC_LITERAL(15, 387, 28),
QT_MOC_LITERAL(16, 416, 28)
    },
    "PololuControllerWidget\0"
    "on_pushButton_Open_clicked\0\0"
    "on_pushButton_Close_clicked\0"
    "on_spinBox_Servo0_valueChanged\0value\0"
    "on_spinBox_Servo1_valueChanged\0"
    "on_spinBox_Servo2_valueChanged\0"
    "on_spinBox_Servo3_valueChanged\0"
    "on_spinBox_Servo4_valueChanged\0"
    "on_spinBox_Servo5_valueChanged\0"
    "on_pushButton_Servo0_clicked\0"
    "on_pushButton_Servo1_clicked\0"
    "on_pushButton_Servo2_clicked\0"
    "on_pushButton_Servo3_clicked\0"
    "on_pushButton_Servo4_clicked\0"
    "on_pushButton_Servo5_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PololuControllerWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08,
       3,    0,   85,    2, 0x08,
       4,    1,   86,    2, 0x08,
       6,    1,   89,    2, 0x08,
       7,    1,   92,    2, 0x08,
       8,    1,   95,    2, 0x08,
       9,    1,   98,    2, 0x08,
      10,    1,  101,    2, 0x08,
      11,    0,  104,    2, 0x08,
      12,    0,  105,    2, 0x08,
      13,    0,  106,    2, 0x08,
      14,    0,  107,    2, 0x08,
      15,    0,  108,    2, 0x08,
      16,    0,  109,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PololuControllerWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PololuControllerWidget *_t = static_cast<PololuControllerWidget *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_Open_clicked(); break;
        case 1: _t->on_pushButton_Close_clicked(); break;
        case 2: _t->on_spinBox_Servo0_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_spinBox_Servo1_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_spinBox_Servo2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_spinBox_Servo3_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_spinBox_Servo4_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_spinBox_Servo5_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_pushButton_Servo0_clicked(); break;
        case 9: _t->on_pushButton_Servo1_clicked(); break;
        case 10: _t->on_pushButton_Servo2_clicked(); break;
        case 11: _t->on_pushButton_Servo3_clicked(); break;
        case 12: _t->on_pushButton_Servo4_clicked(); break;
        case 13: _t->on_pushButton_Servo5_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject PololuControllerWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PololuControllerWidget.data,
      qt_meta_data_PololuControllerWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *PololuControllerWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PololuControllerWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PololuControllerWidget.stringdata))
        return static_cast<void*>(const_cast< PololuControllerWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int PololuControllerWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
