#ifndef ADAFRUIT_WIDGET_H
#define ADAFRUIT_WIDGET_H

#include <QWidget>
#include "adafruit_uart.h"


namespace Ui {
class AdafruitWidget;
}

class AdafruitWidget : public QWidget
{
    Q_OBJECT
public:
    AdafruitWidget(QWidget * parent=0);
    ~AdafruitWidget();


public slots:
    void openConnection();
    void closeConnection();

    void initializeSensor();

    Eigen::Quaternionf getQuaternion();
    
private:
    Ui::AdafruitWidget *ui;
    Adafruit_UART * myIMU;
};




#endif // ADAFRUIT_WIDGET_H
