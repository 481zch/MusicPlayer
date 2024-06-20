#include "cache.h"


Cache::Cache(QObject *parent)
    : QObject{parent}, storage(100 * 1024 * 1024) // 100MB 缓存空间
{
    download = new DownloadFile(this);

    // 确定缓存目录
    filePrefix = QStandardPaths::writableLocation(QStandardPaths::CacheLocation);
    QDir().mkpath(filePrefix);
    connect(download, &DownloadFile::songDownloadFinish, this, &Cache::downloadFinish);
    connect(download, &DownloadFile::songCoverDownloadFinish, this, &Cache::downloadFinish);
    connect(download, &DownloadFile::lyricDownloadFinish, this, &Cache::downloadFinish);
}

void Cache::transformHttp(const songMessage &song, int type)
{
    // 缓存中查询
    if (mp.count(song.songPath)) {
        emit downloadFinished(mp[song.songPath]);
        return;
    }
    res = song;
    // 接着依次下载歌曲，封面，歌词
    // 子文件夹名字
    QString subfolder = sanitizeFileName(song.songName + "-" + song.singer);
    QString subfolderPath = filePrefix + "/" + subfolder;

    QDir().mkpath(subfolderPath);

    QString songType = song.songPath.split(".").last();
    QString coverType;
    // 提取封面类型
    if (type == 1) {
        int dotIndex = song.coverPath.lastIndexOf('.');
        int questionMarkIndex = song.coverPath.indexOf('?', dotIndex);
        if (dotIndex != -1 && questionMarkIndex != -1) {
            coverType = song.coverPath.mid(dotIndex + 1, questionMarkIndex - dotIndex - 1);
        } else if (dotIndex != -1) {
            coverType = song.coverPath.mid(dotIndex + 1);
        } else {
            coverType = "jpg";
        }
    } else {
        coverType = song.coverPath.split(".").last();
    }
    QString lyricType = "lrc";

    // 组装文件路径
    QString songFilePath = subfolderPath + "/" + sanitizeFileName(song.songName) + "." + songType;
    QString coverFilePath = subfolderPath + "/" + sanitizeFileName(song.songName) + "." + coverType;
    QString lyricFilePath = subfolderPath + "/" + sanitizeFileName(song.songName) + "." + lyricType;

    res.songPath = songFilePath;
    res.coverPath = coverFilePath;
    res.songLrcPath = lyricFilePath;

    mp[song.songPath] = res;

    downloadCount = 0;

    // 对于搜索得到的音乐，需要进行特殊解析
    download->downloadFile(song.songLrcPath, lyricFilePath, "lyric", type);
    download->downloadFile(song.songPath, songFilePath, "song", type);
    download->downloadFile(song.coverPath, coverFilePath, "pic", type);

}

QString Cache::sanitizeFileName(const QString& fileName)
{
    QString sanitized = fileName;
    sanitized.replace("/", "_");
    sanitized.replace("\\", "_");
    sanitized.replace(":", "_");
    sanitized.replace("*", "_");
    sanitized.replace("?", "_");
    sanitized.replace("\"", "_");
    sanitized.replace("<", "_");
    sanitized.replace(">", "_");
    sanitized.replace("|", "_");
    return sanitized;
}


void Cache::formatLyricsFile(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Cannot open file for reading:" << filePath;
        return;
    }

    QTextStream in(&file);
    QString content = in.readAll();
    file.close();

    QStringList lines = content.split("\\r\\n", Qt::SkipEmptyParts);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        qWarning() << "Cannot open file for writing:" << filePath;
        return;
    }

    QTextStream out(&file);
    for (const QString &line : lines) {
        out << line << "\n";
    }

    file.close();
}

void Cache::downloadFinish()
{
    ++ downloadCount;
    if (downloadCount == 3) {
        // 对歌词文件进行格式一致化(只在当前作业中进行)
        if (!res.songPath.startsWith("http://music.163.com/")) {
            formatLyricsFile(res.songLrcPath);
        }
        emit downloadFinished(res);
        downloadCount = 0;
    }
}

void Cache::clearFiles()
{
    qDebug() << "开始清空缓存文件";
    QDir dir(filePrefix);
    if (dir.exists()) {
        dir.removeRecursively();
        qDebug() << "文件清理完成";
    } else {
        qDebug() << "缓存文件夹不存在";
    }
    emit clearFinish();
}

void Cache::setCacheSize(int num)
{
    storage = num * 1024 * 1024;
}
