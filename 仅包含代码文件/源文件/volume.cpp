#include "volume.h"
#include "ui_volume.h"

Volume::Volume(QWidget *parent)
    : QSlider(parent)
    , ui(new Ui::Volume)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
}

int Volume::getUiValue()
{
    return ui->verticalSlider->value();
}

Volume::~Volume()
{
    delete ui;
}

void Volume::setVolume(int value)
{
    ui->verticalSlider->setValue(value);
}

// 添加背景图
void Volume::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/image/myMusic/Untitled1 (2).png"));
}

void Volume::on_verticalSlider_valueChanged(int value)
{
    emit curValue(value);
    emit changeValue(float(value) * 0.01);
}

