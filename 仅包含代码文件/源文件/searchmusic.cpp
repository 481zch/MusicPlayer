#include "searchmusic.h"
#include <QDebug>
#include <QUrlQuery>
#include <QRegularExpression>

SearchMusic::SearchMusic(QObject *parent)
    : QObject{parent}
{
    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, &QNetworkAccessManager::finished, this, &SearchMusic::onSearchReply);
}

void SearchMusic::getReturnMessage(int page, const QString &songTitle, QList<songMessage> &list)
{
    songList = &list;
    // 请求URL
    QString url = "https://www.jbsou.cn/";

    // 请求头部
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded; charset=UTF-8");
    request.setRawHeader("Accept", "application/json, text/javascript, */*; q=0.01");
    request.setRawHeader("Origin", "https://www.jbsou.cn");
    request.setRawHeader("User-Agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/125.0.0.0 Safari/537.36 Edg/125.0.0.0");
    request.setRawHeader("X-Requested-With", "XMLHttpRequest");

    // POST请求的数据
    QByteArray postData;
    postData.append("input=" + songTitle.toUtf8());
    postData.append("&filter=name&type=netease&page=" + QString::number(page).toUtf8());

    qDebug() << "Sending POST request to" << url;
    qDebug() << "Post data:" << postData;

    // 发送POST请求
    networkManager->post(request, postData);
}

void SearchMusic::onSearchReply(QNetworkReply* reply)
{
    qDebug() << "Received reply from server";
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray response = reply->readAll();
        QString responseStr = QString::fromUtf8(response);

        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseStr.toUtf8());
        if (jsonDoc.isNull()) {
            qDebug() << "Failed to create JSON doc.";
            qDebug() << "Response was:" << responseStr;
            return;
        }
        if (!jsonDoc.isObject()) {
            qDebug() << "JSON is not an object.";
            qDebug() << "JSON is:" << jsonDoc;
            return;
        }

        QJsonObject jsonObj = jsonDoc.object();
        QJsonArray dataArray = jsonObj["data"].toArray();

        qDebug() << "Processing received data, dataArray size:" << dataArray.size();

        for (const QJsonValue& value : dataArray) {
            if (!value.isObject()) {
                qDebug() << "Data value is not an object.";
                continue;
            }

            QJsonObject obj = value.toObject();
            songMessage song;
            song.songName = obj["title"].toString();
            song.singer = obj["author"].toString();
            song.songPath = obj["url"].toString();
            song.coverPath = obj["pic"].toString();

            // 使用正则表达式提取songID
            QRegularExpression re("id=(\\d+)");
            QRegularExpressionMatch match = re.match(song.songPath);
            if (match.hasMatch()) {
                song.songID = match.captured(1);
            } else {
                song.songID = ""; // 如果没有匹配到，songID为空
            }
            song.songLrcPath = QString("http://music.163.com/api/song/lyric?id=%1&lv=1&tv=-1").arg(song.songID);
            song.allPath = song.songPath + "|" + song.songName + "|" + song.coverPath + "|" + song.songLrcPath + "|" + song.singer + "|" + song.songID;
            songList->append(song);
        }
    } else {
        qDebug() << "Error in reply:" << reply->errorString();
    }

    reply->deleteLater();
    emit searchFinish();
}


