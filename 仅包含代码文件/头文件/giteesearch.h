#ifndef GITEESEARCH_H
#define GITEESEARCH_H

#include <QObject>
#include <QPixmap>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class GiteeSearch : public QObject
{
    Q_OBJECT
public:
    explicit GiteeSearch(QObject *parent = nullptr);
    void downloadSongByUrl(const QString& url, const QString& filepath);
    void downloadCoverByUrl(const QString& url, const QString& filepath);
    void downloadLyricByUrl(const QString& url, const QString& filepath);

signals:
    void songDownLoadFinish();
    void songCoverDownLoadFinish();
    void lyricDownLoadFinish();

private slots:
    void onNetworkReply(QNetworkReply* reply);

private:
    QNetworkAccessManager* networkManager;
    QNetworkReply* currentReply;
};

#endif // GITEESEARCH_H
