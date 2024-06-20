/********************************************************************************
** Form generated from reading UI file 'lyric.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LYRIC_H
#define UI_LYRIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lyric
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QGraphicsView *lyricDisplay;
    QPushButton *btn_down;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *playCover;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *Lyric)
    {
        if (Lyric->objectName().isEmpty())
            Lyric->setObjectName("Lyric");
        Lyric->resize(682, 471);
        Lyric->setStyleSheet(QString::fromUtf8("background:transparent;"));
        verticalLayout = new QVBoxLayout(Lyric);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(Lyric);
        widget_2->setObjectName("widget_2");
        widget_2->setStyleSheet(QString::fromUtf8("border-style:hidden;\n"
""));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(widget_2);
        widget->setObjectName("widget");
        widget->setStyleSheet(QString::fromUtf8("background:transparent;"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lyricDisplay = new QGraphicsView(widget);
        lyricDisplay->setObjectName("lyricDisplay");
        lyricDisplay->setMinimumSize(QSize(0, 0));
        lyricDisplay->setMaximumSize(QSize(10000000, 10000000));
        QFont font;
        font.setStyleStrategy(QFont::PreferAntialias);
        font.setHintingPreference(QFont::PreferDefaultHinting);
        lyricDisplay->setFont(font);
        lyricDisplay->setTabletTracking(false);
        lyricDisplay->setStyleSheet(QString::fromUtf8("border-style:hidden;\n"
"background:transparent;"));
        lyricDisplay->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lyricDisplay->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lyricDisplay->setInteractive(false);
        lyricDisplay->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lyricDisplay);


        gridLayout->addWidget(widget, 1, 1, 1, 1);

        btn_down = new QPushButton(widget_2);
        btn_down->setObjectName("btn_down");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_down->sizePolicy().hasHeightForWidth());
        btn_down->setSizePolicy(sizePolicy);
        btn_down->setMinimumSize(QSize(25, 25));
        btn_down->setMaximumSize(QSize(25, 25));
        btn_down->setCursor(QCursor(Qt::PointingHandCursor));
        btn_down->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-style:hidden;\n"
"	border-image: url(:/image/myMusic/down_hover.png);\n"
"	background:transparent;\n"
"\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	border-style:hidden;\n"
"	border-image: url(:/image/myMusic/down.png);\n"
"	background:transparent;\n"
"\n"
"};\n"
"\n"
"\n"
""));

        gridLayout->addWidget(btn_down, 0, 0, 1, 1);

        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName("widget_3");
        widget_3->setStyleSheet(QString::fromUtf8("border-style:hidden;\n"
"background:transparent;"));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        playCover = new QLabel(widget_3);
        playCover->setObjectName("playCover");
        playCover->setMinimumSize(QSize(200, 200));
        playCover->setMaximumSize(QSize(200, 200));
        playCover->setStyleSheet(QString::fromUtf8("border-image: url(:/image/myMusic/cd.png);\n"
"border-radius: 100px;"));

        horizontalLayout->addWidget(playCover);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget_3, 1, 0, 1, 1);


        verticalLayout->addWidget(widget_2);


        retranslateUi(Lyric);

        QMetaObject::connectSlotsByName(Lyric);
    } // setupUi

    void retranslateUi(QWidget *Lyric)
    {
        Lyric->setWindowTitle(QCoreApplication::translate("Lyric", "Form", nullptr));
        btn_down->setText(QString());
        playCover->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Lyric: public Ui_Lyric {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LYRIC_H
