#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <mutex>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include "MessageStruct.h"


// 使用单例模式
class DataBase: QObject
{
    Q_OBJECT
public:
    static DataBase* getInstance();
    bool updateLocalPath(const QString& localPath = "");
    bool updateDownloadPath(const QString& downloadPath = "");
    bool deleteSong(const QString& songPath);
    bool updateLocalMusic(const songMessage& item);
    bool addMyFavoriteMusic(const songMessage& item);
    bool removeFavoriteMusic(const QString& songPath);
    bool queryInMyFavoriteList(const QString& songPath);
    QStringList searchMusic(const QString& songPath);
    void getLocalMusic(QList<songMessage> &list);
    void getDataByPath(songMessage& song);
    bool insertFavorite(const songMessage& item);
    void getFavoriteMusic(QList<songMessage> &itemList);

private:
    explicit DataBase(QObject* parent = nullptr);
    ~DataBase();
    DataBase(const DataBase&) = delete;
    DataBase& operator=(const DataBase&) = delete;

    bool createDataBase();
    void checkAndCreateTables();

private:
    static std::once_flag m_flag;
    static DataBase* m_pInstance;
    QSqlDatabase db;
    QStringList tables;
};

#endif // DATABASE_H
