#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QObject>
#include <QList>
#include <mutex>
#include <qrandom.h>
#include "MessageStruct.h"
#include "src/model/database/database.h"


/*
 * 控制当前列表的播放和歌单的添加删除等功能
 *
*/

class PlayList : public QObject
{
    Q_OBJECT
public:
    static PlayList* getInstance();
    ~PlayList();
    void addSongToCurList(const songMessage& song);
    void addList(const QList<songMessage>& list);
    void removeSongFromCurList(int index);
    void setPlayPattern(playPattern pattern);
    void removeAllMusic();
    int queryIndex(const QString& songPath);
    void changeSort(int index);
    songMessage& getNextSong();
    songMessage& getLastSong();

public:
    // 与数据库进行交互
    bool insertFavorite(const songMessage& song);
    // 如果是网络路径，如果是本地路径：直接对比songPath
    bool checkInFavoriteList(const QString& songPath = "");
    // 从本地中查询数据
    void getData(songMessage& song);
    void getFavoriteMusic(QList<songMessage>& item);
    void removeSongFromMyFavorite(const QString &songPath);

private:
    explicit PlayList(QObject *parent = nullptr);
    PlayList(const PlayList&) = delete;
    PlayList& operator=(const PlayList&) = delete;

signals:
    void insertToHead(const songMessage& item);
    void startPlay(const songMessage& song);

private:
    static std::once_flag m_flag;
    static PlayList* m_pInstance;
    DataBase* database;
    QList<songMessage> realList;
    playPattern currentPattern;
    int curIndex; // 当前播放的歌曲索引，特指realList中
    songMessage emptySong;
    bool isFirstPlay;
};

#endif // PLAYLIST_H

