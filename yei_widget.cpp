#include "yei_widget.h"
#include "ui_yei_widget.h"


YEIWidget::YEIWidget(QWidget * parent) : QWidget(parent), ui(new Ui::YEIWidget)
{
    ui->setupUi(this);
    myIMU = new YEI_IMU(this);
    myLogFile = new QFile();
}

YEIWidget::~YEIWidget()
{
    closeConnection();
    delete ui;
}


int YEIWidget::openConnection()
{
    int res = myIMU->open();
    if(res == SUCCESS)
    {
        ui->groupBox->setEnabled(true);

        QString path = QString("%1/%2.txt").arg(QDir::homePath()).arg(QDateTime::currentDateTime().toString("yyyy-MM-dd-HH-mm-ss-zzz"));

        myLogFile = new QFile(path);
        myLogFile->open(QIODevice::WriteOnly);
        ui->lineEdit_path->setText(path);
    }
    return res;
}

void YEIWidget::closeConnection()
{
    if(myLogFile->isOpen())
        myLogFile->close();
    if(myIMU->isOpen())
        myIMU->close();
    ui->groupBox->setEnabled(false);
    return;
}






Eigen::Quaternionf YEIWidget::getQuaternion()
{
    Eigen::Quaternionf quat = myIMU->getTaredQuaternions();
    QString label = QString("%1 %2 %3 %4 %5").arg(QDateTime::currentMSecsSinceEpoch()).arg(quat.w()).arg(quat.x()).arg(quat.y()).arg(quat.z());
    ui->label_Quaternion->setText(label);

    double angle = 2 * std::acos(quat.w());
    QString anglestring = QString("%1").arg(angle*180/3.14159);

    ui->label_AngleDegree->setText(anglestring);
    QTextStream out (myLogFile);
    out << label << "\n";

    return quat;
}



void YEIWidget::on_pushButton_TareQuat_clicked()
{
    myIMU->setTareOrientationQuaternion();
    getQuaternion();
}
