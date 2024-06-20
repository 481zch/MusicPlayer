#include "searchapi.h"

SearchAPI::SearchAPI(QObject *parent)
    : QObject{parent}
{
    search = new SearchMusic(this);
}

void SearchAPI::getMessageByText(QList<songMessage> &list, int page, const QString &text)
{
    search->getReturnMessage(page, text, list);
}
