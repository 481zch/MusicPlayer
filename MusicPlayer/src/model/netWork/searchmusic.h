#ifndef SEARCHMUSIC_H
#define SEARCHMUSIC_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "MessageStruct.h"

class SearchMusic : public QObject
{
    Q_OBJECT
public:
    explicit SearchMusic(QObject *parent = nullptr);
    void getReturnMessage(int page, const QString& songTitle, QList<songMessage>& list);

signals:
    void searchFinish();

private slots:
    void onSearchReply(QNetworkReply* reply);

private:
    QNetworkAccessManager* networkManager;
    QList<songMessage>* songList;
};

#endif // SEARCHMUSIC_H
