#ifndef CONTROLPLAYLIST_H
#define CONTROLPLAYLIST_H

#include <QObject>
#include <QMessageBox>
#include "mainwindow.h"
#include "src/model/playList/playlist.h"

class ControlPlayList : public QObject
{
    Q_OBJECT
public:
    explicit ControlPlayList(QObject *parent = nullptr);

private:
    songMessage getSongMessageBySongPath(const QString& songPath);
    songMessage packageSongMessage(const QString& songAllPath);
    void insertListToPlayingList(QStandardItemModel* model);
    void changeLocInView(QStandardItemModel* model, int index);

signals:

private:
    MainWindow* w;
    PlayList* playList;
};

#endif // CONTROLPLAYLIST_H
