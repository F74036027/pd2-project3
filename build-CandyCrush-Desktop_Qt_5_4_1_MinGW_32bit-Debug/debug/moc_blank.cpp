/****************************************************************************
** Meta object code from reading C++ file 'blank.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CandyCrush/blank.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'blank.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Blank_t {
    QByteArrayData data[11];
    char stringdata[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Blank_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Blank_t qt_meta_stringdata_Blank = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Blank"
QT_MOC_LITERAL(1, 6, 5), // "Click"
QT_MOC_LITERAL(2, 12, 0), // ""
QT_MOC_LITERAL(3, 13, 3), // "row"
QT_MOC_LITERAL(4, 17, 3), // "col"
QT_MOC_LITERAL(5, 21, 8), // "MoveDone"
QT_MOC_LITERAL(6, 30, 5), // "click"
QT_MOC_LITERAL(7, 36, 9), // "moveright"
QT_MOC_LITERAL(8, 46, 8), // "moveleft"
QT_MOC_LITERAL(9, 55, 8), // "movedown"
QT_MOC_LITERAL(10, 64, 6) // "moveup"

    },
    "Blank\0Click\0\0row\0col\0MoveDone\0click\0"
    "moveright\0moveleft\0movedown\0moveup"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Blank[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,
       5,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   55,    2, 0x0a /* Public */,
       7,    0,   56,    2, 0x0a /* Public */,
       8,    0,   57,    2, 0x0a /* Public */,
       9,    0,   58,    2, 0x0a /* Public */,
      10,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Blank::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Blank *_t = static_cast<Blank *>(_o);
        switch (_id) {
        case 0: _t->Click((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->MoveDone(); break;
        case 2: _t->click(); break;
        case 3: _t->moveright(); break;
        case 4: _t->moveleft(); break;
        case 5: _t->movedown(); break;
        case 6: _t->moveup(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Blank::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Blank::Click)) {
                *result = 0;
            }
        }
        {
            typedef void (Blank::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Blank::MoveDone)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject Blank::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Blank.data,
      qt_meta_data_Blank,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Blank::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Blank::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Blank.stringdata))
        return static_cast<void*>(const_cast< Blank*>(this));
    return QObject::qt_metacast(_clname);
}

int Blank::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Blank::Click(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Blank::MoveDone()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
