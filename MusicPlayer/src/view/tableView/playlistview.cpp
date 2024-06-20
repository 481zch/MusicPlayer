#include "playlistview.h"
#include <QMenu>

PlayListView::PlayListView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PlayListView)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
}


PlayListView::~PlayListView()
{
    delete ui;
}

