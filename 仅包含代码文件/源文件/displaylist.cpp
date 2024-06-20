#include "displaylist.h"

DisplayList::DisplayList(QObject* parent): QObject{parent}
{
    w = MainWindow::getInstance();
    import = new ImportLocalMusic(this);
    playList = PlayList::getInstance();
    search = new SearchAPI(this);
    curPage = 1;

    connect(w, &MainWindow::chooseLocalPath, this, [=](const QString& localPath){
        import->dealWithPath(localPath, list);
        // 显示在表格中
        displayInView(w->model1);
        // 更新标签
        w->ui->label_local_MusicCount->setText(QString("本地共有%1首歌曲").arg(w->model1->rowCount()));
        list.clear();
    });

    connect(w, &MainWindow::launchWindow, this, [=](){
        // 数据库检索获得表格信息
        import->getLocalMusic(list);
        displayInView(w->model1);
        w->ui->label_local_MusicCount->setText(QString("本地共有%1首歌曲").arg(w->model1->rowCount()));
        list.clear();

        // 加载默认在线gitee音乐
        prepareGiteeList();
        displayInView(w->model2);
        w->ui->label_download_MusicCount->setText(QString("在线共有%1首歌曲").arg(w->model2->rowCount()));
        list.clear();

        // 加载我喜欢的音乐
        loadMyFavoriteMusic();
        displayInView(w->model3);
        w->ui->label_favorite_songCount->setText(QString("我喜欢的音乐中共有%1首歌曲").arg(w->model3->rowCount()));
        list.clear();
    });

    connect(playList, &PlayList::insertToHead, this, [=](const songMessage& song){
        insertToPlayListHead(w->playView->model, song);
    });

    connect(w, &MainWindow::removeFromPlayList, this, [=](const int& row){
        removeSelectRow(w->playView->model, row);
    });

    connect(w->playView->ui->btn_removeAll, &QPushButton::clicked, this, [=](){
        w->setUnSelectedForPlayBtn();
        w->setUnSelectedForLastBtn();
        w->setUnSelectedForNextBtn();
        playList->removeAllMusic();
        removeAllInPlayList(w->playView->model);
    });

    connect(w, &MainWindow::refreshMyFavoriteMusic, this, [=](){
        refreshFavoriteMusic();
    });

    connect(w, &MainWindow::removeFavoiteList, this, [=](const QString& songPath){
        songMessage temp;
        // 对于allPath转化为songPath
        if (songPath.startsWith("http")) {
            temp = packageSongMessage(songPath);
            playList->removeSongFromMyFavorite(temp.songPath);
        }
        else playList->removeSongFromMyFavorite(songPath);
        refreshFavoriteMusic();
    });

    connect(w->ui->search, &QLineEdit::returnPressed, this, [=](){
        qDebug() << "发生了输入确认";
        // 首先清空内容
        removeAllInPlayList(w->model4);
        // 然后发起请求
        search->getMessageByText(list, curPage, w->ui->search->text());
        // 执行加载中动画
        w->loading->movie->start();
        w->loading->show();
    });

    connect(search->search, &SearchMusic::searchFinish, this, [=](){
        // 关闭加载中动画
        w->ui->tab_5->setCurrentIndex(3);
        w->loading->movie->finished();
        w->loading->hide();
        displayInView(w->model4);
        list.clear();
    });

    w->initialize();
}

void DisplayList::displayInView(QStandardItemModel* model)
{
    int curRow = model->rowCount();
    for (int i = 0; i < list.size(); ++ i) {
        const songMessage& item = list[i];
        QString singer = item.singer;
        QString songName = item.songName;
        QString songPath = item.songPath;
        // 这里本身就是特判，在线音乐不应该直接显示大小的
        QString fileSize = getFileSize(songPath);
        QString songAllPath = item.allPath;

        QStringList temp;
        temp << QString::number(i + 1 + curRow) << songName << singer << fileSize;

        // 当前这种判断方式肯定不严谨，暂时先这样判断（暂且默认对于所有需要的资源非本地即网络）
        if (item.songPath.startsWith("http")) {
            addViewRow(model, temp, songAllPath);
        }
        else addViewRow(model, temp, songPath);
    }
}

void DisplayList::addViewRow(QStandardItemModel *model, const QStringList &rowData, const QString &hiddenData)
{
    QList<QStandardItem*> items;
    for (const QString& text : rowData) {
        QStandardItem* item = new QStandardItem(text);
        item->setTextAlignment(Qt::AlignLeft);
        items.append(item);
    }
    model->appendRow(items);

    items.first()->setData(hiddenData, Qt::UserRole);
}

void DisplayList::insertToPlayListHead(QStandardItemModel* model, const songMessage &song)
{
    QList<QStandardItem*> items;
    items.append(new QStandardItem(song.songName));
    items.append(new QStandardItem(song.singer));
    model->insertRow(0, items);
    // 添加隐藏数据
    if (song.songPath.startsWith("http")) {
        items.first()->setData(song.allPath, Qt::UserRole);
    } else {
        items.first()->setData(song.songPath, Qt::UserRole);
    }
}

void DisplayList::prepareGiteeList()
{
    // 孤勇者 - 陈奕迅
    songMessage temp1;
    temp1.singer = "陈奕迅";
    temp1.songName = "孤勇者";
    temp1.songPath = "https://gitee.com/MarkYangUp/music/raw/master/%E5%AD%A4%E5%8B%87%E8%80%85/%E9%99%88%E5%A5%95%E8%BF%85/music.mp3";
    temp1.songLrcPath = "https://gitee.com/MarkYangUp/music/raw/master/%E5%AD%A4%E5%8B%87%E8%80%85/%E9%99%88%E5%A5%95%E8%BF%85/lyric.txt";
    temp1.coverPath = "https://gitee.com/MarkYangUp/music/raw/master/%E5%AD%A4%E5%8B%87%E8%80%85/%E9%99%88%E5%A5%95%E8%BF%85/img.jpg";
    temp1.songID = "";
    temp1.allPath = temp1.songPath + "|" + temp1.songName + "|" + temp1.coverPath + "|" + temp1.songLrcPath + "|" + temp1.singer + "|";

    // 风雨无阻 - 半吨兄弟
    songMessage temp2;
    temp2.singer = "半吨兄弟";
    temp2.songName = "风雨无阻";
    temp2.songPath = "https://gitee.com/MarkYangUp/music/raw/master/%E9%A3%8E%E9%9B%A8%E6%97%A0%E9%98%BB/%E5%8D%8A%E5%90%A8%E5%85%84%E5%BC%9F/music.mp3";
    temp2.songLrcPath = "https://gitee.com/MarkYangUp/music/raw/master/%E9%A3%8E%E9%9B%A8%E6%97%A0%E9%98%BB/%E5%8D%8A%E5%90%A8%E5%85%84%E5%BC%9F/lyric.txt";
    temp2.coverPath = "https://gitee.com/MarkYangUp/music/raw/master/%E9%A3%8E%E9%9B%A8%E6%97%A0%E9%98%BB/%E5%8D%8A%E5%90%A8%E5%85%84%E5%BC%9F/img.jpg";
    temp2.songID = "";
    temp2.allPath = temp2.songPath + "|" + temp2.songName + "|" + temp2.coverPath + "|" + temp2.songLrcPath + "|" + temp2.singer + "|";

    // 风雨无阻 - 周华健
    songMessage temp3;
    temp3.singer = "周华健";
    temp3.songName = "风雨无阻";
    temp3.songPath = "https://gitee.com/MarkYangUp/music/raw/master/%E9%A3%8E%E9%9B%A8%E6%97%A0%E9%98%BB/%E5%91%A8%E5%8D%8E%E5%81%A5/music.mp3";
    temp3.songLrcPath = "https://gitee.com/MarkYangUp/music/raw/master/%E9%A3%8E%E9%9B%A8%E6%97%A0%E9%98%BB/%E5%91%A8%E5%8D%8E%E5%81%A5/lyric.txt";
    temp3.coverPath = "https://gitee.com/MarkYangUp/music/raw/master/%E9%A3%8E%E9%9B%A8%E6%97%A0%E9%98%BB/%E5%91%A8%E5%8D%8E%E5%81%A5/img.jpg";
    temp3.songID = "";
    temp3.allPath = temp3.songPath + "|" + temp3.songName + "|" + temp3.coverPath + "|" + temp3.songLrcPath + "|" + temp3.singer + "|";

    list.append(temp1);
    list.append(temp2);
    list.append(temp3);
}

void DisplayList::loadMyFavoriteMusic()
{
    playList->getFavoriteMusic(list);
}

void DisplayList::refreshFavoriteMusic()
{
    removeAllInPlayList(w->model3);
    // 加载我喜欢的音乐
    loadMyFavoriteMusic();
    displayInView(w->model3);
    w->ui->label_favorite_songCount->setText(QString("我喜欢的音乐中共有%1首歌曲").arg(w->model3->rowCount()));
    list.clear();
}

songMessage DisplayList::packageSongMessage(const QString &songAllPath)
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

void DisplayList::removeSelectRow(QStandardItemModel *model, const int &row)
{
    model->removeRow(row);
}

void DisplayList::removeAllInPlayList(QStandardItemModel *model)
{
    int rowCount = model->rowCount();
    model->removeRows(0, rowCount);
}

QString DisplayList::getFileSize(const QString &songPath)
{
    QFileInfo fileInfo(songPath);
    qint64 size = fileInfo.size();
    return QString::number(size / (1024.0 * 1024.0), 'f', 2) + " MB";
}
