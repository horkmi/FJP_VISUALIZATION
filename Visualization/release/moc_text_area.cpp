/****************************************************************************
** Meta object code from reading C++ file 'text_area.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/gui/text_area.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'text_area.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TextArea_t {
    QByteArrayData data[8];
    char stringdata0[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TextArea_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TextArea_t qt_meta_stringdata_TextArea = {
    {
QT_MOC_LITERAL(0, 0, 8), // "TextArea"
QT_MOC_LITERAL(1, 9, 4), // "show"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 5), // "state"
QT_MOC_LITERAL(4, 21, 19), // "appendHtmlPlainText"
QT_MOC_LITERAL(5, 41, 4), // "html"
QT_MOC_LITERAL(6, 46, 8), // "QString*"
QT_MOC_LITERAL(7, 55, 13) // "htmlPlainText"

    },
    "TextArea\0show\0\0state\0appendHtmlPlainText\0"
    "html\0QString*\0htmlPlainText"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TextArea[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x0a /* Public */,
       4,    2,   27,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 6,    5,    7,

       0        // eod
};

void TextArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TextArea *_t = static_cast<TextArea *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->show((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->appendHtmlPlainText((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString*(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject TextArea::staticMetaObject = {
    { &QPlainTextEdit::staticMetaObject, qt_meta_stringdata_TextArea.data,
      qt_meta_data_TextArea,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TextArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TextArea::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TextArea.stringdata0))
        return static_cast<void*>(const_cast< TextArea*>(this));
    return QPlainTextEdit::qt_metacast(_clname);
}

int TextArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlainTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
