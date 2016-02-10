/********************************************************************************
** Form generated from reading UI file 'adafruit_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADAFRUIT_WIDGET_H
#define UI_ADAFRUIT_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_AdafruitWidget
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_Open;
    QPushButton *pushButton_Close;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_Quaternion;
    QPushButton *pushButton_Calib;
    QLabel *label_Calib;
    QLabel *label_Quaternion;
    QPushButton *pushButton_Init;
    QVTKWidget *qvtkwidget;

    void setupUi(QWidget *AdafruitWidget)
    {
        if (AdafruitWidget->objectName().isEmpty())
            AdafruitWidget->setObjectName(QStringLiteral("AdafruitWidget"));
        AdafruitWidget->resize(435, 294);
        gridLayout = new QGridLayout(AdafruitWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_Open = new QPushButton(AdafruitWidget);
        pushButton_Open->setObjectName(QStringLiteral("pushButton_Open"));

        gridLayout->addWidget(pushButton_Open, 0, 0, 1, 1);

        pushButton_Close = new QPushButton(AdafruitWidget);
        pushButton_Close->setObjectName(QStringLiteral("pushButton_Close"));

        gridLayout->addWidget(pushButton_Close, 1, 0, 1, 1);

        groupBox = new QGroupBox(AdafruitWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setEnabled(false);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton_Quaternion = new QPushButton(groupBox);
        pushButton_Quaternion->setObjectName(QStringLiteral("pushButton_Quaternion"));

        gridLayout_2->addWidget(pushButton_Quaternion, 1, 0, 1, 1);

        pushButton_Calib = new QPushButton(groupBox);
        pushButton_Calib->setObjectName(QStringLiteral("pushButton_Calib"));

        gridLayout_2->addWidget(pushButton_Calib, 2, 0, 1, 1);

        label_Calib = new QLabel(groupBox);
        label_Calib->setObjectName(QStringLiteral("label_Calib"));

        gridLayout_2->addWidget(label_Calib, 2, 1, 1, 1);

        label_Quaternion = new QLabel(groupBox);
        label_Quaternion->setObjectName(QStringLiteral("label_Quaternion"));

        gridLayout_2->addWidget(label_Quaternion, 1, 1, 1, 1);

        pushButton_Init = new QPushButton(groupBox);
        pushButton_Init->setObjectName(QStringLiteral("pushButton_Init"));

        gridLayout_2->addWidget(pushButton_Init, 0, 0, 1, 1);

        qvtkwidget = new QVTKWidget(groupBox);
        qvtkwidget->setObjectName(QStringLiteral("qvtkwidget"));

        gridLayout_2->addWidget(qvtkwidget, 3, 0, 1, 2);


        gridLayout->addWidget(groupBox, 2, 0, 1, 1);


        retranslateUi(AdafruitWidget);

        QMetaObject::connectSlotsByName(AdafruitWidget);
    } // setupUi

    void retranslateUi(QWidget *AdafruitWidget)
    {
        AdafruitWidget->setWindowTitle(QApplication::translate("AdafruitWidget", "Form", 0));
        pushButton_Open->setText(QApplication::translate("AdafruitWidget", "Open", 0));
        pushButton_Close->setText(QApplication::translate("AdafruitWidget", "Close", 0));
        groupBox->setTitle(QApplication::translate("AdafruitWidget", "Measurements", 0));
        pushButton_Quaternion->setText(QApplication::translate("AdafruitWidget", "Get Quat", 0));
        pushButton_Calib->setText(QApplication::translate("AdafruitWidget", "Get Calib", 0));
        label_Calib->setText(QApplication::translate("AdafruitWidget", "Calib", 0));
        label_Quaternion->setText(QApplication::translate("AdafruitWidget", "Quaternion", 0));
        pushButton_Init->setText(QApplication::translate("AdafruitWidget", "Init", 0));
    } // retranslateUi

};

namespace Ui {
    class AdafruitWidget: public Ui_AdafruitWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADAFRUIT_WIDGET_H
