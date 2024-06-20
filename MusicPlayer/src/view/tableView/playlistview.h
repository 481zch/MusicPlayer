#ifndef PLAYLISTVIEW_H
#define PLAYLISTVIEW_H

#include <QWidget>
#include <QStandardItemModel>
#include "ui_playlistview.h"

namespace Ui {
class PlayListView;
}

class PlayListView : public QWidget
{
    Q_OBJECT

public:
    explicit PlayListView(QWidget *parent = nullptr);
    ~PlayListView();

signals:
    void addFavoiteList(const QString& data);
    void removeFromPlayList(int);

public:
    QStandardItemModel* model;
    Ui::PlayListView *ui;

private:
};

#endif // PLAYLISTVIEW_H
