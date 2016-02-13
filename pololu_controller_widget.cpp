#include "pololu_controller_widget.h"
#include "ui_pololu_controller_widget.h"

#include "QApplication"


PololuControllerWidget::PololuControllerWidget(QWidget * parent) : QWidget(parent), ui(new Ui::PololuControllerWidget)
{
    ui->setupUi(this);
    myController = new PololuController();
}

PololuControllerWidget::~PololuControllerWidget()
{
    if (myController->isopen())
        myController->close();
    delete ui;
}




void PololuControllerWidget::on_pushButton_Open_clicked()
{
    if (open() == SUCCESS)
        ui->groupBox->setEnabled(true);
}

void PololuControllerWidget::on_pushButton_Close_clicked()
{
    close();
    ui->groupBox->setEnabled(false);
}


void PololuControllerWidget::on_pushButton_Servo0_clicked()
{
    int channel = 0;
    int previousvalue = myController->getPWM(channel);
    myController->setPWM(channel,2000);
    QTime t;
    t.start();
    while (t.elapsed() < 600)
    {
        ui->lcdNumber_timer->display(t.elapsed());
        ui->label_timer->setText(QString::number(t.elapsed()));
        qApp->processEvents();
    }
    myController->setPWM(channel, previousvalue);

}
void PololuControllerWidget::on_pushButton_Servo1_clicked() {myController->impulse(1);}
void PololuControllerWidget::on_pushButton_Servo2_clicked() {myController->impulse(2);}
void PololuControllerWidget::on_pushButton_Servo3_clicked() {myController->impulse(3);}
void PololuControllerWidget::on_pushButton_Servo4_clicked() {myController->impulse(4);}
void PololuControllerWidget::on_pushButton_Servo5_clicked() {myController->impulse(5);}







