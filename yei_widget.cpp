#include "yei_widget.h"
#include "ui_yei_widget.h"


YEIWidget::YEIWidget(QWidget * parent) : QWidget(parent), ui(new Ui::YEIWidget)
{
    ui->setupUi(this);
    myIMU = new YEI_IMU(this);
}

YEIWidget::~YEIWidget()
{
    closeConnection();
    delete ui;
}


void YEIWidget::openConnection()
{
    if(myIMU->open() == SUCCESS)
    {
        ui->groupBox->setEnabled(true);

        QString path = QString("%1/%2.txt").arg(QDir::homePath()).arg(QDateTime::currentDateTime().toString("yyyy-MM-dd-HH-mm-ss-zzz"));

        myLogFile = new QFile(path);
        myLogFile->open(QIODevice::WriteOnly);
        ui->lineEdit_path->setText(path);
    }
    return;
}

void YEIWidget::closeConnection()
{
    if(myLogFile->isOpen())
        myLogFile->close();
    if(myIMU->isOpen())
        if(myIMU->isOpen())myIMU->close();
    ui->groupBox->setEnabled(false);
    return;
}






Eigen::Quaternionf YEIWidget::getQuaternion()
{
    Eigen::Quaternionf quat = myIMU->getTaredQuaternions();
    QString label = QString("%1 %2 %3 %4 %5").arg(QDateTime::currentMSecsSinceEpoch()).arg(quat.w()).arg(quat.x()).arg(quat.y()).arg(quat.z());
    ui->label_Quaternion->setText(label);

    QTextStream out (myLogFile);
    out << label << "\n";

    return quat;
}


