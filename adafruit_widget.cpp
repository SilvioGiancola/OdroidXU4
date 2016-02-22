#include "adafruit_widget.h"
#include "ui_adafruit_widget.h"


AdafruitWidget::AdafruitWidget(QWidget * parent) : QWidget(parent), ui(new Ui::AdafruitWidget)
{
    ui->setupUi(this);
    myIMU = new Adafruit_UART();   
}

AdafruitWidget::~AdafruitWidget()
{
    if (myIMU->isopen())
        myIMU->close();
    delete ui;
}


void AdafruitWidget::openConnection()
{
    if(myIMU->open() == SUCCESS)
        ui->groupBox->setEnabled(true);
    return;
}

void AdafruitWidget::closeConnection()
{
    myIMU->close();
    ui->groupBox->setEnabled(false);
    return;
}









Eigen::Quaternionf AdafruitWidget::getQuaternion()
{
    Eigen::Quaternionf quat = myIMU->returnPose();
    QString label = QString("%1 / %2 / %3 / %4").arg(quat.w()).arg(quat.x()).arg(quat.y()).arg(quat.z());
    ui->label_Quaternion->setText(label);
    return myIMU->returnPose();
}

void AdafruitWidget::initializeSensor()
{
    myIMU->init();
    return;
}

