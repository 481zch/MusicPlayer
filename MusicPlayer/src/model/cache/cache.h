#ifndef CACHE_H
#define CACHE_H

#include <QQueue>
#include <QObject>
#include <QStandardPaths>
#include "MessageStruct.h"
#include "qdir.h"
#include <unordered_map>
#include "src/model/netWork/downloadfile.h"

/*
 * 管理缓存空间
 * 存取音乐，歌词文件，以及对应的封面图片
 * 每一次退出的时候清除所有存在的文件
 */

class Cache : public QObject
{
    Q_OBJECT
public:
    explicit Cache(QObject *parent = nullptr);
    void transformHttp(const songMessage& song, int type);
    // 图片，歌词，音乐
    int calculateFilesSize();
    // 设置缓存文件存储的位置
    void setLocation();
    void formatLyricsFile(const QString &filePath);

signals:
    void downloadFinished(const songMessage &song);
    void clearFinish();

public slots:
    void downloadFinish();
    void clearFiles();

private:
    void setCacheSize(int num);
    QString sanitizeFileName(const QString& fileName);

public:
    DownloadFile* download;

private:
    long long storage; // 设置存储空间大小
    QQueue<songMessage> q; // 对应加入文件的顺序
    QString filePrefix;
    songMessage res;
    int downloadCount;
    std::unordered_map<QString, songMessage> mp;
};

#endif // CACHE_H
