/********************************************************************************
** Form generated from reading UI file 'playlistview.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYLISTVIEW_H
#define UI_PLAYLISTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayListView
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_removeAll;
    QTableView *curPlayListView;

    void setupUi(QWidget *PlayListView)
    {
        if (PlayListView->objectName().isEmpty())
            PlayListView->setObjectName("PlayListView");
        PlayListView->resize(388, 300);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PlayListView->sizePolicy().hasHeightForWidth());
        PlayListView->setSizePolicy(sizePolicy);
        PlayListView->setMinimumSize(QSize(200, 0));
        PlayListView->setMaximumSize(QSize(388, 16777215));
        PlayListView->setStyleSheet(QString::fromUtf8("background-color: rgb(250, 250, 250);"));
        verticalLayout = new QVBoxLayout(PlayListView);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(PlayListView);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Meiryo UI\";"));
        label->setMargin(5);

        verticalLayout->addWidget(label);

        widget = new QWidget(PlayListView);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 50));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 20, 0);
        horizontalSpacer = new QSpacerItem(300, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_removeAll = new QPushButton(widget);
        btn_removeAll->setObjectName("btn_removeAll");
        btn_removeAll->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	font: 11pt \"Microsoft YaHei UI\";\n"
"	color: rgb(140,169,162);\n"
"	border-style:hidden;\n"
"}\n"
"QPushButton:hover\n"
"\n"
"{\n"
"	font: 11pt \"Microsoft YaHei UI\";\n"
"	color: rgb(85, 170, 255);\n"
"	border-style:hidden;\n"
"}\n"
""));

        horizontalLayout->addWidget(btn_removeAll);


        verticalLayout->addWidget(widget);

        curPlayListView = new QTableView(PlayListView);
        curPlayListView->setObjectName("curPlayListView");
        curPlayListView->setMinimumSize(QSize(200, 0));
        curPlayListView->setStyleSheet(QString::fromUtf8("QHeaderView::section\n"
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
        curPlayListView->setAutoScrollMargin(6);

        verticalLayout->addWidget(curPlayListView);


        retranslateUi(PlayListView);

        QMetaObject::connectSlotsByName(PlayListView);
    } // setupUi

    void retranslateUi(QWidget *PlayListView)
    {
        PlayListView->setWindowTitle(QCoreApplication::translate("PlayListView", "Form", nullptr));
        label->setText(QCoreApplication::translate("PlayListView", "  \345\275\223\345\211\215\346\222\255\346\224\276", nullptr));
        btn_removeAll->setText(QCoreApplication::translate("PlayListView", "\346\270\205\347\251\272\345\210\227\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayListView: public Ui_PlayListView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYLISTVIEW_H
