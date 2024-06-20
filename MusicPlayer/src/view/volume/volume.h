#ifndef VOLUME_H
#define VOLUME_H

#include <QWidget>
#include <QPainter>
#include <QSlider>

namespace Ui {
class Volume;
}

class Volume : public QSlider
{
    Q_OBJECT

public:
    explicit Volume(QWidget *parent = nullptr);
    int getUiValue();
    ~Volume();

signals:
    void curValue(int value);
    void changeValue(float value);

public slots:
    void setVolume(int value);

protected:
    void paintEvent(QPaintEvent* event);

private slots:
    void on_verticalSlider_valueChanged(int value);

private:
    Ui::Volume *ui;
    int loudness;   // 当前进度条数值，对应的音量大小
};

#endif // VOLUME_H
