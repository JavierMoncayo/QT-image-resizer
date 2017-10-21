/****************************************************************************
** Meta object code from reading C++ file 'imageResizer.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "imageResizer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageResizer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_imageResizer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      23,   13,   13,   13, 0x08,
      43,   37,   13,   13, 0x08,
      57,   13,   13,   13, 0x08,
      78,   73,   13,   13, 0x08,
     108,  103,   95,   13, 0x08,
     122,   13,   13,   13, 0x08,
     184,  149,  142,   13, 0x08,
     267,  221,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_imageResizer[] = {
    "imageResizer\0\0setDir()\0scaleImages()\0"
    "ready\0goReady(bool)\0setScaleLabel()\0"
    "path\0getInfo(QString)\0QString\0size\0"
    "getUnits(int)\0signalConnections()\0"
    "QImage\0imageFileName,sourcePath,finalPath\0"
    "changeSize(QString&,QString,QString)\0"
    "dirNum,fileNum,oriSize,finalSize,oriSizeUnits\0"
    "setInfoLabels(QString,QString,QString,QString,QString)\0"
};

void imageResizer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        imageResizer *_t = static_cast<imageResizer *>(_o);
        switch (_id) {
        case 0: _t->setDir(); break;
        case 1: _t->scaleImages(); break;
        case 2: _t->goReady((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setScaleLabel(); break;
        case 4: _t->getInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: { QString _r = _t->getUnits((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 6: _t->signalConnections(); break;
        case 7: { QImage _r = _t->changeSize((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 8: _t->setInfoLabels((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData imageResizer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject imageResizer::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_imageResizer,
      qt_meta_data_imageResizer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &imageResizer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *imageResizer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *imageResizer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_imageResizer))
        return static_cast<void*>(const_cast< imageResizer*>(this));
    return QDialog::qt_metacast(_clname);
}

int imageResizer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
