#include "lyric.h"

Lyric::Lyric(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Lyric)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    // 默认渐变色
    this->setStyleSheet(R"(
    QWidget#widget_2 {
        border-style: none;
        background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,
                                                      stop:0 rgba(255, 0, 0, 255),
                                                      stop:1 rgba(255, 255, 255, 255));
    }
    )");

    ui->playCover->setStyleSheet("border-radius: 100px;");
}

void Lyric::textChanged(QStringList &list)
{
    if (!ui->lyricDisplay->scene()) {
        ui->lyricDisplay->setScene(new QGraphicsScene(this));
    }
    ui->lyricDisplay->scene()->clear();
    QGraphicsScene *scene = new QGraphicsScene(this);

    for (int i = 0; i < list.size(); ++i) {
        QGraphicsTextItem *textItem = new QGraphicsTextItem(list[i]);

        // 设置第四句歌词黑体加粗
        if (i == 3) {
            QFont font = textItem->font();
            font.setBold(true);
            font.setPointSize(15);
            textItem->setFont(font);
            textItem->setDefaultTextColor(Qt::black);
        } else {
            // 其他歌词灰色字体
            QFont font = textItem->font();
            font.setPointSize(15);
            textItem->setFont(font);
            textItem->setDefaultTextColor(QColor(180, 180, 180));
        }

        // 设置每行歌词的位置
        textItem->setPos(0, i * 30);
        scene->addItem(textItem);
    }
    ui->lyricDisplay->setScene(scene);
}

Lyric::~Lyric()
{
    delete ui;
}
