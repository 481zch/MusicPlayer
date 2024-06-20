#ifndef SEARCHAPI_H
#define SEARCHAPI_H

#include <QObject>
#include "src/model/netWork/searchmusic.h"

class SearchAPI : public QObject
{
    Q_OBJECT
public:
    explicit SearchAPI(QObject *parent = nullptr);
    void getMessageByText(QList<songMessage>& list, int page, const QString& text);

signals:

public:
    SearchMusic* search;
};

#endif // SEARCHAPI_H
