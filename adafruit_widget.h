#ifndef ADAFRUIT_WIDGET_H
#define ADAFRUIT_WIDGET_H

#include <QWidget>
#include "adafruit_uart.h"


#include <pcl/visualization/pcl_visualizer.h>
#include <vtkRenderWindow.h>




namespace Ui {
class AdafruitWidget;
}

class AdafruitWidget : public QWidget
{
    Q_OBJECT
public:
    AdafruitWidget(QWidget * parent=0);
    ~AdafruitWidget();

signals:

public slots:

private slots:    
    void on_pushButton_Open_clicked();
    void on_pushButton_Close_clicked();




    void on_pushButton_Quaternion_clicked();

    void on_pushButton_Init_clicked();

    void on_pushButton_Calib_clicked();

private:
    Ui::AdafruitWidget *ui;
    Adafruit_UART * myIMU;

    pcl::visualization::PCLVisualizer::Ptr viewer;

};




#endif // ADAFRUIT_WIDGET_H
