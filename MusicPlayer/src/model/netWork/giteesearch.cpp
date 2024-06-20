#include "GiteeSearch.h"

GiteeSearch::GiteeSearch(QObject *parent) : QObject(parent)
{
    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, &QNetworkAccessManager::finished, this, &GiteeSearch::onNetworkReply);
}

void GiteeSearch::getSongCoverByUrl(const QString& url)
{
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    currentRequestType = Image;
    currentReply = networkManager->get(request);
}

void GiteeSearch::getTextFileByUrl(const QString& url)
{
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    currentRequestType = Text;
    currentReply = networkManager->get(request);
}

void GiteeSearch::onNetworkReply(QNetworkReply* reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray data = reply->readAll();
        if (currentRequestType == Image) {
            QPixmap pixmap;
            pixmap.loadFromData(data);
            emit songCoverReady(pixmap);
        } else if (currentRequestType == Text) {
            QString content = QString::fromUtf8(data);
            emit textFileReady(content);
        }
    }
    reply->deleteLater();
}
