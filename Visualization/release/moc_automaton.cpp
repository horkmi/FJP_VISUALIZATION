/****************************************************************************
** Meta object code from reading C++ file 'automaton.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/inner/automaton.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'automaton.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Automaton_t {
    QByteArrayData data[19];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Automaton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Automaton_t qt_meta_stringdata_Automaton = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Automaton"
QT_MOC_LITERAL(1, 10, 10), // "setGrammar"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 8), // "setStack"
QT_MOC_LITERAL(4, 31, 8), // "setTable"
QT_MOC_LITERAL(5, 40, 16), // "selectGrammarRow"
QT_MOC_LITERAL(6, 57, 5), // "index"
QT_MOC_LITERAL(7, 63, 14), // "selectStackRow"
QT_MOC_LITERAL(8, 78, 10), // "selectCell"
QT_MOC_LITERAL(9, 89, 3), // "row"
QT_MOC_LITERAL(10, 93, 6), // "column"
QT_MOC_LITERAL(11, 100, 13), // "processResult"
QT_MOC_LITERAL(12, 114, 6), // "accept"
QT_MOC_LITERAL(13, 121, 7), // "message"
QT_MOC_LITERAL(14, 129, 4), // "html"
QT_MOC_LITERAL(15, 134, 12), // "inputChanged"
QT_MOC_LITERAL(16, 147, 4), // "done"
QT_MOC_LITERAL(17, 152, 7), // "process"
QT_MOC_LITERAL(18, 160, 6) // "future"

    },
    "Automaton\0setGrammar\0\0setStack\0setTable\0"
    "selectGrammarRow\0index\0selectStackRow\0"
    "selectCell\0row\0column\0processResult\0"
    "accept\0message\0html\0inputChanged\0done\0"
    "process\0future"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Automaton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    1,   62,    2, 0x06 /* Public */,
       7,    1,   65,    2, 0x06 /* Public */,
       8,    2,   68,    2, 0x06 /* Public */,
      11,    1,   73,    2, 0x06 /* Public */,
      13,    2,   76,    2, 0x06 /* Public */,
      15,    3,   81,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,   14,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   16,   17,   18,

       0        // eod
};

void Automaton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Automaton *_t = static_cast<Automaton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setGrammar(); break;
        case 1: _t->setStack(); break;
        case 2: _t->setTable(); break;
        case 3: _t->selectGrammarRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->selectStackRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->selectCell((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->processResult((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->message((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: _t->inputChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Automaton::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Automaton::setGrammar)) {
                *result = 0;
            }
        }
        {
            typedef void (Automaton::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Automaton::setStack)) {
                *result = 1;
            }
        }
        {
            typedef void (Automaton::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Automaton::setTable)) {
                *result = 2;
            }
        }
        {
            typedef void (Automaton::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Automaton::selectGrammarRow)) {
                *result = 3;
            }
        }
        {
            typedef void (Automaton::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Automaton::selectStackRow)) {
                *result = 4;
            }
        }
        {
            typedef void (Automaton::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Automaton::selectCell)) {
                *result = 5;
            }
        }
        {
            typedef void (Automaton::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Automaton::processResult)) {
                *result = 6;
            }
        }
        {
            typedef void (Automaton::*_t)(bool , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Automaton::message)) {
                *result = 7;
            }
        }
        {
            typedef void (Automaton::*_t)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Automaton::inputChanged)) {
                *result = 8;
            }
        }
    }
}

const QMetaObject Automaton::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Automaton.data,
      qt_meta_data_Automaton,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Automaton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Automaton::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Automaton.stringdata0))
        return static_cast<void*>(const_cast< Automaton*>(this));
    return QThread::qt_metacast(_clname);
}

int Automaton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void Automaton::setGrammar()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Automaton::setStack()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Automaton::setTable()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void Automaton::selectGrammarRow(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Automaton::selectStackRow(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Automaton::selectCell(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Automaton::processResult(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Automaton::message(bool _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Automaton::inputChanged(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE
