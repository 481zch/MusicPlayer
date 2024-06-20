#ifndef STARTPLAYMUSIC_H
#define STARTPLAYMUSIC_H

#include <QObject>
#include <QColor>
#include <QImage>
#include <QMap>
#include <QTimer>
#include <QThread>
#include <QAudioOutput>
#include <QRegularExpression>
#include "MessageStruct.h"
#include "mainwindow.h"
#include "QMediaPlayer"
#include "src/control/playList/controlplaylist.h"
#include "src/model/cache/cache.h"

class StartPlayMusic : public QObject
{
    Q_OBJECT
public:
    explicit StartPlayMusic(QObject *parent = nullptr);

signals:
    void finishPlayCurSong(); // 当前播放的歌曲已经完成

public slots:
    void dealWithPlay(songMessage& song);
    void updateTextTime(qint64 position);
    void updateTime(qint64 duration);

private:
    QColor extractDominantColor(const QImage& image);
    void setGradientBackground(QWidget *widget, const QColor &startColor);
    bool analysisLyric(const QString& songPth);
    bool analysisLyricsFile(QString line);
    void updateSliderAndTime(qint64 duration); // 更新进度条和播放显示
    void restoreState(); // 恢复现场，避免缺失的时候没有对应的文件出现异常
    void dealWithLocal(const songMessage &song);
    void loadPrompt();

private:
    MainWindow* w;
    PlayList* playList;
    songMessage curSong;
    QMediaPlayer* media;
    QMap<qint64, QString> listLyric;
    QPixmap pixmap;
    QAudioOutput* audio;
    int countLyric; // 要显示出来的歌词数量
    bool fromNet; // 来源与网络还是本地的文件
    Cache* cache;
};

#endif // STARTPLAYMUSIC_H
