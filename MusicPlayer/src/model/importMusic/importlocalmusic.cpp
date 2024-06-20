#include "importlocalmusic.h"

#include <qmessagebox.h>

ImportLocalMusic::ImportLocalMusic(QObject* parent): QObject{parent}
{
    audioFormat = {"mp3", "wav", "flac", "aac"};
    picFormat = {"jpg", "png", "jpeg", "bmp"};
    instance = DataBase::getInstance();
}

void ImportLocalMusic::dealWithPath(const QString &localPath, QList<songMessage>& result)
{
    // 进行存储
    if (!instance->updateLocalPath(localPath)) {
        qDebug() << "上传数据库本地路径失败";
        return;
    }

    searchLocalSong(localPath, result);

    // 对result进行筛选
    result.erase(std::remove_if(result.begin(), result.end(),
                                [this](const songMessage& item) {
                                    bool status = instance->updateLocalMusic(item);
                                    return !status;
                                }),
                 result.end());
}

// 扫描路径下的文件夹，文件夹是有一定要求的，如果不符合格式要求，则进行忽略
void ImportLocalMusic::searchLocalSong(const QString &path, QList<songMessage>& result)
{
    QDir rootDir(path);
    if (!rootDir.exists()) {
        qDebug() << "路径不存在";
        return;
    }

    // 获取一级目录
    foreach (const QFileInfo& entry, rootDir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot)) {
        // 处理每一个一级文件夹
        processDirectory(QDir(entry.filePath()), result);
    }

    // 遍历其余目标格式文件
    foreach (const QFileInfo& fileInfo, rootDir.entryInfoList(QDir::Files)) {
        QString suffix = fileInfo.suffix().toLower();
        if (audioFormat.contains(suffix)) {
            songMessage song{"未知歌手", fileInfo.completeBaseName(), fileInfo.filePath(), "", "", "", ""};
            result.append(song);
        }
    }

    if (result.size() == 0) {
        QMessageBox::information(nullptr, "查找音乐", "文件夹下未检索到音乐");
    }
}

void ImportLocalMusic::processDirectory(const QDir &dir, QList<songMessage> &result)
{
    repairPath(dir);
    songMessage song;
    foreach (const QFileInfo& fileInfo, dir.entryInfoList(QDir::Files)) {
        QString suffix = fileInfo.suffix().toLower();
        if (suffix == "txt") {
            QFile file(fileInfo.absoluteFilePath());
            if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QTextStream in(&file);

                while (!in.atEnd()) {
                    QString line = in.readLine();
                    int colonIndex = line.indexOf(':');
                    if (colonIndex == -1) continue;

                    QString key = line.left(colonIndex).trimmed();
                    QString value = line.mid(colonIndex + 1).trimmed();

                    if (key == "singer") song.singer = value;
                    else if (key == "songName") song.songName = value;
                    else if (key == "songPath") song.songPath = value;
                    else if (key == "songLrcPath") song.songLrcPath = value;
                    else if (key == "coverPath") song.coverPath = value;
                    else if (key == "songID") song.songID = value;
                    else if (key == "allPath") song.allPath = value;
                }
                file.close();
            }
        }
    }

    if (song.songPath != "") result.append(song);
}

void ImportLocalMusic::repairPath(const QDir &dir) {
    QString songPath, lyricPath, coverPath;

    foreach (const QFileInfo& fileInfo, dir.entryInfoList(QDir::Files)) {
        QString suffix = fileInfo.suffix().toLower();
        if (audioFormat.contains(suffix)) songPath = fileInfo.absoluteFilePath();
        else if (picFormat.contains(suffix)) coverPath = fileInfo.absoluteFilePath();
        else if (suffix == "lrc") lyricPath = fileInfo.absoluteFilePath();
    }

    // 修改 message.txt 文件中的路径
    QString messageFilePath = dir.absoluteFilePath("message.txt");
    if (QFile::exists(messageFilePath)) {
        QFile messageFile(messageFilePath);
        if (messageFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
            QTextStream in(&messageFile);
            QStringList lines;
            while (!in.atEnd()) {
                QString line = in.readLine();
                int colonIndex = line.indexOf(':');
                if (colonIndex != -1) {
                    QString key = line.left(colonIndex).trimmed();
                    if (key == "songPath" && !songPath.isEmpty()) {
                        line = key + ":" + songPath;
                    } else if (key == "songLrcPath" && !lyricPath.isEmpty()) {
                        line = key + ":" + lyricPath;
                    } else if (key == "coverPath" && !coverPath.isEmpty()) {
                        line = key + ":" + coverPath;
                    }
                }
                lines.append(line);
            }
            messageFile.resize(0); // 清空文件内容
            QTextStream out(&messageFile);
            for (const QString &line : lines) {
                out << line << "\n";
            }
            messageFile.close();
        }
    }
}


void ImportLocalMusic::getLocalMusic(QList<songMessage> &result)
{
    instance->getLocalMusic(result);
}

ImportLocalMusic::~ImportLocalMusic()
{

}
