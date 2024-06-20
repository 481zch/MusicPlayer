/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_23;
    QTabWidget *tab_5;
    QWidget *tab_3;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_local_MusicCount;
    QSpacerItem *horizontalSpacer_21;
    QPushButton *import_music;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *btn_local_playAll;
    QPushButton *btn_local_pattern;
    QSpacerItem *horizontalSpacer_22;
    QLineEdit *local_search;
    QTableView *local_music_tableView;
    QWidget *tab_4;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_download_MusicCount;
    QSpacerItem *horizontalSpacer_24;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *btn_download_playAll;
    QSpacerItem *horizontalSpacer_25;
    QLineEdit *download_search;
    QSpacerItem *verticalSpacer_2;
    QTableView *download_music_tableView;
    QWidget *tab_6;
    QGridLayout *gridLayout_7;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_favorite_songCount;
    QSpacerItem *horizontalSpacer_31;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *btn_favorite_playAll;
    QSpacerItem *horizontalSpacer_32;
    QLineEdit *favorite_search;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_7;
    QTableView *favorite_music_tableView;
    QWidget *tab;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_17;
    QSpacerItem *horizontalSpacer_33;
    QHBoxLayout *horizontalLayout_18;
    QPushButton *btn_online_playAll;
    QSpacerItem *horizontalSpacer_34;
    QTableView *online_music_tableView;
    QSpacerItem *verticalSpacer_4;
    QWidget *titleWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_titleWYY;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_back;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_next;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *search;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btn_skin;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btn_setting;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_5;
    QPushButton *btn_mini;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *btn_min;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *btn_changeSize;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *btn_close;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QListWidget *listwidget_local;
    QSpacerItem *verticalSpacer_5;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_singer_pic;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_song_name;
    QLabel *label_singer_name;
    QSpacerItem *horizontalSpacer_11;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *btn_lastMusic;
    QSpacerItem *horizontalSpacer_19;
    QPushButton *btn_pauseMusic;
    QSpacerItem *horizontalSpacer_20;
    QPushButton *btn_nextMusic;
    QSpacerItem *horizontalSpacer_26;
    QPushButton *btn_play_mode;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *horizontalSpacer_17;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_14;
    QLabel *label_time_start;
    QSlider *song_slider;
    QLabel *label_time;
    QSpacerItem *horizontalSpacer_15;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btn_volume;
    QPushButton *play_song_list;
    QSpacerItem *horizontalSpacer_13;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1133, 673);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalSpacer_23 = new QSpacerItem(9, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_23, 0, 0, 1, 1);

        tab_5 = new QTabWidget(tab_2);
        tab_5->setObjectName("tab_5");
        tab_5->setCursor(QCursor(Qt::PointingHandCursor));
        tab_5->setStyleSheet(QString::fromUtf8("QTabWidget::pane\n"
"{\n"
"	top:10px;\n"
"    border: none;  \n"
"}\n"
"\n"
"QTabBar::tab\n"
"{ \n"
"	background:transparent;\n"
"	border-bottom: 3px solid rgb(255,255,255);\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size:16px;\n"
"	padding-left:5px;\n"
"	padding-right:5px;\n"
"	min-width: 85px;\n"
"	min-height:30px;		\n"
"}\n"
" \n"
"QTabBar::tab:selected\n"
"{\n"
"	border-bottom: 3px solid rgb(236,65,65);\n"
"	color: rgb(55,55,55);\n"
"	font-size:20px;\n"
"	font-weight: bold;\n"
"}"));
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        gridLayout_3 = new QGridLayout(tab_3);
        gridLayout_3->setObjectName("gridLayout_3");
        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(verticalSpacer, 2, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_local_MusicCount = new QLabel(tab_3);
        label_local_MusicCount->setObjectName("label_local_MusicCount");
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(10);
        label_local_MusicCount->setFont(font);

        horizontalLayout_7->addWidget(label_local_MusicCount);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_21);

        import_music = new QPushButton(tab_3);
        import_music->setObjectName("import_music");
        import_music->setMinimumSize(QSize(100, 30));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font1.setPointSize(11);
        import_music->setFont(font1);
        import_music->setCursor(QCursor(Qt::PointingHandCursor));
        import_music->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{		\n"
"	\n"
"	background-color: rgb(166, 166, 166);\n"
"	border-radius:15px;\n"
"	color: rgb(255, 255, 255);\n"
"}"));

        horizontalLayout_7->addWidget(import_music);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        btn_local_playAll = new QPushButton(tab_3);
        btn_local_playAll->setObjectName("btn_local_playAll");
        btn_local_playAll->setMinimumSize(QSize(100, 30));
        btn_local_playAll->setFont(font1);
        btn_local_playAll->setCursor(QCursor(Qt::PointingHandCursor));
        btn_local_playAll->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{		\n"
"	background-color: rgb(236, 65, 65);\n"
"	border-radius:15px;\n"
"	color: rgb(255, 255, 255);\n"
"}"));

        horizontalLayout_8->addWidget(btn_local_playAll);

        btn_local_pattern = new QPushButton(tab_3);
        btn_local_pattern->setObjectName("btn_local_pattern");
        btn_local_pattern->setMinimumSize(QSize(100, 30));
        btn_local_pattern->setFont(font1);
        btn_local_pattern->setCursor(QCursor(Qt::PointingHandCursor));
        btn_local_pattern->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{		\n"
"	background-color: rgb(236, 65, 65);\n"
"	border-radius:15px;\n"
"	color: rgb(255, 255, 255);\n"
"}"));

        horizontalLayout_8->addWidget(btn_local_pattern);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_22);

        local_search = new QLineEdit(tab_3);
        local_search->setObjectName("local_search");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(8);
        sizePolicy.setHeightForWidth(local_search->sizePolicy().hasHeightForWidth());
        local_search->setSizePolicy(sizePolicy);
        local_search->setMinimumSize(QSize(180, 35));
        local_search->setMaximumSize(QSize(201, 35));
        local_search->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(247, 247, 247);\n"
"border-radius: 14px;\n"
"padding: 0px 0px 0px 0px;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_8->addWidget(local_search);


        verticalLayout_4->addLayout(horizontalLayout_8);


        gridLayout_3->addLayout(verticalLayout_4, 0, 0, 1, 1);

        local_music_tableView = new QTableView(tab_3);
        local_music_tableView->setObjectName("local_music_tableView");
        local_music_tableView->setStyleSheet(QString::fromUtf8("QHeaderView::section\n"
"{\n"
"    font-size:14px;\n"
"    background: transparent;\n"
"    border:none;\n"
"	padding-left:3px;\n"
"    margin-top: 5px;\n"
"    min-height:35px;\n"
"    max-height:35px;\n"
"}\n"
"QTableWidget\n"
"{\n"
"    font-size:14px;\n"
"    border: none;\n"
"    margin: 0px;\n"
"    padding: 0px;\n"
"    color: black;\n"
"}"));
        local_music_tableView->setAutoScroll(true);

        gridLayout_3->addWidget(local_music_tableView, 3, 0, 1, 1);

        tab_5->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        gridLayout_4 = new QGridLayout(tab_4);
        gridLayout_4->setObjectName("gridLayout_4");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_download_MusicCount = new QLabel(tab_4);
        label_download_MusicCount->setObjectName("label_download_MusicCount");
        label_download_MusicCount->setFont(font);

        horizontalLayout_9->addWidget(label_download_MusicCount);

        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_24);


        verticalLayout_5->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        btn_download_playAll = new QPushButton(tab_4);
        btn_download_playAll->setObjectName("btn_download_playAll");
        btn_download_playAll->setMinimumSize(QSize(100, 30));
        btn_download_playAll->setFont(font1);
        btn_download_playAll->setCursor(QCursor(Qt::PointingHandCursor));
        btn_download_playAll->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{		\n"
"	background-color: rgb(236, 65, 65);\n"
"	border-radius:15px;\n"
"	color: rgb(255, 255, 255);\n"
"}"));

        horizontalLayout_10->addWidget(btn_download_playAll);

        horizontalSpacer_25 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_25);

        download_search = new QLineEdit(tab_4);
        download_search->setObjectName("download_search");
        sizePolicy.setHeightForWidth(download_search->sizePolicy().hasHeightForWidth());
        download_search->setSizePolicy(sizePolicy);
        download_search->setMinimumSize(QSize(180, 35));
        download_search->setMaximumSize(QSize(201, 35));
        download_search->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(247, 247, 247);\n"
"border-radius: 14px;\n"
"padding: 0px 0px 0px 0px;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_10->addWidget(download_search);


        verticalLayout_5->addLayout(horizontalLayout_10);


        gridLayout_4->addLayout(verticalLayout_5, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout_4->addItem(verticalSpacer_2, 1, 0, 1, 1);

        download_music_tableView = new QTableView(tab_4);
        download_music_tableView->setObjectName("download_music_tableView");
        download_music_tableView->setStyleSheet(QString::fromUtf8("QHeaderView::section\n"
"{\n"
"    font-size:14px;\n"
"    background: transparent;\n"
"    border:none;\n"
"	padding-left:3px;\n"
"    margin-top: 5px;\n"
"    min-height:35px;\n"
"    max-height:35px;\n"
"}\n"
"QTableWidget\n"
"{\n"
"    font-size:14px;\n"
"    border: none;\n"
"    margin: 0px;\n"
"    padding: 0px;\n"
"    color: black;\n"
"}"));

        gridLayout_4->addWidget(download_music_tableView, 2, 0, 1, 1);

        tab_5->addTab(tab_4, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        gridLayout_7 = new QGridLayout(tab_6);
        gridLayout_7->setObjectName("gridLayout_7");
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        label_favorite_songCount = new QLabel(tab_6);
        label_favorite_songCount->setObjectName("label_favorite_songCount");
        label_favorite_songCount->setFont(font);

        horizontalLayout_15->addWidget(label_favorite_songCount);

        horizontalSpacer_31 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_31);


        verticalLayout_8->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        btn_favorite_playAll = new QPushButton(tab_6);
        btn_favorite_playAll->setObjectName("btn_favorite_playAll");
        btn_favorite_playAll->setMinimumSize(QSize(100, 30));
        btn_favorite_playAll->setFont(font1);
        btn_favorite_playAll->setCursor(QCursor(Qt::PointingHandCursor));
        btn_favorite_playAll->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{		\n"
"	background-color: rgb(236, 65, 65);\n"
"	border-radius:15px;\n"
"	color: rgb(255, 255, 255);\n"
"}"));

        horizontalLayout_16->addWidget(btn_favorite_playAll);

        horizontalSpacer_32 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_32);

        favorite_search = new QLineEdit(tab_6);
        favorite_search->setObjectName("favorite_search");
        sizePolicy.setHeightForWidth(favorite_search->sizePolicy().hasHeightForWidth());
        favorite_search->setSizePolicy(sizePolicy);
        favorite_search->setMinimumSize(QSize(180, 35));
        favorite_search->setMaximumSize(QSize(201, 35));
        favorite_search->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(247, 247, 247);\n"
"border-radius: 14px;\n"
"padding: 0px 0px 0px 0px;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_16->addWidget(favorite_search);


        verticalLayout_8->addLayout(horizontalLayout_16);


        gridLayout_7->addLayout(verticalLayout_8, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout_7->addItem(verticalSpacer_3, 0, 0, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout_7->addItem(verticalSpacer_7, 2, 0, 1, 1);

        favorite_music_tableView = new QTableView(tab_6);
        favorite_music_tableView->setObjectName("favorite_music_tableView");
        favorite_music_tableView->setStyleSheet(QString::fromUtf8("QHeaderView::section\n"
"{\n"
"    font-size:14px;\n"
"    background: transparent;\n"
"    border:none;\n"
"	padding-left:3px;\n"
"    margin-top: 5px;\n"
"    min-height:35px;\n"
"    max-height:35px;\n"
"}\n"
"QTableWidget\n"
"{\n"
"    font-size:14px;\n"
"    border: none;\n"
"    margin: 0px;\n"
"    padding: 0px;\n"
"    color: black;\n"
"}"));

        gridLayout_7->addWidget(favorite_music_tableView, 3, 0, 1, 1);

        tab_5->addTab(tab_6, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        gridLayout_5 = new QGridLayout(tab);
        gridLayout_5->setObjectName("gridLayout_5");
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        horizontalSpacer_33 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_33);


        verticalLayout_9->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        btn_online_playAll = new QPushButton(tab);
        btn_online_playAll->setObjectName("btn_online_playAll");
        btn_online_playAll->setMinimumSize(QSize(100, 30));
        btn_online_playAll->setFont(font1);
        btn_online_playAll->setCursor(QCursor(Qt::PointingHandCursor));
        btn_online_playAll->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{		\n"
"	background-color: rgb(236, 65, 65);\n"
"	border-radius:15px;\n"
"	color: rgb(255, 255, 255);\n"
"}"));

        horizontalLayout_18->addWidget(btn_online_playAll);

        horizontalSpacer_34 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_34);


        verticalLayout_9->addLayout(horizontalLayout_18);


        gridLayout_5->addLayout(verticalLayout_9, 0, 0, 1, 1);

        online_music_tableView = new QTableView(tab);
        online_music_tableView->setObjectName("online_music_tableView");
        online_music_tableView->setStyleSheet(QString::fromUtf8("QHeaderView::section\n"
"{\n"
"    font-size:14px;\n"
"    background: transparent;\n"
"    border:none;\n"
"	padding-left:3px;\n"
"    margin-top: 5px;\n"
"    min-height:35px;\n"
"    max-height:35px;\n"
"}\n"
"QTableWidget\n"
"{\n"
"    font-size:14px;\n"
"    border: none;\n"
"    margin: 0px;\n"
"    padding: 0px;\n"
"    color: black;\n"
"}"));

        gridLayout_5->addWidget(online_music_tableView, 2, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout_5->addItem(verticalSpacer_4, 1, 0, 1, 1);

        tab_5->addTab(tab, QString());

        gridLayout_2->addWidget(tab_5, 0, 1, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 1, 1, 1, 1);

        titleWidget = new QWidget(centralwidget);
        titleWidget->setObjectName("titleWidget");
        titleWidget->setMinimumSize(QSize(1115, 60));
        titleWidget->setMaximumSize(QSize(16777215, 60));
        titleWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(236, 65, 65);"));
        horizontalLayout = new QHBoxLayout(titleWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 25, 0);
        horizontalSpacer = new QSpacerItem(8, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_titleWYY = new QLabel(titleWidget);
        label_titleWYY->setObjectName("label_titleWYY");
        label_titleWYY->setMinimumSize(QSize(141, 28));
        label_titleWYY->setMaximumSize(QSize(16777215, 40));
        label_titleWYY->setStyleSheet(QString::fromUtf8("font: 14pt \"Microsoft YaHei UI\";\n"
"color: rgb(255, 255, 255);"));
        label_titleWYY->setFrameShape(QFrame::NoFrame);
        label_titleWYY->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_titleWYY);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btn_back = new QPushButton(titleWidget);
        btn_back->setObjectName("btn_back");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_back->sizePolicy().hasHeightForWidth());
        btn_back->setSizePolicy(sizePolicy1);
        btn_back->setMaximumSize(QSize(21, 21));
        btn_back->setCursor(QCursor(Qt::PointingHandCursor));
        btn_back->setStyleSheet(QString::fromUtf8("background-color:rgb(217,59,59);\n"
"border-radius:10px;\n"
"border-image: url(:/image/titleImage/backPage.png);"));

        horizontalLayout->addWidget(btn_back);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        btn_next = new QPushButton(titleWidget);
        btn_next->setObjectName("btn_next");
        sizePolicy1.setHeightForWidth(btn_next->sizePolicy().hasHeightForWidth());
        btn_next->setSizePolicy(sizePolicy1);
        btn_next->setMaximumSize(QSize(21, 21));
        btn_next->setCursor(QCursor(Qt::PointingHandCursor));
        btn_next->setStyleSheet(QString::fromUtf8("background-color:rgb(217,59,59);\n"
"border-radius:10px;\n"
"border-image: url(:/image/titleImage/nextPage.png);\n"
""));

        horizontalLayout->addWidget(btn_next);

        horizontalSpacer_4 = new QSpacerItem(100, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        search = new QLineEdit(titleWidget);
        search->setObjectName("search");
        sizePolicy.setHeightForWidth(search->sizePolicy().hasHeightForWidth());
        search->setSizePolicy(sizePolicy);
        search->setMinimumSize(QSize(200, 35));
        search->setMaximumSize(QSize(210, 35));
        search->setStyleSheet(QString::fromUtf8("background: rgb(225,62,62);\n"
"border-radius: 14px;\n"
"color: rgb(255, 255, 255);\n"
"font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout->addWidget(search);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        btn_skin = new QPushButton(titleWidget);
        btn_skin->setObjectName("btn_skin");
        btn_skin->setMinimumSize(QSize(18, 17));
        btn_skin->setMaximumSize(QSize(17, 17));
        btn_skin->setCursor(QCursor(Qt::PointingHandCursor));
        btn_skin->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-style: hidden;\n"
"	border-image: url(:/image/titleImage/skin.png);\n"
"}\n"
"QPushButton: hover\n"
"{\n"
"	border-style: hidden;\n"
"	border-image: url(:/image/titleImage/skinHover.png);\n"
"}\n"
"\n"
"\n"
""));
        btn_skin->setIconSize(QSize(30, 20));

        horizontalLayout->addWidget(btn_skin);

        horizontalSpacer_6 = new QSpacerItem(15, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        btn_setting = new QPushButton(titleWidget);
        btn_setting->setObjectName("btn_setting");
        btn_setting->setMinimumSize(QSize(19, 18));
        btn_setting->setMaximumSize(QSize(17, 17));
        btn_setting->setCursor(QCursor(Qt::PointingHandCursor));
        btn_setting->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-style: hidden;\n"
"	border-image: url(:/image/titleImage/set.png);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	border-style: hidden;\n"
"	border-image: url(:/image/titleImage/setHover.png);\n"
"}"));

        horizontalLayout->addWidget(btn_setting);

        horizontalSpacer_7 = new QSpacerItem(15, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        pushButton_5 = new QPushButton(titleWidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setMinimumSize(QSize(10, 17));
        pushButton_5->setMaximumSize(QSize(21, 17));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-style: hidden;\n"
"	border-image: url(:/image/titleImage/separate.png);\n"
"}"));

        horizontalLayout->addWidget(pushButton_5);

        btn_mini = new QPushButton(titleWidget);
        btn_mini->setObjectName("btn_mini");
        btn_mini->setMinimumSize(QSize(17, 17));
        btn_mini->setMaximumSize(QSize(17, 17));
        btn_mini->setCursor(QCursor(Qt::PointingHandCursor));
        btn_mini->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-style:hidden;\n"
"	border-image: url(:/image/titleImage/mini.png);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	border-style:hidden;\n"
"	border-image: url(:/image/titleImage/miniHover.png);\n"
"}\n"
"\n"
""));
        btn_mini->setIconSize(QSize(30, 20));

        horizontalLayout->addWidget(btn_mini);

        horizontalSpacer_8 = new QSpacerItem(15, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btn_min = new QPushButton(titleWidget);
        btn_min->setObjectName("btn_min");
        btn_min->setMinimumSize(QSize(17, 17));
        btn_min->setMaximumSize(QSize(17, 17));
        btn_min->setCursor(QCursor(Qt::PointingHandCursor));
        btn_min->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-style: hidden;\n"
"	border-image: url(:/image/titleImage/min.png);\n"
"}\n"
"QPushButton: hover\n"
"{\n"
"	border-style: hidden;\n"
"	border-image: url(:/image/titleImage/minHover.png);\n"
"}\n"
"\n"
"\n"
""));
        btn_min->setIconSize(QSize(30, 20));

        horizontalLayout->addWidget(btn_min);

        horizontalSpacer_9 = new QSpacerItem(15, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        btn_changeSize = new QPushButton(titleWidget);
        btn_changeSize->setObjectName("btn_changeSize");
        btn_changeSize->setMinimumSize(QSize(17, 17));
        btn_changeSize->setMaximumSize(QSize(17, 17));
        btn_changeSize->setCursor(QCursor(Qt::PointingHandCursor));
        btn_changeSize->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-style: hidden;\n"
"	border-image: url(:/image/titleImage/max.png);\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	border-style: hidden;\n"
"	border-image: url(:/image/titleImage/maxHover.png);\n"
"}"));

        horizontalLayout->addWidget(btn_changeSize);

        horizontalSpacer_10 = new QSpacerItem(15, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_10);

        btn_close = new QPushButton(titleWidget);
        btn_close->setObjectName("btn_close");
        btn_close->setMinimumSize(QSize(17, 17));
        btn_close->setMaximumSize(QSize(17, 17));
        btn_close->setCursor(QCursor(Qt::PointingHandCursor));
        btn_close->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-style:hidden;\n"
"	border-image: url(:/image/titleImage/quit.png);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	border-style:hidden;\n"
"	border-image: url(:image/titleImage/quitHover.png);\n"
"}\n"
"\n"
""));
        btn_close->setIconSize(QSize(30, 20));

        horizontalLayout->addWidget(btn_close);


        gridLayout->addWidget(titleWidget, 0, 0, 1, 2);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        widget_2->setMinimumSize(QSize(209, 430));
        widget_2->setMaximumSize(QSize(209, 16777215));
        widget_2->setStyleSheet(QString::fromUtf8("border-style:none;\n"
"border-bottom:3px solid rgb(240, 240, 240);"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName("verticalLayout");
        label_2 = new QLabel(widget_2);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(60);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setMinimumSize(QSize(57, 20));
        label_2->setMaximumSize(QSize(57, 20));
        QFont font2;
        font2.setPointSize(10);
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(121, 121, 121);\n"
"border-style:none;\n"
"margin-top: 6px;"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2->setMargin(0);

        verticalLayout->addWidget(label_2);

        listwidget_local = new QListWidget(widget_2);
        new QListWidgetItem(listwidget_local);
        new QListWidgetItem(listwidget_local);
        new QListWidgetItem(listwidget_local);
        new QListWidgetItem(listwidget_local);
        listwidget_local->setObjectName("listwidget_local");
        listwidget_local->setMinimumSize(QSize(196, 150));
        listwidget_local->setMaximumSize(QSize(196, 159));
        listwidget_local->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        listwidget_local->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    font: normal 14px;\n"
"    border: 0px;\n"
"    color: rgb(0,0,0);\n"
"    background: rgb(255,255,255);    \n"
"}\n"
"\n"
"* {\n"
"    outline: 0px;\n"
"}\n"
"\n"
"QListWidget::Item {\n"
"    height: 36px;  /* \344\277\256\346\255\243\351\253\230\345\272\246\345\200\274 */\n"
"    border: 0px solid rgb(255,255,255);    \n"
"    padding-top: 1px;\n"
"}\n"
"\n"
"QListWidget::Item:hover {\n"
"    background: rgb(246,246,247);    \n"
"}\n"
"\n"
"QListWidget::Item:selected {\n"
"    font: bold 14px;  /* \344\277\256\346\255\243\345\255\227\344\275\223\346\240\267\345\274\217 */\n"
"    color: rgb(0,0,0);\n"
"    border: 0px;\n"
"    background: rgb(246,246,247);    \n"
"}\n"
""));
        listwidget_local->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listwidget_local->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listwidget_local->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listwidget_local->setProperty("showDropIndicator", QVariant(false));

        verticalLayout->addWidget(listwidget_local);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        label_2->raise();
        listwidget_local->raise();

        gridLayout->addWidget(widget_2, 1, 0, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 55));
        horizontalLayout_6 = new QHBoxLayout(widget);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_singer_pic = new QLabel(widget);
        label_singer_pic->setObjectName("label_singer_pic");
        label_singer_pic->setMinimumSize(QSize(51, 51));
        label_singer_pic->setMaximumSize(QSize(51, 51));
        label_singer_pic->setCursor(QCursor(Qt::PointingHandCursor));
        label_singer_pic->setStyleSheet(QString::fromUtf8("border-radius:6px;\n"
"border-image: url(:/image/statusImage/unKnowSinger.png);\n"
""));

        horizontalLayout_6->addWidget(label_singer_pic);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_song_name = new QLabel(widget);
        label_song_name->setObjectName("label_song_name");
        label_song_name->setMinimumSize(QSize(120, 16));
        label_song_name->setMaximumSize(QSize(120, 16));

        horizontalLayout_2->addWidget(label_song_name);


        verticalLayout_2->addLayout(horizontalLayout_2);

        label_singer_name = new QLabel(widget);
        label_singer_name->setObjectName("label_singer_name");
        label_singer_name->setMinimumSize(QSize(100, 15));
        label_singer_name->setMaximumSize(QSize(100, 15));

        verticalLayout_2->addWidget(label_singer_name);


        horizontalLayout_6->addLayout(verticalLayout_2);

        horizontalSpacer_11 = new QSpacerItem(30, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_11);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_16 = new QSpacerItem(140, 16, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_16);

        btn_lastMusic = new QPushButton(widget);
        btn_lastMusic->setObjectName("btn_lastMusic");
        btn_lastMusic->setEnabled(false);
        btn_lastMusic->setMaximumSize(QSize(20, 20));
        QFont font3;
        font3.setStyleStrategy(QFont::PreferAntialias);
        btn_lastMusic->setFont(font3);
        btn_lastMusic->setCursor(QCursor(Qt::PointingHandCursor));
        btn_lastMusic->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-style:hidden;\n"
"	border-image: url(:/image/statusImage/last_unselected.png);\n"
"}"));

        horizontalLayout_3->addWidget(btn_lastMusic);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_19);

        btn_pauseMusic = new QPushButton(widget);
        btn_pauseMusic->setObjectName("btn_pauseMusic");
        btn_pauseMusic->setEnabled(false);
        btn_pauseMusic->setMaximumSize(QSize(20, 24));
        btn_pauseMusic->setCursor(QCursor(Qt::PointingHandCursor));
        btn_pauseMusic->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-style:hidden;\n"
"	/*border-image: url(:/image/statusImage/play.png);*/\n"
"	\n"
"	border-image: url(:/image/statusImage/pause_unselected.png);\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	border-style:hidden;\n"
"};"));
        btn_pauseMusic->setIconSize(QSize(20, 20));
        btn_pauseMusic->setCheckable(true);
        btn_pauseMusic->setChecked(false);

        horizontalLayout_3->addWidget(btn_pauseMusic);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_20);

        btn_nextMusic = new QPushButton(widget);
        btn_nextMusic->setObjectName("btn_nextMusic");
        btn_nextMusic->setEnabled(false);
        btn_nextMusic->setMaximumSize(QSize(20, 20));
        btn_nextMusic->setCursor(QCursor(Qt::PointingHandCursor));
        btn_nextMusic->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-style:hidden;\n"
"	border-image: url(:/image/statusImage/next_unselected.png);\n"
"}"));

        horizontalLayout_3->addWidget(btn_nextMusic);

        horizontalSpacer_26 = new QSpacerItem(25, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_26);

        btn_play_mode = new QPushButton(widget);
        btn_play_mode->setObjectName("btn_play_mode");
        btn_play_mode->setMinimumSize(QSize(24, 24));
        btn_play_mode->setMaximumSize(QSize(24, 24));
        btn_play_mode->setCursor(QCursor(Qt::PointingHandCursor));
        btn_play_mode->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-style:hidden;\n"
"	\n"
"	border-image: url(:/image/statusImage/play_cycle.png);\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	border-style:hidden;\n"
"	border-image: url(:/image/statusImage/play_cycle_hover.png);\n"
"};\n"
""));

        horizontalLayout_3->addWidget(btn_play_mode);

        horizontalSpacer_18 = new QSpacerItem(140, 16, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_18);

        horizontalSpacer_17 = new QSpacerItem(30, 16, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_17);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_14 = new QSpacerItem(110, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_14);

        label_time_start = new QLabel(widget);
        label_time_start->setObjectName("label_time_start");

        horizontalLayout_4->addWidget(label_time_start);

        song_slider = new QSlider(widget);
        song_slider->setObjectName("song_slider");
        song_slider->setMinimumSize(QSize(350, 15));
        song_slider->setMaximumSize(QSize(350, 15));
        song_slider->setCursor(QCursor(Qt::ArrowCursor));
        song_slider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    background: rgb(204, 204, 204);\n"
"    height: 4px;\n"
"    border-radius: 2px;  /* \347\241\256\344\277\235\346\247\275\347\232\204\350\276\271\350\247\222\346\230\257\345\234\206\346\273\221\347\232\204 */\n"
"    margin: 2px 0; /* \345\242\236\345\212\240\346\247\275\347\232\204\344\270\212\344\270\213\350\276\271\350\267\235\357\274\214\344\273\245\347\241\256\344\277\235\346\211\213\346\237\204\350\203\275\345\256\214\345\205\250\346\230\276\347\244\272 */\n"
"}\n"
"\n"
"QSlider::groove:horizontal:hover {\n"
"    background: rgb(204, 204, 204);\n"
"    height: 6px;\n"
"    border-radius: 3px;  /* \347\241\256\344\277\235\346\247\275\347\232\204\350\276\271\350\247\222\346\230\257\345\234\206\346\273\221\347\232\204 */\n"
"    margin: 2px 0; /* \345\242\236\345\212\240\346\247\275\347\232\204\344\270\212\344\270\213\350\276\271\350\267\235\357\274\214\344\273\245\347\241\256\344\277\235\346\211\213\346\237\204\350\203\275\345\256\214\345\205\250\346\230\276\347\244\272"
                        " */\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"    background: rgb(255, 78, 78);\n"
"    height: 4px;\n"
"    border-radius: 2px;  /* \347\241\256\344\277\235\346\247\275\347\232\204\350\276\271\350\247\222\346\230\257\345\234\206\346\273\221\347\232\204 */\n"
"    margin: 2px 0; /* \345\242\236\345\212\240\346\247\275\347\232\204\344\270\212\344\270\213\350\276\271\350\267\235\357\274\214\344\273\245\347\241\256\344\277\235\346\211\213\346\237\204\350\203\275\345\256\214\345\205\250\346\230\276\347\244\272 */\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal:hover {\n"
"    background: rgb(255, 78, 78);\n"
"    height: 6px;\n"
"    border-radius: 3px;  /* \347\241\256\344\277\235\346\247\275\347\232\204\350\276\271\350\247\222\346\230\257\345\234\206\346\273\221\347\232\204 */\n"
"    margin: 2px 0; /* \345\242\236\345\212\240\346\247\275\347\232\204\344\270\212\344\270\213\350\276\271\350\267\235\357\274\214\344\273\245\347\241\256\344\277\235\346\211\213\346\237\204\350\203\275\345\256\214\345\205\250\346\230"
                        "\276\347\244\272 */\n"
"}\n"
"\n"
"QSlider::handle:horizontal {	\n"
"    border-image: url(:/image/statusImage/handle3.png);	\n"
"    width: 10px;\n"
"    height: 10px;  /* \347\241\256\344\277\235\345\233\276\347\211\207\346\230\276\347\244\272\346\255\243\347\241\256 */\n"
"    margin: -3px 0px -3px 0px;  /* \351\200\232\350\277\207\350\260\203\346\225\264\344\270\212\350\276\271\350\267\235\345\222\214\344\270\213\350\276\271\350\267\235\357\274\214\347\241\256\344\277\235\346\211\213\346\237\204\345\261\205\344\270\255 */\n"
"}\n"
""));
        song_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(song_slider);

        label_time = new QLabel(widget);
        label_time->setObjectName("label_time");

        horizontalLayout_4->addWidget(label_time);

        horizontalSpacer_15 = new QSpacerItem(110, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_15);


        verticalLayout_3->addLayout(horizontalLayout_4);


        horizontalLayout_6->addLayout(verticalLayout_3);

        horizontalSpacer_12 = new QSpacerItem(30, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_12);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(13);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        btn_volume = new QPushButton(widget);
        btn_volume->setObjectName("btn_volume");
        btn_volume->setMaximumSize(QSize(25, 25));
        btn_volume->setCursor(QCursor(Qt::PointingHandCursor));
        btn_volume->setMouseTracking(true);
        btn_volume->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-style:hidden;\n"
"	border-image: url(:/image/statusImage/volume.png);\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	border-style:hidden;\n"
"	border-image: url(:/image/statusImage/volume-hover.png);\n"
"};"));
        btn_volume->setCheckable(true);

        horizontalLayout_5->addWidget(btn_volume);

        play_song_list = new QPushButton(widget);
        play_song_list->setObjectName("play_song_list");
        play_song_list->setMaximumSize(QSize(25, 25));
        play_song_list->setCursor(QCursor(Qt::PointingHandCursor));
        play_song_list->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-style:hidden;\n"
"	border-image: url(:/image/statusImage/playlist.png);\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	border-style:hidden;\n"
"	border-image: url(:/image/statusImage/playlist-hover.png);\n"
"};"));

        horizontalLayout_5->addWidget(play_song_list);


        horizontalLayout_6->addLayout(horizontalLayout_5);

        horizontalSpacer_13 = new QSpacerItem(10, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_13);


        gridLayout->addWidget(widget, 2, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        tab_5->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_local_MusicCount->setText(QCoreApplication::translate("MainWindow", "\346\234\254\345\234\260\345\205\261\346\234\2110\351\246\226\346\255\214\346\233\262", nullptr));
        import_music->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\205\245\351\237\263\344\271\220", nullptr));
        btn_local_playAll->setText(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276\345\205\250\351\203\250", nullptr));
        btn_local_pattern->setText(QCoreApplication::translate("MainWindow", "\345\214\271\351\205\215\351\237\263\344\271\220", nullptr));
        local_search->setText(QString());
        local_search->setPlaceholderText(QCoreApplication::translate("MainWindow", " \346\220\234\347\264\242\346\234\254\345\234\260\351\237\263\344\271\220\357\274\210\345\260\232\346\234\252\345\256\236\347\216\260\357\274\211", nullptr));
        tab_5->setTabText(tab_5->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\346\234\254\345\234\260\351\237\263\344\271\220", nullptr));
        label_download_MusicCount->setText(QCoreApplication::translate("MainWindow", "\345\205\261\344\270\213\350\275\2750\351\246\226\346\255\214\346\233\262", nullptr));
        btn_download_playAll->setText(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276\345\205\250\351\203\250", nullptr));
        download_search->setText(QString());
        download_search->setPlaceholderText(QCoreApplication::translate("MainWindow", " \346\220\234\347\264\242\345\234\250\347\272\277\351\237\263\344\271\220\357\274\210\345\260\232\346\234\252\345\256\236\347\216\260\357\274\211", nullptr));
        tab_5->setTabText(tab_5->indexOf(tab_4), QCoreApplication::translate("MainWindow", "\345\234\250\347\272\277\351\237\263\344\271\220", nullptr));
        label_favorite_songCount->setText(QCoreApplication::translate("MainWindow", "\345\205\2610\351\246\226\346\255\214\346\233\262", nullptr));
        btn_favorite_playAll->setText(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276\345\205\250\351\203\250", nullptr));
        favorite_search->setText(QString());
        favorite_search->setPlaceholderText(QCoreApplication::translate("MainWindow", " \346\220\234\347\264\242\346\210\221\345\226\234\346\254\242\347\232\204\351\237\263\344\271\220\357\274\210\345\260\232\346\234\252\345\256\236\347\216\260\357\274\211", nullptr));
        tab_5->setTabText(tab_5->indexOf(tab_6), QCoreApplication::translate("MainWindow", "\346\210\221\345\226\234\346\254\242\347\232\204\351\237\263\344\271\220", nullptr));
        btn_online_playAll->setText(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276\345\205\250\351\203\250", nullptr));
        tab_5->setTabText(tab_5->indexOf(tab), QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242\351\237\263\344\271\220", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QString());
        label_titleWYY->setText(QCoreApplication::translate("MainWindow", "\351\237\263\344\271\220", nullptr));
#if QT_CONFIG(tooltip)
        btn_back->setToolTip(QCoreApplication::translate("MainWindow", "\346\232\202\346\234\252\345\256\236\347\216\260", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_back->setText(QString());
#if QT_CONFIG(tooltip)
        btn_next->setToolTip(QCoreApplication::translate("MainWindow", "\346\232\202\346\234\252\345\256\236\347\216\260", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_next->setText(QString());
#if QT_CONFIG(tooltip)
        search->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        search->setPlaceholderText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242\346\237\245\346\211\276\351\237\263\344\271\220", nullptr));
#if QT_CONFIG(tooltip)
        btn_skin->setToolTip(QCoreApplication::translate("MainWindow", "\346\232\202\346\234\252\345\256\236\347\216\260", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_skin->setText(QString());
#if QT_CONFIG(tooltip)
        btn_setting->setToolTip(QCoreApplication::translate("MainWindow", "\346\232\202\346\234\252\345\256\236\347\216\260", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_setting->setText(QString());
        pushButton_5->setText(QString());
#if QT_CONFIG(tooltip)
        btn_mini->setToolTip(QCoreApplication::translate("MainWindow", "\346\232\202\346\234\252\345\256\236\347\216\260", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_mini->setText(QString());
        btn_min->setText(QString());
        btn_changeSize->setText(QString());
#if QT_CONFIG(tooltip)
        btn_close->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        btn_close->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\210\221\347\232\204\351\237\263\344\271\220", nullptr));

        const bool __sortingEnabled = listwidget_local->isSortingEnabled();
        listwidget_local->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listwidget_local->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "\346\234\254\345\234\260\351\237\263\344\271\220", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listwidget_local->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "\345\234\250\347\272\277\351\237\263\344\271\220", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listwidget_local->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("MainWindow", "\346\210\221\345\226\234\346\254\242\347\232\204\351\237\263\344\271\220", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listwidget_local->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242\351\237\263\344\271\220", nullptr));
        listwidget_local->setSortingEnabled(__sortingEnabled);

        label_singer_pic->setText(QString());
        label_song_name->setText(QCoreApplication::translate("MainWindow", "\346\227\240\346\255\214\346\233\262", nullptr));
        label_singer_name->setText(QCoreApplication::translate("MainWindow", "\346\232\202\346\227\240\346\222\255\346\224\276", nullptr));
#if QT_CONFIG(tooltip)
        btn_lastMusic->setToolTip(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\200\351\246\226", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_lastMusic->setText(QString());
#if QT_CONFIG(tooltip)
        btn_pauseMusic->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        btn_pauseMusic->setText(QString());
#if QT_CONFIG(tooltip)
        btn_nextMusic->setToolTip(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\351\246\226", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_nextMusic->setText(QString());
        btn_play_mode->setText(QString());
        label_time_start->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\346\227\266\351\227\264", nullptr));
        label_time->setText(QCoreApplication::translate("MainWindow", "\346\200\273\345\205\261\346\227\266\351\227\264", nullptr));
#if QT_CONFIG(tooltip)
        btn_volume->setToolTip(QCoreApplication::translate("MainWindow", "\351\237\263\351\207\217", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_volume->setText(QString());
#if QT_CONFIG(tooltip)
        play_song_list->setToolTip(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276\345\210\227\350\241\250", nullptr));
#endif // QT_CONFIG(tooltip)
        play_song_list->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
