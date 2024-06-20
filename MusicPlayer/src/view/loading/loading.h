#ifndef LOADING_H
#define LOADING_H

#include <QWidget>
#include <QMovie>
#include "ui_loading.h"

namespace Ui {
class Loading;
}

class Loading : public QWidget
{
    Q_OBJECT

public:
    explicit Loading(QWidget *parent = nullptr);
    ~Loading();

public:
    QMovie* movie;

private:
    Ui::Loading *ui;
};

#endif // LOADING_H
