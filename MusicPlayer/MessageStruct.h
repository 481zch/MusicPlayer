#ifndef MESSAGESTRUCT_H
#define MESSAGESTRUCT_H
#include <QObject>

struct songMessage{
    QString singer;
    QString songName;
    QString songPath; // 与来源有关（可以忽略）
    QString songLrcPath; // 与来源有关（可以解决）
    QString coverPath; //与来源有关（可以忽略）
    QString songID; // 歌曲的唯一标识，作为第二个主键存在
    QString allPath; // 记录了网络路径
};

// 顺序播放，随机播放，单曲循环，列表循环
enum playPattern{
    RandomList,
    singleCycle,
    CycleList
};

// 定义为常量的样式表
namespace Styles{
const QString normalSliderStyle = R"(QSlider::groove:horizontal {
    background: rgb(204, 204, 204);
    height: 4px;
    border-radius: 2px;  /* 确保槽的边角是圆滑的 */
    margin: 2px 0; /* 增加槽的上下边距，以确保手柄能完全显示 */
}

QSlider::groove:horizontal:hover {
    background: rgb(204, 204, 204);
    height: 6px;
    border-radius: 3px;  /* 确保槽的边角是圆滑的 */
    margin: 2px 0; /* 增加槽的上下边距，以确保手柄能完全显示 */
}

QSlider::sub-page:horizontal {
    background: rgb(255, 78, 78);
    height: 4px;
    border-radius: 2px;  /* 确保槽的边角是圆滑的 */
    margin: 2px 0; /* 增加槽的上下边距，以确保手柄能完全显示 */
}

QSlider::sub-page:horizontal:hover {
    background: rgb(255, 78, 78);
    height: 6px;
    border-radius: 3px;  /* 确保槽的边角是圆滑的 */
    margin: 2px 0; /* 增加槽的上下边距，以确保手柄能完全显示 */
}

QSlider::handle:horizontal {
    border-image: url(:/image/statusImage/handle3.png);
    width: 10px;
    height: 10px;  /* 确保图片显示正确 */
    margin: -3px 0px -3px 0px;  /* 通过调整上边距和下边距，确保手柄居中 */
}
)";

const QString loadingSliderStyle = R"(
QSlider::groove:horizontal {
    background: rgb(229, 229, 229);
    height: 4px;
    border-radius: 2px;
    margin: 2px 0;
}

QSlider::sub-page:horizontal {
    background: rgb(206, 206, 206);
    height: 4px;
    border-radius: 2px;
    margin: 2px 0;
}

QSlider::handle:horizontal {
    background: rgb(180, 180, 180);
    width: 0px;
    height: 0px;
    border-radius: 5px;
    margin: -3px 0px -3px 0px;
}
)";

const QString menuStyle = R"(
        QMenu {
            background-color: rgb(253, 253, 254);
            padding: 5px;
            border-radius: 15px;
        }
        QMenu::item {
            font-size: 10pt;
            color: rgb(0, 0, 0);
            background-color: rgb(253, 253, 254);
            padding: 8px 25px 6px 10px;
            margin: 4px 1px;
        }
        QMenu::item:selected {
            background-color: rgb(236, 236, 237);
        }
        QMenu::icon:checked {
            background: rgb(253, 253, 254);
            position: absolute;
            top: 1px;
            right: 1px;
            bottom: 1px;
            left: 1px;
        }
        QMenu::icon:checked:selected {
            background-color: rgb(236, 236, 237);
            background-image: url(:/space_selected.png);
        }
        QMenu::separator {
            height: 2px;
            background: rgb(235, 235, 236);
            margin-left: 10px;
            margin-right: 10px;
        }
    )";

const QString normalPlayBtn = R"(
        QPushButton
        {
            border-style:hidden;
            border-image: url(:/image/statusImage/play.png);
        }
        QPushButton:hover
        {
            border-style:hidden;
        };
    )";

const QString normalNextBtn = R"(
        QPushButton
        {
            border-style:hidden;
            border-image: url(:/image/statusImage/nextMusic.png);
        }
        QPushButton:hover
        {
            border-style:hidden;
            border-image: url(:/image/statusImage/nextMusic-hover.png);
        };
    )";

const QString normalLastBtn = R"(
        QPushButton
        {
            border-style:hidden;
            border-image:url(:/image/statusImage/lastMusic.png);
        }
        QPushButton:hover
        {
            border-style:hidden;
            border-image:url(:/image/statusImage/lastMusic-hover.png);
        };
    )";

const QString unselectedForPlayBtn = R"(
        QPushButton
        {
            border-style:hidden;
            border-image: url(:/image/statusImage/pause_unselected.png);
        }
        QPushButton:hover
        {
            border-style:hidden;
        };
    )";

const QString unselectedForLastBtn = R"(
        QPushButton
        {
            border-style:hidden;
            border-image: url(:/image/statusImage/last_unselected.png);
        }
    )";

const QString unselectedForNextBtn = R"(
        QPushButton
        {
            border-style:hidden;
            border-image: url(:/image/statusImage/next_unselected.png);
    }
    )";
}

#endif // MESSAGESTRUCT_H
