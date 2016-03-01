#ifndef YEI_WIDGET_H
#define YEI_WIDGET_H

#include <QWidget>
#include <QDateTime>
#include <QDir>
#include <QFile>
#include "yei_imu.h"



namespace Ui {
class YEIWidget;
}

class YEIWidget : public QWidget
{
    Q_OBJECT
public:
    YEIWidget(QWidget * parent=0);
    ~YEIWidget();


public slots:
    int openConnection();
    void closeConnection();

    Eigen::Quaternionf getQuaternion();


private slots:
    void on_pushButton_TareQuat_clicked();

private:
    Ui::YEIWidget *ui;
    YEI_IMU * myIMU;

    QFile * myLogFile;

};




#endif // YEI_WIDGET_H
