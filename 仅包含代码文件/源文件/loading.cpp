#include "loading.h"

Loading::Loading(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Loading)
{
    ui->setupUi(this);
    movie = new QMovie(":/image/statusImage/loading.gif");
    ui->label->setMovie(movie);
}

Loading::~Loading()
{
    delete movie;
    delete ui;
}
