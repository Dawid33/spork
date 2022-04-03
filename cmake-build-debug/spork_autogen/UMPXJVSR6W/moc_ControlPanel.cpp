/****************************************************************************
** Meta object code from reading C++ file 'ControlPanel.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/ui/control_panel/ControlPanel.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ControlPanel.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ControlPanel_t {
    QByteArrayData data[12];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ControlPanel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ControlPanel_t qt_meta_stringdata_ControlPanel = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ControlPanel"
QT_MOC_LITERAL(1, 13, 12), // "selectedItem"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 14), // "InventoryItem*"
QT_MOC_LITERAL(4, 42, 4), // "item"
QT_MOC_LITERAL(5, 47, 16), // "clickedUseButton"
QT_MOC_LITERAL(6, 64, 9), // "gotWordle"
QT_MOC_LITERAL(7, 74, 20), // "clickedInventoryCell"
QT_MOC_LITERAL(8, 95, 3), // "row"
QT_MOC_LITERAL(9, 99, 6), // "column"
QT_MOC_LITERAL(10, 106, 16), // "useButtonPressed"
QT_MOC_LITERAL(11, 123, 13) // "enteredWordle"

    },
    "ControlPanel\0selectedItem\0\0InventoryItem*\0"
    "item\0clickedUseButton\0gotWordle\0"
    "clickedInventoryCell\0row\0column\0"
    "useButtonPressed\0enteredWordle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ControlPanel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       5,    1,   47,    2, 0x06 /* Public */,
       6,    1,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    2,   53,    2, 0x09 /* Protected */,
      10,    1,   58,    2, 0x09 /* Protected */,
      11,    0,   61,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

       0        // eod
};

void ControlPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ControlPanel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->selectedItem((*reinterpret_cast< InventoryItem*(*)>(_a[1]))); break;
        case 1: _t->clickedUseButton((*reinterpret_cast< InventoryItem*(*)>(_a[1]))); break;
        case 2: _t->gotWordle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->clickedInventoryCell((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->useButtonPressed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->enteredWordle(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ControlPanel::*)(InventoryItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ControlPanel::selectedItem)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ControlPanel::*)(InventoryItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ControlPanel::clickedUseButton)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ControlPanel::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ControlPanel::gotWordle)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ControlPanel::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ControlPanel.data,
    qt_meta_data_ControlPanel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ControlPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ControlPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ControlPanel.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ControlPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ControlPanel::selectedItem(InventoryItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ControlPanel::clickedUseButton(InventoryItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ControlPanel::gotWordle(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
