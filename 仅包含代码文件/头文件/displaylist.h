#ifndef DISPLAYLIST_H
#define DISPLAYLIST_H

#include <QObject>
#include "src/model/importMusic/importlocalmusic.h"
#include "src/model/playList/playlist.h"
#include "src/control/displayList/searchapi.h"
#include "mainwindow.h"

class DisplayList: QObject
{
    Q_OBJECT
public:
    DisplayList(QObject* parent = nullptr);
    QString getFileSize(const QString& songPath);

protected:
    void displayInView(QStandardItemModel* view);
    void addViewRow(QStandardItemModel* model, const QStringList& rowData, const QString &hiddenData);
    void insertToPlayListHead(QStandardItemModel* model, const songMessage& song);
    void removeSelectRow(QStandardItemModel* model, const int& row);
    void removeAllInPlayList(QStandardItemModel* model);
    void prepareGiteeList();
    void loadMyFavoriteMusic();
    void refreshFavoriteMusic();
    songMessage packageSongMessage(const QString& songAllPath);

private:
    MainWindow* w;
    PlayList* playList;
    ImportLocalMusic* import;
    SearchAPI* search;
    QList<songMessage> list;
    int curPage;
};

#endif // DISPLAYLIST_H
