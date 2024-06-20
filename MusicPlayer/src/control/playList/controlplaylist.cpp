#include "controlplaylist.h"

ControlPlayList::ControlPlayList(QObject *parent)
    : QObject{parent}
{
    w = MainWindow::getInstance();
    playList = PlayList::getInstance();

    // 将path分割组合：songpath + | + songName + | + songPic + | + lycPath + | + singer + | + songID + | + songAllPath
    connect(w, &MainWindow::addFavoiteList, this, [=](const QString& localPath){
        songMessage song;
        if (localPath.startsWith("http")) song = packageSongMessage(localPath);
        else song = getSongMessageBySongPath(localPath);

        // 查询
        if (playList->checkInFavoriteList(song.songPath)) {
            QMessageBox::information(nullptr, "信息", "歌曲已经在喜欢的列表中，不需要重复添加。");
            return;
        }

        // 添加到我喜欢的歌单中
        bool success = playList->insertFavorite(song);
        if (!success) {
            QMessageBox::information(nullptr, "信息", "歌曲添加失败，请稍后重试");
            qDebug() << "添加失败";
        } else {
            QMessageBox::information(nullptr, "信息", "歌曲添加成功");
            qDebug() << "添加成功";
        }
    });

    // 单曲加入播放列表
    connect(w, &MainWindow::addPlayList, this, [=](const QString& songPath){
        songMessage temp;
        if (songPath.startsWith("http")) temp = packageSongMessage(songPath);
        else temp = getSongMessageBySongPath(songPath);
        // 根据localPath获得对应的songMessage
        playList->addSongToCurList(temp);
    });

    // 修改播放顺序
    connect(w, &MainWindow::changePlaySort, this, [=](const QString& songPath){
        songMessage temp;
        if (songPath.startsWith("http")) temp = packageSongMessage(songPath);
        else temp = getSongMessageBySongPath(songPath);
        int index = playList->queryIndex(temp.songPath);
        playList->changeSort(index);
        // 修改在model中的显示，默认将要显示在头部
        changeLocInView(w->playView->model, index);
    });

    // 歌单加入播放列表
    connect(w, &MainWindow::addListToPlayList, this, [=](QStandardItemModel* model){
        w->playView->ui->btn_removeAll->click();
        playList->removeAllMusic();
        // 将model中的所有内容加入列表中，逆序加入
        w->recoverNoramlForPlayBtn();
        w->recoverNormalForLastBtn();
        w->recoverNormalForNextBtn();
        insertListToPlayingList(model);
    });
}

songMessage ControlPlayList::getSongMessageBySongPath(const QString &songPath)
{
    songMessage song;
    QString path;
    if (songPath.startsWith("http")) {
        QStringList parts = songPath.split('|');
        song.songPath = parts[0], song.songName = parts[1],
            song.coverPath = parts[2], song.songLrcPath = parts[3],
            song.singer = parts[4], song.songID = parts[5], song.allPath = parts[6];
    }
    else {
        // 查询
        song.songPath = songPath;
        playList->getData(song);
    }

    return song;
}

songMessage ControlPlayList::packageSongMessage(const QString &songAllPath)
{
    songMessage song;
    QStringList parts = songAllPath.split('|', Qt::KeepEmptyParts);

    if (parts.size() == 6) {
        song.songPath = parts[0];
        song.songName = parts[1];
        song.coverPath = parts[2];
        song.songLrcPath = parts[3];
        song.singer = parts[4];
        song.songID = parts[5];
        song.allPath = songAllPath;
    }
    return song;
}

void ControlPlayList::insertListToPlayingList(QStandardItemModel *model)
{
    for (int row = model->rowCount() - 1; row >= 0; -- row) {
        QModelIndex index = model->index(row, 0);
        QVariant data = index.siblingAtColumn(0).data(Qt::UserRole);
        QString songPath = data.toString();
        songMessage song;
        if (songPath.startsWith("http")) song = packageSongMessage(songPath);
        else song = getSongMessageBySongPath(songPath);
        playList->addSongToCurList(song);
    }
}

void ControlPlayList::changeLocInView(QStandardItemModel *model, int index)
{
    QList<QStandardItem*> rowItems = model->takeRow(index);
    model->insertRow(0, rowItems);
}

