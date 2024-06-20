#ifndef IMPORTLOCALMUSIC_H
#define IMPORTLOCALMUSIC_H

#include <QDir>
#include <QObject>
#include "src/model/database/database.h"
#include "MessageStruct.h"


class ImportLocalMusic:QObject
{
    Q_OBJECT
public:
    ImportLocalMusic(QObject* parent = nullptr);
    ~ImportLocalMusic();
    void searchLocalSong(const QString& path, QList<songMessage>& result);
    void getLocalMusic(QList<songMessage>& result);

public slots:
    void dealWithPath(const QString& localPath, QList<songMessage>& result);

private:
    void processDirectory(const QDir& dir, QList<songMessage>& result);
    void repairPath(const QDir& dir);


private:
    DataBase* instance;
    QStringList audioFormat;
    QStringList picFormat;
};

#endif // IMPORTLOCALMUSIC_H
