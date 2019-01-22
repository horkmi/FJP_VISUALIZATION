/****************************************************************************
** Meta object code from reading C++ file 'automaton.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/inner/automaton.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'automaton.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Automaton_t {
    QByteArrayData data[17];
    char stringdata0[178];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Automaton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Automaton_t qt_meta_stringdata_Automaton = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Automaton"
QT_MOC_LITERAL(1, 10, 13), // "hasNewHistory"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 13), // "hasNotHistory"
QT_MOC_LITERAL(4, 39, 11), // "hasNextStep"
QT_MOC_LITERAL(5, 51, 14), // "clearSelection"
QT_MOC_LITERAL(6, 66, 16), // "selectGrammarRow"
QT_MOC_LITERAL(7, 83, 5), // "index"
QT_MOC_LITERAL(8, 89, 22), // "selectParsingTableCell"
QT_MOC_LITERAL(9, 112, 3), // "row"
QT_MOC_LITERAL(10, 116, 6), // "column"
QT_MOC_LITERAL(11, 123, 13), // "processResult"
QT_MOC_LITERAL(12, 137, 6), // "accept"
QT_MOC_LITERAL(13, 144, 7), // "message"
QT_MOC_LITERAL(14, 152, 4), // "html"
QT_MOC_LITERAL(15, 157, 12), // "inputChanged"
QT_MOC_LITERAL(16, 170, 7) // "oneStep"

    },
    "Automaton\0hasNewHistory\0\0hasNotHistory\0"
    "hasNextStep\0clearSelection\0selectGrammarRow\0"
    "index\0selectParsingTableCell\0row\0"
    "column\0processResult\0accept\0message\0"
    "html\0inputChanged\0oneStep"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Automaton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,
       5,    0,   67,    2, 0x06 /* Public */,
       6,    1,   68,    2, 0x06 /* Public */,
       8,    2,   71,    2, 0x06 /* Public */,
      11,    1,   76,    2, 0x06 /* Public */,
      13,    2,   79,    2, 0x06 /* Public */,
      15,    0,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,   14,   13,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Automaton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Automaton *_t = static_cast<Automaton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->hasNewHistory(); break;
        case 1: _t->hasNotHistory(); break;
        case 2: _t->hasNextStep(); break;
        case 3: _t->clearSelection(); break;
        case 4: _t->selectGrammarRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->selectParsingTableCell((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->processResult((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->message((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: _t->inputChanged(); break;
        case 9: _t->oneStep(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Automaton::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Automaton::hasNewHistory)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Automaton::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Automaton::hasNotHistory)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Automaton::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Automaton::hasNextStep)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Automaton::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Automaton::clearSelection)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Automaton::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Automaton::selectGrammarRow)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Automaton::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Automaton::selectParsingTableCell)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Automaton::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Automaton::processResult)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (Automaton::*_t)(bool , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Automaton::message)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (Automaton::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Automaton::inputChanged)) {
                *result = 8;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Automaton::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Automaton.data,
      qt_meta_data_Automaton,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Automaton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Automaton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Automaton.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Automaton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Automaton::hasNewHistory()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Automaton::hasNotHistory()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Automaton::hasNextStep()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Automaton::clearSelection()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Automaton::selectGrammarRow(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Automaton::selectParsingTableCell(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Automaton::processResult(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Automaton::message(bool _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Automaton::inputChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
