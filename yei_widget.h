#ifndef YEI_WIDGET_H
#define YEI_WIDGET_H

#include <QWidget>
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
    void openConnection();
    void closeConnection();

    Eigen::Quaternionf getQuaternion();
    
private:
    Ui::YEIWidget *ui;
    YEI_IMU * myIMU;

};




#endif // YEI_WIDGET_H
