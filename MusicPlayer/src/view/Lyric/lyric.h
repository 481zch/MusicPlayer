#ifndef LYRIC_H
#define LYRIC_H

#include <QWidget>
#include <QEvent>
#include <QGraphicsTextItem>
#include "ui_lyric.h"

namespace Ui {
class Lyric;
}

class Lyric : public QWidget
{
    Q_OBJECT

public:
    explicit Lyric(QWidget *parent = nullptr);
    void textChanged(QStringList &lsit);
    ~Lyric();

public:
    Ui::Lyric *ui;
};

#endif // LYRIC_H
