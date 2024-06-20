#ifndef DOWNLOADFILE_H
#define DOWNLOADFILE_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

class DownloadFile : public QObject
{
    Q_OBJECT
public:
    explicit DownloadFile(QObject *parent = nullptr);
    void downloadFile(const QString& url, const QString& filepath, const QString& type, int origin);

signals:
    void songDownloadFinish(const QString& filepath);
    void songCoverDownloadFinish(const QString& filepath);
    void lyricDownloadFinish(const QString& filepath);
    void downloadError();

private slots:
    void onNetworkReply(QNetworkReply* reply);

private:
    int origin;
    QNetworkAccessManager* networkManager;
    struct DownloadTask {
        QString filepath;
        QString type;
    };
    QHash<QNetworkReply*, DownloadTask> activeDownloads;
};

#endif // DOWNLOADFILE_H
