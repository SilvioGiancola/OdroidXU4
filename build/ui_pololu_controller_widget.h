/********************************************************************************
** Form generated from reading UI file 'pololu_controller_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POLOLU_CONTROLLER_WIDGET_H
#define UI_POLOLU_CONTROLLER_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PololuControllerWidget
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_Open;
    QPushButton *pushButton_Close;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QSlider *horizontalSlider_Servo5;
    QSpinBox *spinBox_Servo0;
    QLabel *label;
    QLabel *label_2;
    QSlider *horizontalSlider_Servo0;
    QSpinBox *spinBox_Servo2;
    QSpinBox *spinBox_Servo1;
    QLabel *label_5;
    QSpinBox *spinBox_Servo4;
    QSlider *horizontalSlider_Servo1;
    QLabel *label_3;
    QLabel *label_6;
    QSlider *horizontalSlider_Servo2;
    QSlider *horizontalSlider_Servo4;
    QSlider *horizontalSlider_Servo3;
    QLabel *label_4;
    QSpinBox *spinBox_Servo3;
    QSpinBox *spinBox_Servo5;
    QPushButton *pushButton_Servo0;
    QPushButton *pushButton_Servo1;
    QPushButton *pushButton_Servo2;
    QPushButton *pushButton_Servo3;
    QPushButton *pushButton_Servo4;
    QPushButton *pushButton_Servo5;

    void setupUi(QWidget *PololuControllerWidget)
    {
        if (PololuControllerWidget->objectName().isEmpty())
            PololuControllerWidget->setObjectName(QStringLiteral("PololuControllerWidget"));
        PololuControllerWidget->resize(584, 330);
        gridLayout = new QGridLayout(PololuControllerWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_Open = new QPushButton(PololuControllerWidget);
        pushButton_Open->setObjectName(QStringLiteral("pushButton_Open"));

        gridLayout->addWidget(pushButton_Open, 0, 0, 1, 1);

        pushButton_Close = new QPushButton(PololuControllerWidget);
        pushButton_Close->setObjectName(QStringLiteral("pushButton_Close"));

        gridLayout->addWidget(pushButton_Close, 1, 0, 1, 1);

        groupBox = new QGroupBox(PololuControllerWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setEnabled(false);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalSlider_Servo5 = new QSlider(groupBox);
        horizontalSlider_Servo5->setObjectName(QStringLiteral("horizontalSlider_Servo5"));
        horizontalSlider_Servo5->setMinimum(1000);
        horizontalSlider_Servo5->setMaximum(2000);
        horizontalSlider_Servo5->setValue(1500);
        horizontalSlider_Servo5->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_Servo5, 5, 1, 1, 1);

        spinBox_Servo0 = new QSpinBox(groupBox);
        spinBox_Servo0->setObjectName(QStringLiteral("spinBox_Servo0"));
        spinBox_Servo0->setMinimum(1000);
        spinBox_Servo0->setMaximum(2000);
        spinBox_Servo0->setSingleStep(100);
        spinBox_Servo0->setValue(1500);

        gridLayout_2->addWidget(spinBox_Servo0, 0, 2, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        horizontalSlider_Servo0 = new QSlider(groupBox);
        horizontalSlider_Servo0->setObjectName(QStringLiteral("horizontalSlider_Servo0"));
        horizontalSlider_Servo0->setMinimum(1000);
        horizontalSlider_Servo0->setMaximum(2000);
        horizontalSlider_Servo0->setValue(1500);
        horizontalSlider_Servo0->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_Servo0, 0, 1, 1, 1);

        spinBox_Servo2 = new QSpinBox(groupBox);
        spinBox_Servo2->setObjectName(QStringLiteral("spinBox_Servo2"));
        spinBox_Servo2->setMinimum(1000);
        spinBox_Servo2->setMaximum(2000);
        spinBox_Servo2->setSingleStep(100);
        spinBox_Servo2->setValue(1500);

        gridLayout_2->addWidget(spinBox_Servo2, 2, 2, 1, 1);

        spinBox_Servo1 = new QSpinBox(groupBox);
        spinBox_Servo1->setObjectName(QStringLiteral("spinBox_Servo1"));
        spinBox_Servo1->setMinimum(1000);
        spinBox_Servo1->setMaximum(2000);
        spinBox_Servo1->setSingleStep(100);
        spinBox_Servo1->setValue(1500);

        gridLayout_2->addWidget(spinBox_Servo1, 1, 2, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 4, 0, 1, 1);

        spinBox_Servo4 = new QSpinBox(groupBox);
        spinBox_Servo4->setObjectName(QStringLiteral("spinBox_Servo4"));
        spinBox_Servo4->setMinimum(1000);
        spinBox_Servo4->setMaximum(2000);
        spinBox_Servo4->setSingleStep(100);
        spinBox_Servo4->setValue(1500);

        gridLayout_2->addWidget(spinBox_Servo4, 4, 2, 1, 1);

        horizontalSlider_Servo1 = new QSlider(groupBox);
        horizontalSlider_Servo1->setObjectName(QStringLiteral("horizontalSlider_Servo1"));
        horizontalSlider_Servo1->setMinimum(1000);
        horizontalSlider_Servo1->setMaximum(2000);
        horizontalSlider_Servo1->setValue(1500);
        horizontalSlider_Servo1->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_Servo1, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 5, 0, 1, 1);

        horizontalSlider_Servo2 = new QSlider(groupBox);
        horizontalSlider_Servo2->setObjectName(QStringLiteral("horizontalSlider_Servo2"));
        horizontalSlider_Servo2->setMinimum(1000);
        horizontalSlider_Servo2->setMaximum(2000);
        horizontalSlider_Servo2->setValue(1500);
        horizontalSlider_Servo2->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_Servo2, 2, 1, 1, 1);

        horizontalSlider_Servo4 = new QSlider(groupBox);
        horizontalSlider_Servo4->setObjectName(QStringLiteral("horizontalSlider_Servo4"));
        horizontalSlider_Servo4->setMinimum(1000);
        horizontalSlider_Servo4->setMaximum(2000);
        horizontalSlider_Servo4->setValue(1500);
        horizontalSlider_Servo4->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_Servo4, 4, 1, 1, 1);

        horizontalSlider_Servo3 = new QSlider(groupBox);
        horizontalSlider_Servo3->setObjectName(QStringLiteral("horizontalSlider_Servo3"));
        horizontalSlider_Servo3->setMinimum(1000);
        horizontalSlider_Servo3->setMaximum(2000);
        horizontalSlider_Servo3->setValue(1500);
        horizontalSlider_Servo3->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_Servo3, 3, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        spinBox_Servo3 = new QSpinBox(groupBox);
        spinBox_Servo3->setObjectName(QStringLiteral("spinBox_Servo3"));
        spinBox_Servo3->setMinimum(1000);
        spinBox_Servo3->setMaximum(2000);
        spinBox_Servo3->setSingleStep(100);
        spinBox_Servo3->setValue(1500);

        gridLayout_2->addWidget(spinBox_Servo3, 3, 2, 1, 1);

        spinBox_Servo5 = new QSpinBox(groupBox);
        spinBox_Servo5->setObjectName(QStringLiteral("spinBox_Servo5"));
        spinBox_Servo5->setMinimum(1000);
        spinBox_Servo5->setMaximum(2000);
        spinBox_Servo5->setSingleStep(100);
        spinBox_Servo5->setValue(1500);

        gridLayout_2->addWidget(spinBox_Servo5, 5, 2, 1, 1);

        pushButton_Servo0 = new QPushButton(groupBox);
        pushButton_Servo0->setObjectName(QStringLiteral("pushButton_Servo0"));

        gridLayout_2->addWidget(pushButton_Servo0, 0, 3, 1, 1);

        pushButton_Servo1 = new QPushButton(groupBox);
        pushButton_Servo1->setObjectName(QStringLiteral("pushButton_Servo1"));

        gridLayout_2->addWidget(pushButton_Servo1, 1, 3, 1, 1);

        pushButton_Servo2 = new QPushButton(groupBox);
        pushButton_Servo2->setObjectName(QStringLiteral("pushButton_Servo2"));

        gridLayout_2->addWidget(pushButton_Servo2, 2, 3, 1, 1);

        pushButton_Servo3 = new QPushButton(groupBox);
        pushButton_Servo3->setObjectName(QStringLiteral("pushButton_Servo3"));

        gridLayout_2->addWidget(pushButton_Servo3, 3, 3, 1, 1);

        pushButton_Servo4 = new QPushButton(groupBox);
        pushButton_Servo4->setObjectName(QStringLiteral("pushButton_Servo4"));

        gridLayout_2->addWidget(pushButton_Servo4, 4, 3, 1, 1);

        pushButton_Servo5 = new QPushButton(groupBox);
        pushButton_Servo5->setObjectName(QStringLiteral("pushButton_Servo5"));

        gridLayout_2->addWidget(pushButton_Servo5, 5, 3, 1, 1);


        gridLayout->addWidget(groupBox, 2, 0, 1, 1);


        retranslateUi(PololuControllerWidget);
        QObject::connect(horizontalSlider_Servo0, SIGNAL(valueChanged(int)), spinBox_Servo0, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_Servo1, SIGNAL(valueChanged(int)), spinBox_Servo1, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_Servo2, SIGNAL(valueChanged(int)), spinBox_Servo2, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_Servo3, SIGNAL(valueChanged(int)), spinBox_Servo3, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_Servo4, SIGNAL(valueChanged(int)), spinBox_Servo4, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_Servo5, SIGNAL(valueChanged(int)), spinBox_Servo5, SLOT(setValue(int)));
        QObject::connect(spinBox_Servo0, SIGNAL(valueChanged(int)), horizontalSlider_Servo0, SLOT(setValue(int)));
        QObject::connect(spinBox_Servo1, SIGNAL(valueChanged(int)), horizontalSlider_Servo1, SLOT(setValue(int)));
        QObject::connect(spinBox_Servo2, SIGNAL(valueChanged(int)), horizontalSlider_Servo2, SLOT(setValue(int)));
        QObject::connect(spinBox_Servo3, SIGNAL(valueChanged(int)), horizontalSlider_Servo3, SLOT(setValue(int)));
        QObject::connect(spinBox_Servo4, SIGNAL(valueChanged(int)), horizontalSlider_Servo4, SLOT(setValue(int)));
        QObject::connect(spinBox_Servo5, SIGNAL(valueChanged(int)), horizontalSlider_Servo5, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(PololuControllerWidget);
    } // setupUi

    void retranslateUi(QWidget *PololuControllerWidget)
    {
        PololuControllerWidget->setWindowTitle(QApplication::translate("PololuControllerWidget", "Form", 0));
        pushButton_Open->setText(QApplication::translate("PololuControllerWidget", "Open", 0));
        pushButton_Close->setText(QApplication::translate("PololuControllerWidget", "Close", 0));
        groupBox->setTitle(QApplication::translate("PololuControllerWidget", "Channel 0-5", 0));
        label->setText(QApplication::translate("PololuControllerWidget", "Servo 0", 0));
        label_2->setText(QApplication::translate("PololuControllerWidget", "Servo 1", 0));
        label_5->setText(QApplication::translate("PololuControllerWidget", "Servo 4", 0));
        label_3->setText(QApplication::translate("PololuControllerWidget", "Servo 2", 0));
        label_6->setText(QApplication::translate("PololuControllerWidget", "Servo 5", 0));
        label_4->setText(QApplication::translate("PololuControllerWidget", "Servo 3", 0));
        pushButton_Servo0->setText(QApplication::translate("PololuControllerWidget", "Impulse", 0));
        pushButton_Servo1->setText(QApplication::translate("PololuControllerWidget", "Impulse", 0));
        pushButton_Servo2->setText(QApplication::translate("PololuControllerWidget", "Impulse", 0));
        pushButton_Servo3->setText(QApplication::translate("PololuControllerWidget", "Impulse", 0));
        pushButton_Servo4->setText(QApplication::translate("PololuControllerWidget", "Impulse", 0));
        pushButton_Servo5->setText(QApplication::translate("PololuControllerWidget", "Impulse", 0));
    } // retranslateUi

};

namespace Ui {
    class PololuControllerWidget: public Ui_PololuControllerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POLOLU_CONTROLLER_WIDGET_H
