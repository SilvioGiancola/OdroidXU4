#ifndef POLOLU_CONTROLLER_WIDGET_H
#define POLOLU_CONTROLLER_WIDGET_H

#include <QWidget>
#include "pololu_controller.h"




namespace Ui {
class PololuControllerWidget;
}

class PololuControllerWidget : public QWidget
{
    Q_OBJECT
public:
    PololuControllerWidget(QWidget * parent=0);
    ~PololuControllerWidget();

signals:

public slots:

private slots:    
    void on_pushButton_Open_clicked();
    void on_pushButton_Close_clicked();

    void on_spinBox_Servo0_valueChanged(int value){ myController->setPWM(0,value); }
    void on_spinBox_Servo1_valueChanged(int value){ myController->setPWM(1,value); }
    void on_spinBox_Servo2_valueChanged(int value){ myController->setPWM(2,value); }
    void on_spinBox_Servo3_valueChanged(int value){ myController->setPWM(3,value); }
    void on_spinBox_Servo4_valueChanged(int value){ myController->setPWM(4,value); }
    void on_spinBox_Servo5_valueChanged(int value){ myController->setPWM(5,value); }

    void on_pushButton_Servo0_clicked() {myController->impulse(0);}
    void on_pushButton_Servo1_clicked() {myController->impulse(1);}
    void on_pushButton_Servo2_clicked() {myController->impulse(2);}
    void on_pushButton_Servo3_clicked() {myController->impulse(3);}
    void on_pushButton_Servo4_clicked() {myController->impulse(4);}
    void on_pushButton_Servo5_clicked() {myController->impulse(5);}


private:
    Ui::PololuControllerWidget *ui;
    PololuController * myController;


};




#endif // POLOLU_CONTROLLER_WIDGET_H