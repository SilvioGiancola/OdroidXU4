#ifndef POLOLU_CONTROLLER_WIDGET_H
#define POLOLU_CONTROLLER_WIDGET_H

#include <QWidget>
#include <QTime>
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


public slots:
    int openConnection();
    void closeConnection();

    void impulseChannel0();
    void impulseChannel1() {myController->impulse(1);}
    void impulseChannel2() {myController->impulse(2);}
    void impulseChannel3() {myController->impulse(3);}
    void impulseChannel4() {myController->impulse(4);}
    void impulseChannel5() {myController->impulse(5);}


private slots:

    void on_spinBox_Servo0_valueChanged(int value){ myController->setPWM(0,value); }
    void on_spinBox_Servo1_valueChanged(int value){ myController->setPWM(1,value); }
    void on_spinBox_Servo2_valueChanged(int value){ myController->setPWM(2,value); }
    void on_spinBox_Servo3_valueChanged(int value){ myController->setPWM(3,value); }
    void on_spinBox_Servo4_valueChanged(int value){ myController->setPWM(4,value); }
    void on_spinBox_Servo5_valueChanged(int value){ myController->setPWM(5,value); }



private:
    Ui::PololuControllerWidget *ui;
    PololuController * myController;


};




#endif // POLOLU_CONTROLLER_WIDGET_H
