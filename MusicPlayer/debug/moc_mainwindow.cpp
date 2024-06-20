/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "changeVolume",
    "",
    "value",
    "chooseLocalPath",
    "localPath",
    "launchWindow",
    "addFavoiteList",
    "songPath",
    "removeFavoiteList",
    "addPlayList",
    "changePlaySort",
    "addLocalMusic",
    "removeFromPlayList",
    "row",
    "stopPlay",
    "playAccordingList",
    "type",
    "sliderMoved",
    "position",
    "clearCache",
    "changeMode",
    "playPattern",
    "pattern",
    "addListToPlayList",
    "QStandardItemModel*",
    "model",
    "switchLastSong",
    "switchNextSong",
    "refreshMyFavoriteMusic",
    "on_btn_close_clicked",
    "on_btn_min_clicked",
    "on_btn_changeSize_clicked",
    "on_btn_volume_clicked",
    "on_import_music_clicked",
    "on_play_song_list_clicked",
    "on_song_slider_sliderMoved",
    "on_song_slider_sliderReleased",
    "on_btn_play_mode_clicked",
    "on_btn_local_playAll_clicked",
    "on_btn_download_playAll_clicked",
    "on_btn_lastMusic_clicked",
    "on_btn_nextMusic_clicked",
    "on_btn_favorite_playAll_clicked",
    "on_listwidget_local_itemClicked",
    "QListWidgetItem*",
    "item",
    "on_btn_online_playAll_clicked",
    "on_btn_pauseMusic_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      35,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      18,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  224,    2, 0x06,    1 /* Public */,
       4,    1,  227,    2, 0x06,    3 /* Public */,
       6,    0,  230,    2, 0x06,    5 /* Public */,
       7,    1,  231,    2, 0x06,    6 /* Public */,
       9,    1,  234,    2, 0x06,    8 /* Public */,
      10,    1,  237,    2, 0x06,   10 /* Public */,
      11,    1,  240,    2, 0x06,   12 /* Public */,
      12,    1,  243,    2, 0x06,   14 /* Public */,
      13,    1,  246,    2, 0x06,   16 /* Public */,
      15,    0,  249,    2, 0x06,   18 /* Public */,
      16,    1,  250,    2, 0x06,   19 /* Public */,
      18,    1,  253,    2, 0x06,   21 /* Public */,
      20,    0,  256,    2, 0x06,   23 /* Public */,
      21,    1,  257,    2, 0x06,   24 /* Public */,
      24,    1,  260,    2, 0x06,   26 /* Public */,
      27,    0,  263,    2, 0x06,   28 /* Public */,
      28,    0,  264,    2, 0x06,   29 /* Public */,
      29,    0,  265,    2, 0x06,   30 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      30,    0,  266,    2, 0x08,   31 /* Private */,
      31,    0,  267,    2, 0x08,   32 /* Private */,
      32,    0,  268,    2, 0x08,   33 /* Private */,
      33,    0,  269,    2, 0x08,   34 /* Private */,
      34,    0,  270,    2, 0x08,   35 /* Private */,
      35,    0,  271,    2, 0x08,   36 /* Private */,
      36,    1,  272,    2, 0x08,   37 /* Private */,
      37,    0,  275,    2, 0x08,   39 /* Private */,
      38,    0,  276,    2, 0x08,   40 /* Private */,
      39,    0,  277,    2, 0x08,   41 /* Private */,
      40,    0,  278,    2, 0x08,   42 /* Private */,
      41,    0,  279,    2, 0x08,   43 /* Private */,
      42,    0,  280,    2, 0x08,   44 /* Private */,
      43,    0,  281,    2, 0x08,   45 /* Private */,
      44,    1,  282,    2, 0x08,   46 /* Private */,
      47,    0,  285,    2, 0x08,   48 /* Private */,
      48,    0,  286,    2, 0x0a,   49 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void, 0x80000000 | 25,   26,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 45,   46,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'changeVolume'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'chooseLocalPath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'launchWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addFavoiteList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'removeFavoiteList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'addPlayList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'changePlaySort'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'addLocalMusic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'removeFromPlayList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'stopPlay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'playAccordingList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'sliderMoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'clearCache'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'changeMode'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<playPattern, std::false_type>,
        // method 'addListToPlayList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStandardItemModel *, std::false_type>,
        // method 'switchLastSong'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'switchNextSong'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'refreshMyFavoriteMusic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_close_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_min_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_changeSize_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_volume_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_import_music_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_play_song_list_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_song_slider_sliderMoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_song_slider_sliderReleased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_play_mode_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_local_playAll_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_download_playAll_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_lastMusic_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_nextMusic_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_favorite_playAll_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_listwidget_local_itemClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'on_btn_online_playAll_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_pauseMusic_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->changeVolume((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->chooseLocalPath((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->launchWindow(); break;
        case 3: _t->addFavoiteList((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->removeFavoiteList((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->addPlayList((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->changePlaySort((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->addLocalMusic((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->removeFromPlayList((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->stopPlay(); break;
        case 10: _t->playAccordingList((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->sliderMoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->clearCache(); break;
        case 13: _t->changeMode((*reinterpret_cast< std::add_pointer_t<playPattern>>(_a[1]))); break;
        case 14: _t->addListToPlayList((*reinterpret_cast< std::add_pointer_t<QStandardItemModel*>>(_a[1]))); break;
        case 15: _t->switchLastSong(); break;
        case 16: _t->switchNextSong(); break;
        case 17: _t->refreshMyFavoriteMusic(); break;
        case 18: _t->on_btn_close_clicked(); break;
        case 19: _t->on_btn_min_clicked(); break;
        case 20: _t->on_btn_changeSize_clicked(); break;
        case 21: _t->on_btn_volume_clicked(); break;
        case 22: _t->on_import_music_clicked(); break;
        case 23: _t->on_play_song_list_clicked(); break;
        case 24: _t->on_song_slider_sliderMoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 25: _t->on_song_slider_sliderReleased(); break;
        case 26: _t->on_btn_play_mode_clicked(); break;
        case 27: _t->on_btn_local_playAll_clicked(); break;
        case 28: _t->on_btn_download_playAll_clicked(); break;
        case 29: _t->on_btn_lastMusic_clicked(); break;
        case 30: _t->on_btn_nextMusic_clicked(); break;
        case 31: _t->on_btn_favorite_playAll_clicked(); break;
        case 32: _t->on_listwidget_local_itemClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 33: _t->on_btn_online_playAll_clicked(); break;
        case 34: _t->on_btn_pauseMusic_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QStandardItemModel* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(int );
            if (_t _q_method = &MainWindow::changeVolume; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const QString & );
            if (_t _q_method = &MainWindow::chooseLocalPath; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::launchWindow; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const QString & );
            if (_t _q_method = &MainWindow::addFavoiteList; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const QString & );
            if (_t _q_method = &MainWindow::removeFavoiteList; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const QString & );
            if (_t _q_method = &MainWindow::addPlayList; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const QString & );
            if (_t _q_method = &MainWindow::changePlaySort; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const QString & );
            if (_t _q_method = &MainWindow::addLocalMusic; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const int & );
            if (_t _q_method = &MainWindow::removeFromPlayList; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::stopPlay; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (_t _q_method = &MainWindow::playAccordingList; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (_t _q_method = &MainWindow::sliderMoved; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::clearCache; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(playPattern );
            if (_t _q_method = &MainWindow::changeMode; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QStandardItemModel * );
            if (_t _q_method = &MainWindow::addListToPlayList; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::switchLastSong; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::switchNextSong; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::refreshMyFavoriteMusic; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 17;
                return;
            }
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::changeVolume(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::chooseLocalPath(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::launchWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::addFavoiteList(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::removeFavoiteList(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::addPlayList(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::changePlaySort(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainWindow::addLocalMusic(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MainWindow::removeFromPlayList(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MainWindow::stopPlay()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void MainWindow::playAccordingList(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void MainWindow::sliderMoved(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void MainWindow::clearCache()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void MainWindow::changeMode(playPattern _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void MainWindow::addListToPlayList(QStandardItemModel * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void MainWindow::switchLastSong()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void MainWindow::switchNextSong()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void MainWindow::refreshMyFavoriteMusic()
{
    QMetaObject::activate(this, &staticMetaObject, 17, nullptr);
}
QT_WARNING_POP
