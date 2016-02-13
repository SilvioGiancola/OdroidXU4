#ifndef ADAFRUIT_WIDGET_H
#define ADAFRUIT_WIDGET_H

#include <QWidget>
#include "adafruit_uart.h"


//#include <pcl/visualization/pcl_visualizer.h>
//#include <vtkRenderWindow.h>




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

  //  pcl::visualization::PCLVisualizer::Ptr viewer;

};




#endif // ADAFRUIT_WIDGET_H
