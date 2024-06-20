QT       += core gui
QT       += multimedia
QT       += network
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    src/control/allControl/allcontrol.cpp \
    src/control/customItemDelegate/customitemdelegate.cpp \
    src/control/displayList/displaylist.cpp \
    src/control/displayList/searchapi.cpp \
    src/control/playList/controlplaylist.cpp \
    src/control/playList/startplaymusic.cpp \
    src/model/cache/cache.cpp \
    src/model/database/database.cpp \
    src/model/importMusic/importlocalmusic.cpp \
    src/model/netWork/downloadfile.cpp \
    src/model/netWork/searchmusic.cpp \
    src/model/playList/playlist.cpp \
    src/view/Lyric/lyric.cpp \
    src/view/loading/loading.cpp \
    src/view/tableView/playlistview.cpp \
    src/view/volume/volume.cpp

HEADERS += \
    MessageStruct.h \
    mainwindow.h \
    src/control/allControl/allcontrol.h \
    src/control/customItemDelegate/customitemdelegate.h \
    src/control/displayList/displaylist.h \
    src/control/displayList/searchapi.h \
    src/control/playList/controlplaylist.h \
    src/control/playList/startplaymusic.h \
    src/model/cache/cache.h \
    src/model/database/database.h \
    src/model/importMusic/importlocalmusic.h \
    src/model/netWork/downloadfile.h \
    src/model/netWork/searchmusic.h \
    src/model/playList/playlist.h \
    src/view/Lyric/lyric.h \
    src/view/loading/loading.h \
    src/view/tableView/playlistview.h \
    src/view/volume/volume.h

FORMS += \
    mainwindow.ui \
    src/view/Lyric/lyric.ui \
    src/view/loading/loading.ui \
    src/view/tableView/playlistview.ui \
    src/view/volume/volume.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

win32: RC_ICONS += "logo.ico"

DISTFILES +=
