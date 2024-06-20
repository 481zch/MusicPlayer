/********************************************************************************
** Form generated from reading UI file 'volume.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOLUME_H
#define UI_VOLUME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Volume
{
public:
    QFormLayout *formLayout;
    QSlider *verticalSlider;

    void setupUi(QWidget *Volume)
    {
        if (Volume->objectName().isEmpty())
            Volume->setObjectName("Volume");
        Volume->resize(61, 128);
        Volume->setStyleSheet(QString::fromUtf8(""));
        formLayout = new QFormLayout(Volume);
        formLayout->setObjectName("formLayout");
        verticalSlider = new QSlider(Volume);
        verticalSlider->setObjectName("verticalSlider");
        verticalSlider->setStyleSheet(QString::fromUtf8("QSlider {\n"
"	padding-top: 15px;\n"
"	padding-bottom: 15px;\n"
"	padding-left:7px;\n"
"	padding-right:8px;\n"
"	border-radius: 5px;\n"
"}\n"
" \n"
"QSlider::add-page:vertical {\n"
"	background-color: rgb(236, 65, 65);	\n"
"	width:3px;\n"
"	border-radius: 2px;\n"
"}\n"
" \n"
"QSlider::sub-page:vertical {\n"
"	background-color: rgb(229, 229, 229);\n"
"	width:3px;\n"
"	border-radius: 2px;\n"
"}\n"
" \n"
"QSlider::groove:vertical {\n"
"	background:transparent;\n"
"	width:4px;\n"
"}\n"
" \n"
"QSlider::handle:vertical {\n"
"	height: 9px;\n"
"	width: 4px;\n"
"	margin: 0px -3px 0px -3px;\n"
"	border-radius: 4px;\n"
"	background-color: rgb(236, 65, 65);\n"
"}\n"
""));
        verticalSlider->setMaximum(100);
        verticalSlider->setValue(25);
        verticalSlider->setOrientation(Qt::Vertical);

        formLayout->setWidget(0, QFormLayout::LabelRole, verticalSlider);


        retranslateUi(Volume);

        QMetaObject::connectSlotsByName(Volume);
    } // setupUi

    void retranslateUi(QWidget *Volume)
    {
        Volume->setWindowTitle(QCoreApplication::translate("Volume", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Volume: public Ui_Volume {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOLUME_H
