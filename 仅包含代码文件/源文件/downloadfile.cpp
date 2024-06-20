#include "downloadfile.h"
#include <QFile>
#include <QDebug>
#include <QFileInfo>

DownloadFile::DownloadFile(QObject *parent)
    : QObject(parent), networkManager(new QNetworkAccessManager(this))
{
    connect(networkManager, &QNetworkAccessManager::finished, this, &DownloadFile::onNetworkReply);
    origin = 0;
}

void DownloadFile::downloadFile(const QString& url, const QString& filepath, const QString& type, int origin)
{
    this->origin = origin;
    QUrl qurl(url);
    QNetworkRequest request(qurl);
    QNetworkReply* reply = networkManager->get(request);

    DownloadTask task;
    task.filepath = filepath;
    task.type = type;

    activeDownloads.insert(reply, task);
}

void DownloadFile::onNetworkReply(QNetworkReply* reply)
{
    if (!activeDownloads.contains(reply)) {
        reply->deleteLater();
        return;
    }

    DownloadTask task = activeDownloads.take(reply);

    if (reply->error() == QNetworkReply::NoError) {
        QFile file(task.filepath);
        if (file.open(QIODevice::WriteOnly)) {
            if (origin == 1 && task.type == "lyric") {
                // 对歌词进行特殊解析下载写入
                QByteArray response = reply->readAll();
                QString responseStr = QString::fromUtf8(response);
                QJsonDocument jsonDoc = QJsonDocument::fromJson(responseStr.toUtf8());
                QJsonObject jsonObj = jsonDoc.object();
                QJsonObject lrcObj = jsonObj["lrc"].toObject();
                QString originalLyric = lrcObj["lyric"].toString();

                QJsonObject tlyricObj = jsonObj["tlyric"].toObject();
                QString translatedLyric = tlyricObj["lyric"].toString();

                if (!translatedLyric.isEmpty()) {
                    originalLyric += "\n" + translatedLyric;
                }

                file.write(originalLyric.toUtf8());
                file.close();
            }
            else {
                file.write(reply->readAll());
                file.close();
            }

            if (task.type == "song") {
                QFileInfo fileInfo(task.filepath);
                if (fileInfo.size() < 1 * 1024 * 1024) {
                    qWarning() << "下载失败: 音乐版权问题" ;
                    emit downloadError();
                }
                else {
                    qDebug() << "歌曲文件下载完成";
                    emit songDownloadFinish(task.filepath);
                }
            } else if (task.type == "pic") {
                qDebug() << "封面文件下载完成";
                emit songCoverDownloadFinish(task.filepath);
            } else if (task.type == "lyric") {
                qDebug() << "歌词文件下载完成";
                emit lyricDownloadFinish(task.filepath);
            }
        } else {
            qWarning() << "无法打开文件来写: " << task.filepath;
        }
    } else {
        qWarning() << "下载失败: " << reply->errorString();
    }
    reply->deleteLater();
}
