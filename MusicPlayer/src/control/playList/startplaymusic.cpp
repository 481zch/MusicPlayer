#include "startplaymusic.h"

StartPlayMusic::StartPlayMusic(QObject *parent)
    : QObject{parent}
{
    // 准备播放资源:
    w = MainWindow::getInstance();
    playList = PlayList::getInstance();
    media = new QMediaPlayer(this);
    audio = new QAudioOutput(this);
    media->setAudioOutput(audio);
    countLyric = 7;
    cache = new Cache(this);

    // 后期需要进行优化解耦
    connect(w, &MainWindow::playAccordingList, this, [=](int type){
        if (type == 0) {
            if (media->playbackState() == QMediaPlayer::PlayingState || media->playbackState() == QMediaPlayer::PausedState) {
                loadPrompt();
                media->stop();
            }
            songMessage& song = playList->getNextSong();
            fromNet = song.songPath.startsWith("http");
            dealWithPlay(song);
        } else if (type == 1) {
            if (media->playbackState() == QMediaPlayer::StoppedState) {
                songMessage& song = playList->getNextSong();
                fromNet = song.songPath.startsWith("http");
                dealWithPlay(song);
            } else {
                media->play();
            }
        }

    });

    // 修改播放模式
    connect(w, &MainWindow::changeMode, playList, &PlayList::setPlayPattern);

    // 歌词的更新
    connect(media, &QMediaPlayer::positionChanged, this, &StartPlayMusic::updateTextTime);

    // 时间标签的修改
    connect(media, &QMediaPlayer::durationChanged, this, &StartPlayMusic::updateTime);

    // 暂停播放音乐
    connect(w, &MainWindow::stopPlay, media, &QMediaPlayer::pause);

    // 进度条拖动完成后才改变播放
    connect(w, &MainWindow::sliderMoved, this, [=](int position){
        qint64 duration = media->duration();
        qint64 newPosition = (duration * position) / 100;
        media->setPosition(newPosition);
    });

    // 歌曲结束时发出信号通知方便切换下一首歌曲
    connect(media, &QMediaPlayer::mediaStatusChanged, this, [=](QMediaPlayer::MediaStatus status){
        if (status == QMediaPlayer::EndOfMedia) {
            songMessage& song = playList->getNextSong();
            if (song.songPath.isEmpty()) {
                w->on_btn_pauseMusic_clicked();
                return;
            }
            fromNet = song.songPath.startsWith("http");
            // 开始播放这首歌曲
            dealWithPlay(song);
        }
    });

    connect(w->volume, &Volume::changeValue, audio, [=](float value){
        audio->setVolume(value);
    });

    connect(cache, &Cache::downloadFinished, this, [=](const songMessage& song){
        w->stopLoadAnimation();
        dealWithLocal(song);
    });

    // 关闭的时候清空缓存文件
    connect(w, &MainWindow::clearCache, cache, &Cache::clearFiles);
    connect(cache, &Cache::clearFinish, w, &MainWindow::close);

    // 和上一首歌曲与下一首歌曲建立连接
    connect(w, &MainWindow::switchLastSong, this, [=](){
        if (media->playbackState() == QMediaPlayer::PlayingState || media->playbackState() == QMediaPlayer::PausedState) {
            loadPrompt();
            media->stop();
        }
        songMessage& song = playList->getLastSong();
        fromNet = song.songPath.startsWith("http");
        dealWithPlay(song);
    });

    connect(w, &MainWindow::switchNextSong, this, [=](){
        if (media->playbackState() == QMediaPlayer::PlayingState || media->playbackState() == QMediaPlayer::PausedState) {
            loadPrompt();
            media->stop();
        }
        songMessage& song = playList->getNextSong();
        fromNet = song.songPath.startsWith("http");
        dealWithPlay(song);
    });

    connect(cache->download, &DownloadFile::downloadError, this, [=](){
        QMessageBox::information(nullptr, "播放失败", "当前音乐暂时无法播放（版权问题）");
        // 停止动画
        w->stopLoadAnimation();
        // 从当前歌曲列表中移除
        if (w->playView->model->rowCount() == 1) {
            w->setUnSelectedForPlayBtn();
            w->setUnSelectedForLastBtn();
            w->setUnSelectedForNextBtn();
        }
        emit w->removeFromPlayList(0);
        // 转到下一首歌曲
        emit w->switchNextSong();
    });
}

void StartPlayMusic::dealWithPlay(songMessage &song)
{
    // 后面应该再想一种办法使得停止继续加载想要播放的那首在线音乐的，否则会出现跳乱
    if (fromNet) {
        w->startLoadAnimation();
        int type = song.songLrcPath.startsWith("http://music.163.com/");
        // 来自于网易云为1，来自于gitee为0
        cache->transformHttp(song, type);
    }
    else dealWithLocal(song);
}

void StartPlayMusic::updateTextTime(qint64 position)
{
    updateSliderAndTime(position);

    // 延迟匹配
    position -= 1000;

    if (listLyric.empty()) {
        QStringList temp;
        temp << "暂时未匹配到歌词";
        w->lyric->textChanged(temp);
        return;
    }

    QStringList displayLyrics(countLyric, QString());
    QMap<qint64, QString>::iterator target = listLyric.end();
    qint64 minDiff = std::numeric_limits<qint64>::max();

    for (auto it = listLyric.begin(); it != listLyric.end(); ++ it) {
        qint64 diff = qAbs(position - it.key());
        if (diff == 0) {
            target = it;
            break;
        }
        else if (diff < minDiff) {
            minDiff = diff;
            target = it;
        }
    }

    int mid = countLyric / 2;
    displayLyrics[mid] = target.value();
    auto it = target;
    // 显示前面的歌词
    for (int i = mid - 1; i >= 0; --i)
    {
        if (it != listLyric.begin())
        {
            --it;
            displayLyrics[i] = it.value();
        }
        else
        {
            displayLyrics[i] = "\n";
        }
    }
    // 显示后面的歌词
    it = target;
    for (int i = mid + 1; i < countLyric; ++i)
    {
        if (it != listLyric.end())
        {
            ++it;
            if (it != listLyric.end())
            {
                displayLyrics[i] = it.value();
            }
            else
            {
                displayLyrics[i] = "\n";
            }
        }
        else
        {
            displayLyrics[i] = "\n";
        }
    }



    // 刷新歌词显示
    w->lyric->textChanged(displayLyrics);
}

// 更新结束时间
void StartPlayMusic::updateTime(qint64 duration)
{
    int seconds = (duration / 1000) % 60;
    int minutes = (duration / 60000) % 60;
    int hours = (duration / 3600000);
    QString timeString;
    if (hours > 0)
    {
        timeString = QString("%1:%2:%3").arg(hours, 2, 10, QChar('0')).arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));
    }
    else
    {
        timeString = QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));
    }
    w->ui->label_time->setText(timeString);
}

// 为了获得模糊渐变色
QColor StartPlayMusic::extractDominantColor(const QImage &image) {
    QHash<QRgb, int> colorCount;
    QColor color;
    for (int y = 0; y < image.height(); y++) {
        for (int x = 0; x < image.width(); x++) {
            color.setRgb(image.pixel(x, y));
            // 转换到 HSV 色彩空间
            color = color.toHsv();
            if (color.value() > 30 && color.value() < 225 && color.saturation() > 25) {
                QRgb rgbColor = color.rgb();
                colorCount[rgbColor]++;
            }
        }
    }

    QRgb mostFrequent = 0;
    int maxCount = 0;
    for (auto it = colorCount.constBegin(); it != colorCount.constEnd(); ++it) {
        if (it.value() > maxCount) {
            maxCount = it.value();
            mostFrequent = it.key();
        }
    }

    return QColor(mostFrequent).toRgb();
}


void StartPlayMusic::setGradientBackground(QWidget *widget, const QColor &startColor) {
    QString styleSheet = QString(R"(
    QWidget#widget_2 {
            border-style: none;
            background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,
                                                          stop:0 rgba(%1, %2, %3, 255),
                                                          stop:1 rgba(255, 255, 255, 255));
        }
    )").arg(startColor.red()).arg(startColor.green()).arg(startColor.blue());

    widget->setStyleSheet(styleSheet);
}

bool StartPlayMusic::analysisLyric(const QString &lyricPath)
{
    listLyric.clear();
    QFile file(lyricPath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        listLyric.clear();
        return false;
    }
    QTextStream in(&file);
    QString line;
    while (!in.atEnd()) {
        line = in.readLine();
        analysisLyricsFile(line);
    }
    return true;
}

bool StartPlayMusic::analysisLyricsFile(QString line)
{
    if (line.isEmpty())
    {
        return false;
    }
    QRegularExpression timeRegExp("\\[(\\d+):(\\d+\\.\\d+)\\]");
    QRegularExpressionMatch match = timeRegExp.match(line);

    if (match.hasMatch())
    {
        int minutes = match.captured(1).toInt();
        float seconds = match.captured(2).toFloat();
        qint64 totalTime = minutes * 60000 + qRound(seconds * 1000);

        QString lyricText = line.mid(match.capturedLength());
        listLyric.insert(totalTime, lyricText);
    }
    return true;
}

void StartPlayMusic::updateSliderAndTime(qint64 position)
{
    // 同时完成更新当前播放时间
    int seconds = (position / 1000) % 60;
    int minutes = (position / 60000) % 60;
    int hours = (position / 3600000);
    QString timeString;
    if (hours > 0)
    {
        timeString = QString("%1:%2:%3").arg(hours, 2, 10, QChar('0')).arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));
    }
    else
    {
        timeString = QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));
    }
    w->ui->label_time_start->setText(timeString);

    // 正在拖动的话就停止更新
    if (w->isSliderBeingMoved) return;
    // 计算进度条的位置并更新
    qint64 duration = media->duration();
    if (duration > 0) {
        int sliderPosition = static_cast<int>((position * 100) / duration);
        w->ui->song_slider->setSliderPosition(sliderPosition);
    }
}

void StartPlayMusic::dealWithLocal(const songMessage &song)
{
    QStringList temp;
    w->lyric->textChanged(temp);
    // 加载图片，歌词，歌手，音乐名称，音乐时长，高斯背景模糊
    setGradientBackground(w->lyric->ui->widget_2, extractDominantColor(QImage(song.coverPath)));
    if (song.coverPath.isEmpty()) {
        w->lyric->ui->playCover->setStyleSheet(QString("border-image: url(:/image/myMusic/cd.png);border-radius: 100px;"));
    }
    else w->lyric->ui->playCover->setStyleSheet(QString("border-image: url(%1);border-radius: 100px;").arg(song.coverPath));

    w->ui->label_singer_pic->setScaledContents(true);
    if (song.coverPath.isEmpty()) {
        w->ui->label_singer_pic->setPixmap(QPixmap(":/image/myMusic/unKnowHead.jpg"));
    }
    else w->ui->label_singer_pic->setPixmap(QPixmap(song.coverPath));

    w->ui->label_singer_name->setText(song.singer);
    w->ui->label_song_name->setText(song.songName);

    // 解析歌词
    analysisLyric(song.songLrcPath);

    // 播放
    media->setSource(QUrl::fromLocalFile(song.songPath));
    audio->setVolume(0.25);
    media->play();
}

void StartPlayMusic::loadPrompt()
{
    w->ui->label_singer_name->setText("加载中...");
    w->ui->label_song_name->setText("加载中...");
    w->ui->label_singer_pic->setPixmap(QPixmap(":/image/myMusic/unKnowHead.jpg"));
}






