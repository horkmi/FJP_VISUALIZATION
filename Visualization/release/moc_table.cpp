/****************************************************************************
** Meta object code from reading C++ file 'table.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/gui/table.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'table.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Table_t {
    QByteArrayData data[10];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Table_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Table_t qt_meta_stringdata_Table = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Table"
QT_MOC_LITERAL(1, 6, 10), // "setGrammar"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 8), // "setTable"
QT_MOC_LITERAL(4, 27, 8), // "setStack"
QT_MOC_LITERAL(5, 36, 9), // "selectRow"
QT_MOC_LITERAL(6, 46, 5), // "index"
QT_MOC_LITERAL(7, 52, 10), // "selectCell"
QT_MOC_LITERAL(8, 63, 3), // "row"
QT_MOC_LITERAL(9, 67, 6) // "column"

    },
    "Table\0setGrammar\0\0setTable\0setStack\0"
    "selectRow\0index\0selectCell\0row\0column"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Table[] = {

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
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    1,   42,    2, 0x08 /* Private */,
       7,    2,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,

       0        // eod
};

void Table::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Table *_t = static_cast<Table *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setGrammar(); break;
        case 1: _t->setTable(); break;
        case 2: _t->setStack(); break;
        case 3: _t->selectRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->selectCell((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject Table::staticMetaObject = {
    { &QTableWidget::staticMetaObject, qt_meta_stringdata_Table.data,
      qt_meta_data_Table,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Table::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Table::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Table.stringdata0))
        return static_cast<void*>(const_cast< Table*>(this));
    return QTableWidget::qt_metacast(_clname);
}

int Table::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
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