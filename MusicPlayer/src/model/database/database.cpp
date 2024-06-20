#include "database.h"

#include <qdir.h>
#include <qstandardpaths.h>


// 初始化静态对象
DataBase* DataBase::m_pInstance = nullptr;
// 初始化once_flag
std::once_flag DataBase::m_flag;

DataBase *DataBase::getInstance()
{
    std::call_once(m_flag, []() { m_pInstance = new DataBase(nullptr); });
    return m_pInstance;
}

DataBase::DataBase(QObject* parent): QObject{parent}
{
    tables = {"Other", "LocalMusic", "MyFavoriteList"};
    createDataBase();
    checkAndCreateTables();
}

bool DataBase::createDataBase()
{
    QString appLocalDataPath = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
    QDir().mkpath(appLocalDataPath);
    QString dbPath = appLocalDataPath + "/musicDataBaseZangCongHui.db";
    db = QSqlDatabase::addDatabase("QSQLITE");;
    db.setDatabaseName(dbPath);

    if (!db.open()) {
        qDebug() << "数据库创建或者打开失败 " << db.lastError();
        return false;
    }
    return true;
}

// 添加songID和songAllPath
void DataBase::checkAndCreateTables()
{
    QSqlQuery query(db);
    QStringList existTables = db.tables();

    foreach (const QString& table, tables) {
        if (!existTables.contains(table, Qt::CaseInsensitive)) {
            if (table == "Other") {
                bool success = query.exec("CREATE TABLE Other(localPath TEXT DEFAULT '', downloadPath TEXT DEFAULT '')");
                if (!success) {
                    qDebug() << "创建杂项表失败: " << query.lastError();
                    return;
                }
            }

            if (table == "LocalMusic") {
                bool success =
                    query.exec("CREATE TABLE LocalMusic(songPath TEXT "
                               "PRIMARY KEY, singer TEXT, songName TEXT, songLrcPath TEXT, coverPath TEXT, songID TEXT, songAllPath TEXT)");
                if (!success) {
                    qDebug() << "创建本地音乐表" << query.lastError();
                    return;
                }
            }

            if (table == "MyFavoriteList") {
                bool success =
                    query.exec("CREATE TABLE MyFavoriteList(songPath TEXT "
                               "PRIMARY KEY, singer TEXT, songName TEXT, songLrcPath TEXT, coverPath TEXT, songID TEXT, songAllPath TEXT)");
                if (!success) {
                    qDebug() << "创建我喜欢的音乐歌单" << query.lastError();
                    return;
                }
            }
        }
    }
}

bool DataBase::updateLocalPath(const QString &localPath)
{
    QSqlQuery query(db);

    if (localPath.isEmpty()) {
        qDebug() << "传入的本地路径为空";
        return true;
    }
    query.prepare("UPDATE Other SET localPath = ?");
    query.addBindValue(localPath);

    bool success = query.exec();
    if (!success) {
        qDebug() << query.lastError();
        return false;
    }

    return true;
}

bool DataBase::updateDownloadPath(const QString &downloadPath)
{
    QSqlQuery query(db);

    if (downloadPath.isEmpty()) {
        qDebug() << "传入的下载路径为空";
        return true;
    }
    query.prepare("UPDATE Other SET downloadPath = ?");
    query.addBindValue(downloadPath);

    bool success = query.exec();
    if (!success) {
        qDebug() << query.lastError();
        return false;
    }

    return true;
}

bool DataBase::deleteSong(const QString &songPath)
{
    QSqlQuery query(db);
    if (songPath.isEmpty()) {
        qDebug() << "要删除的歌曲不能为空";
        return true;
    }

    query.prepare("DELETE FROM LocalMusic WHERE songPath = ?");
    query.addBindValue(songPath);

    bool success = query.exec();
    if (!success) {
        qDebug() << query.lastError();
        return false;
    }

    return true;
}

bool DataBase::updateLocalMusic(const songMessage& item)
{
    QSqlQuery query(db);
    if (item.songPath.isEmpty()) {
        qDebug() << "要添加的歌曲不能为空";
        return true;
    }

    query.prepare("SELECT * FROM LocalMusic WHERE songPath = ?");
    query.addBindValue(item.songPath);
    bool success = query.exec();
    if (!success || query.next()) {
        qDebug() << "查询出错或者该歌曲已经存在";
        return false;
    }

    query.clear();

    // 存在的话不加入，不存在的话再加入
    query.prepare("INSERT INTO LocalMusic (songPath, singer, "
                  "songName, songLrcPath, coverPath, songID, songAllPath) VALUES (?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(item.songPath);
    query.addBindValue(item.singer);
    query.addBindValue(item.songName);
    query.addBindValue(item.songLrcPath);
    query.addBindValue(item.coverPath);
    query.addBindValue(item.songID);
    query.addBindValue(item.allPath);

    success = query.exec();
    if (!success) {
        qDebug() << query.lastError();
        return false;
    }

    return true;
}

bool DataBase::addMyFavoriteMusic(const songMessage &item)
{
    QSqlQuery query(db);

    query.prepare("INSERT INTO MyFavoriteList (songPath, singer, "
                  "songName, songLrcPath, coverPath, songID, songAllPath) VALUES (?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(item.songPath);
    query.addBindValue(item.singer);
    query.addBindValue(item.songName);
    query.addBindValue(item.songLrcPath);
    query.addBindValue(item.coverPath);
    query.addBindValue(item.songID);
    query.addBindValue(item.allPath);

    bool success = query.exec();
    if (!success) {
        qDebug() << "添加喜欢音乐失败: " << query.lastError();
        return false;
    }

    return true;
}

bool DataBase::removeFavoriteMusic(const QString &songPath)
{
    qDebug() << "要移出我喜欢: " << songPath;
    QSqlQuery query(db);

    query.prepare("DELETE FROM MyFavoriteList WHERE songPath = ?");
    query.addBindValue(songPath);

    bool success = query.exec();
    if (!success) {
        qDebug()  << "删除喜欢音乐失败: " << query.lastError();
        return false;
    }

    return true;
}

bool DataBase::queryInMyFavoriteList(const QString &songPath)
{
    QSqlQuery query(db);

    query.prepare("SELECT * FROM MyFavoriteList WHERE songPath = ?");
    query.addBindValue(songPath);
    bool success = query.exec();

    if (!success) {
        qDebug() << "查询歌曲是否在喜欢歌单中失败: " << query.lastError();
        return false;
    }

    if (query.next()) {
        return true;
    } else {
        return false;
    }
}

QStringList DataBase::searchMusic(const QString &songPath)
{
    QSqlQuery query(db);
    QStringList result;

    if (songPath.isEmpty()) {
        qDebug() << "要查询的歌曲不能为空";
        return result;
    }

    query.prepare("SELECT songPath, singer, "
                  "songName, songLrcPath, coverPath, songID, songAllPath FROM LocalMusic WHERE songPath = ?");
    query.addBindValue(songPath);
    bool success = query.exec();

    if (!success) {
        qDebug() << "查询歌曲失败" << query.lastError();
        return result;
    }

    if (query.next()) {
        result << query.value("songPath").toString()
               << query.value("singer").toString()
               << query.value("songName").toString()
               << query.value("songLrcPath").toString()
               << query.value("coverPath").toString()
               << query.value("songID").toString()
               << query.value("allSongPath").toString();
    } else {
        qDebug() << "未找到匹配的歌曲";
    }

    return result;

}

void DataBase::getLocalMusic(QList<songMessage> &list)
{
    QSqlQuery query(db);
    bool success = query.exec("SELECT songPath, singer, songName, songLrcPath, "
                              "coverPath FROM LocalMusic");

    if (!success) {
        qDebug() << "本地歌曲查询失败" << query.lastError();
        return;
    }

    while (query.next()) {
        songMessage temp;
        temp.songPath = query.value("songPath").toString();
        temp.singer = query.value("singer").toString();
        temp.songName = query.value("songName").toString();
        temp.songLrcPath = query.value("songLrcPath").toString();
        temp.coverPath = query.value("coverPath").toString();

        list.append(temp);
    }
}

void DataBase::getDataByPath(songMessage& song)
{
    QSqlQuery query(db);
    query.prepare("SELECT * FROM LocalMusic WHERE songPath = ?");
    query.addBindValue(song.songPath);

    bool success = query.exec();
    if (!success) {
        qDebug() << "查询失败" << query.lastError().text();
        return;
    }

    if (query.next()) {
        song.songPath = query.value("songPath").toString();
        song.singer = query.value("singer").toString();
        song.songName = query.value("songName").toString();
        song.songLrcPath = query.value("songLrcPath").toString();
        song.coverPath = query.value("coverPath").toString();
        song.songID = query.value("songID").toString();
        song.allPath = query.value("songAllPath").toString();
    } else {
        qDebug() << "记录不存在";
    }
}

bool DataBase::insertFavorite(const songMessage& item)
{
    QSqlQuery query(db);
    query.prepare(
        "INSERT INTO MyFavoriteList (songPath, songName, coverPath, songLrcPath, "
        "singer, songID, songAllPath) VALUES (?, ?, ?, ?, ?, ?, ?)");

    query.addBindValue(item.songPath);
    query.addBindValue(item.songName);
    query.addBindValue(item.coverPath);
    query.addBindValue(item.songLrcPath);
    query.addBindValue(item.singer);
    query.addBindValue(item.songID);
    query.addBindValue(item.allPath);

    if (!query.exec()) {
        qDebug() << "插入喜欢列表失败: " << query.lastError().text();
        return false;
    }
    return true;
}

void DataBase::getFavoriteMusic(QList<songMessage> &itemList)
{
    QSqlQuery query(db);
    query.prepare("SELECT songPath, songName, coverPath, songLrcPath, singer, songID, songAllPath FROM MyFavoriteList");

    if (!query.exec()) {
        qDebug() << "查询喜欢列表失败: " << query.lastError().text();
        return;
    }

    while (query.next()) {
        songMessage item;
        item.songPath = query.value(0).toString();
        item.songName = query.value(1).toString();
        item.coverPath = query.value(2).toString();
        item.songLrcPath = query.value(3).toString();
        item.singer = query.value(4).toString();
        item.songID = query.value(5).toString();
        item.allPath = query.value(6).toString();
        itemList.append(item);
    }
}



DataBase::~DataBase()
{

}
