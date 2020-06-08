/****************************************************************************
** Meta object code from reading C++ file 'changecarsdata.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CarsManageSystem/changecarsdata.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'changecarsdata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChangeCarsData_t {
    QByteArrayData data[11];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChangeCarsData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChangeCarsData_t qt_meta_stringdata_ChangeCarsData = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ChangeCarsData"
QT_MOC_LITERAL(1, 15, 7), // "mainsys"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 11), // "flchangesys"
QT_MOC_LITERAL(4, 36, 11), // "jbchangesys"
QT_MOC_LITERAL(5, 48, 11), // "ddchangesys"
QT_MOC_LITERAL(6, 60, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(7, 84, 19), // "on_flButton_clicked"
QT_MOC_LITERAL(8, 104, 7), // "receive"
QT_MOC_LITERAL(9, 112, 21), // "on_jbButton_2_clicked"
QT_MOC_LITERAL(10, 134, 21) // "on_ddButton_3_clicked"

    },
    "ChangeCarsData\0mainsys\0\0flchangesys\0"
    "jbchangesys\0ddchangesys\0on_pushButton_4_clicked\0"
    "on_flButton_clicked\0receive\0"
    "on_jbButton_2_clicked\0on_ddButton_3_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChangeCarsData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ChangeCarsData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChangeCarsData *_t = static_cast<ChangeCarsData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mainsys(); break;
        case 1: _t->flchangesys(); break;
        case 2: _t->jbchangesys(); break;
        case 3: _t->ddchangesys(); break;
        case 4: _t->on_pushButton_4_clicked(); break;
        case 5: _t->on_flButton_clicked(); break;
        case 6: _t->receive(); break;
        case 7: _t->on_jbButton_2_clicked(); break;
        case 8: _t->on_ddButton_3_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ChangeCarsData::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChangeCarsData::mainsys)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ChangeCarsData::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChangeCarsData::flchangesys)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ChangeCarsData::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChangeCarsData::jbchangesys)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ChangeCarsData::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChangeCarsData::ddchangesys)) {
                *result = 3;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ChangeCarsData::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ChangeCarsData.data,
      qt_meta_data_ChangeCarsData,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ChangeCarsData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChangeCarsData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChangeCarsData.stringdata0))
        return static_cast<void*>(const_cast< ChangeCarsData*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ChangeCarsData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ChangeCarsData::mainsys()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ChangeCarsData::flchangesys()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ChangeCarsData::jbchangesys()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ChangeCarsData::ddchangesys()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
