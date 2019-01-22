/****************************************************************************
** Meta object code from reading C++ file 'main_window.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/gui/main_window.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[25];
    char stringdata0[284];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 19), // "automatonHasHistory"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 22), // "automatonHasNotHistory"
QT_MOC_LITERAL(4, 55, 16), // "automatonHasNext"
QT_MOC_LITERAL(5, 72, 18), // "playPauseAnimation"
QT_MOC_LITERAL(6, 91, 8), // "prevStep"
QT_MOC_LITERAL(7, 100, 8), // "nextStep"
QT_MOC_LITERAL(8, 109, 14), // "resetAnimation"
QT_MOC_LITERAL(9, 124, 8), // "slowDown"
QT_MOC_LITERAL(10, 133, 7), // "speedUp"
QT_MOC_LITERAL(11, 141, 11), // "updateInput"
QT_MOC_LITERAL(12, 153, 8), // "setInput"
QT_MOC_LITERAL(13, 162, 5), // "input"
QT_MOC_LITERAL(14, 168, 13), // "chooseGrammar"
QT_MOC_LITERAL(15, 182, 11), // "editGrammar"
QT_MOC_LITERAL(16, 194, 10), // "setGrammar"
QT_MOC_LITERAL(17, 205, 7), // "grammar"
QT_MOC_LITERAL(18, 213, 13), // "showScenarios"
QT_MOC_LITERAL(19, 227, 9), // "showAbout"
QT_MOC_LITERAL(20, 237, 7), // "message"
QT_MOC_LITERAL(21, 245, 4), // "html"
QT_MOC_LITERAL(22, 250, 13), // "processResult"
QT_MOC_LITERAL(23, 264, 6), // "accept"
QT_MOC_LITERAL(24, 271, 12) // "inputChanged"

    },
    "MainWindow\0automatonHasHistory\0\0"
    "automatonHasNotHistory\0automatonHasNext\0"
    "playPauseAnimation\0prevStep\0nextStep\0"
    "resetAnimation\0slowDown\0speedUp\0"
    "updateInput\0setInput\0input\0chooseGrammar\0"
    "editGrammar\0setGrammar\0grammar\0"
    "showScenarios\0showAbout\0message\0html\0"
    "processResult\0accept\0inputChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x08 /* Private */,
       3,    0,  110,    2, 0x08 /* Private */,
       4,    0,  111,    2, 0x08 /* Private */,
       5,    0,  112,    2, 0x08 /* Private */,
       6,    0,  113,    2, 0x08 /* Private */,
       7,    0,  114,    2, 0x08 /* Private */,
       8,    0,  115,    2, 0x08 /* Private */,
       9,    0,  116,    2, 0x08 /* Private */,
      10,    0,  117,    2, 0x08 /* Private */,
      11,    0,  118,    2, 0x08 /* Private */,
      12,    1,  119,    2, 0x08 /* Private */,
      14,    0,  122,    2, 0x08 /* Private */,
      15,    0,  123,    2, 0x08 /* Private */,
      16,    1,  124,    2, 0x08 /* Private */,
      18,    0,  127,    2, 0x08 /* Private */,
      19,    0,  128,    2, 0x08 /* Private */,
      20,    2,  129,    2, 0x08 /* Private */,
      22,    1,  134,    2, 0x08 /* Private */,
      24,    0,  137,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,   21,   20,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->automatonHasHistory(); break;
        case 1: _t->automatonHasNotHistory(); break;
        case 2: _t->automatonHasNext(); break;
        case 3: _t->playPauseAnimation(); break;
        case 4: _t->prevStep(); break;
        case 5: _t->nextStep(); break;
        case 6: _t->resetAnimation(); break;
        case 7: _t->slowDown(); break;
        case 8: _t->speedUp(); break;
        case 9: _t->updateInput(); break;
        case 10: _t->setInput((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->chooseGrammar(); break;
        case 12: _t->editGrammar(); break;
        case 13: _t->setGrammar((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->showScenarios(); break;
        case 15: _t->showAbout(); break;
        case 16: _t->message((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 17: _t->processResult((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->inputChanged(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
