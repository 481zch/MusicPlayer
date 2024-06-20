#include "playlist.h"


// 初始化静态对象
PlayList* PlayList::m_pInstance = nullptr;
std::once_flag PlayList::m_flag;

PlayList::PlayList(QObject *parent)
    : QObject{parent}
{
    // 默认是顺序播放
    currentPattern = playPattern::CycleList;
    database = DataBase::getInstance();
    curIndex = 0;
    isFirstPlay = true;
}

PlayList::~PlayList()
{
    // 清空播放列表
    realList.clear();
}

PlayList* PlayList::getInstance()
{
    std::call_once(m_flag, [](){m_pInstance = new PlayList(nullptr);});
    return m_pInstance;
}

void PlayList::addSongToCurList(const songMessage &song)
{
    realList.insert(0, song);
    curIndex = 0;
    isFirstPlay = true;
    emit insertToHead(song);
}

void PlayList::addList(const QList<songMessage> &list)
{
    realList.clear();
    realList = list; // 拷贝赋值
}

void PlayList::removeSongFromCurList(int index)
{
    realList.remove(index);
}

void PlayList::setPlayPattern(playPattern pattern)
{
    this->currentPattern = pattern;
}

void PlayList::removeAllMusic()
{
    realList.clear();
    curIndex = 0;
}

int PlayList::queryIndex(const QString &songPath)
{
    for (int i = 0; i < songPath.size(); ++ i) {
        if (realList[i].songPath == songPath) return i;
    }
    // 不可能出现
    return -1;
}


// 需要区分点击的是否是播放列表中的歌曲
void PlayList::changeSort(int index)
{
    // 将index处的移动到头部
    songMessage songToMove = realList.takeAt(index);
    realList.prepend(songToMove);
    isFirstPlay = true;
    curIndex = 0;
}

songMessage &PlayList::getNextSong()
{
    qDebug() << curIndex;
    // 异常信息(不存在歌曲)返回一个空的song表示没有歌曲
    if (realList.isEmpty()) {
        return emptySong;
    }
    if (isFirstPlay) {
        isFirstPlay = false;
        return realList[curIndex];
    }
    if (currentPattern == playPattern::singleCycle) {
        return realList[curIndex];
    } else if (currentPattern == playPattern::RandomList) {
        // 生成一个合法的index
        int randomIndex = QRandomGenerator::global()->bounded(realList.size());
        curIndex = randomIndex;
        return realList[curIndex];
    } else if (currentPattern == playPattern::CycleList) {
        curIndex = (curIndex + 1) % realList.size();
        return realList[curIndex];
    }
    return emptySong;
}

songMessage &PlayList::getLastSong()
{
    qDebug() << curIndex;
    if (realList.isEmpty()) {
        return emptySong;
    }
    if (isFirstPlay) {
        isFirstPlay = false;
        return realList[curIndex];
    }
    if (currentPattern == playPattern::singleCycle) {
        return realList[curIndex];
    } else if (currentPattern == playPattern::RandomList) {
        // 生成一个合法的index
        int randomIndex = QRandomGenerator::global()->bounded(realList.size());
        curIndex = randomIndex;
        return realList[curIndex];
    } else if (currentPattern == playPattern::CycleList) {
        curIndex = (curIndex - 1 + realList.size()) % realList.size();
        return realList[curIndex];
    }
    return emptySong;
}


bool PlayList::insertFavorite(const songMessage& song)
{
    return database->insertFavorite(song);
}

bool PlayList::checkInFavoriteList(const QString &songPath)
{
    if (songPath.isEmpty()) {
        qDebug() << "传入的路径为空";
        return true;
    }
    else return database->queryInMyFavoriteList(songPath);
}

void PlayList::getData(songMessage& song)
{
    // 根据path从数据库中的localMusic中进行检索
    database->getDataByPath(song);
}

void PlayList::getFavoriteMusic(QList<songMessage> &item)
{
    database->getFavoriteMusic(item);
}

void PlayList::removeSongFromMyFavorite(const QString &songPath)
{
    database->removeFavoriteMusic(songPath);
}



