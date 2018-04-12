/****************************************************************************
** Meta object code from reading C++ file 'clienttcpsocket.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../HorlogeIneractifAgendaClient/clienttcpsocket.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clienttcpsocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ClientTcpSocket_t {
    QByteArrayData data[12];
    char stringdata0[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClientTcpSocket_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClientTcpSocket_t qt_meta_stringdata_ClientTcpSocket = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ClientTcpSocket"
QT_MOC_LITERAL(1, 16, 18), // "emmetreMessageRecu"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 7), // "message"
QT_MOC_LITERAL(4, 44, 14), // "emmetreConnecE"
QT_MOC_LITERAL(5, 59, 19), // "emmetreDeconnection"
QT_MOC_LITERAL(6, 79, 19), // "clientDonneesRecues"
QT_MOC_LITERAL(7, 99, 8), // "connectE"
QT_MOC_LITERAL(8, 108, 10), // "deconnectE"
QT_MOC_LITERAL(9, 119, 12), // "erreurSocket"
QT_MOC_LITERAL(10, 132, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(11, 161, 6) // "erreur"

    },
    "ClientTcpSocket\0emmetreMessageRecu\0\0"
    "message\0emmetreConnecE\0emmetreDeconnection\0"
    "clientDonneesRecues\0connectE\0deconnectE\0"
    "erreurSocket\0QAbstractSocket::SocketError\0"
    "erreur"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientTcpSocket[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    0,   52,    2, 0x06 /* Public */,
       5,    0,   53,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   54,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    1,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void ClientTcpSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClientTcpSocket *_t = static_cast<ClientTcpSocket *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->emmetreMessageRecu((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->emmetreConnecE(); break;
        case 2: _t->emmetreDeconnection(); break;
        case 3: _t->clientDonneesRecues(); break;
        case 4: _t->connectE(); break;
        case 5: _t->deconnectE(); break;
        case 6: _t->erreurSocket((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ClientTcpSocket::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientTcpSocket::emmetreMessageRecu)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ClientTcpSocket::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientTcpSocket::emmetreConnecE)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ClientTcpSocket::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientTcpSocket::emmetreDeconnection)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ClientTcpSocket::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ClientTcpSocket.data,
      qt_meta_data_ClientTcpSocket,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ClientTcpSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientTcpSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ClientTcpSocket.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ClientTcpSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ClientTcpSocket::emmetreMessageRecu(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ClientTcpSocket::emmetreConnecE()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ClientTcpSocket::emmetreDeconnection()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
