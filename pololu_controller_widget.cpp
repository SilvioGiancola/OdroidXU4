#include "pololu_controller_widget.h"
#include "ui_pololu_controller_widget.h"

#include "QApplication"


PololuControllerWidget::PololuControllerWidget(QWidget * parent) : QWidget(parent), ui(new Ui::PololuControllerWidget)
{
    ui->setupUi(this);
    myController = new PololuController(this);
}

PololuControllerWidget::~PololuControllerWidget()
{
    if (myController->isopen())
        myController->close();
    delete ui;
}


int PololuControllerWidget::openConnection()
{
    int res = myController->open();
    if (res == SUCCESS)
        ui->groupBox->setEnabled(true);
    return res;
}

void PololuControllerWidget::closeConnection()
{
    if (myController->isopen())
        myController->close();
    ui->groupBox->setEnabled(false);
}


void PololuControllerWidget::impulseChannel0()
{
    if (myController->isopen())
    {
        int channel = 0;
        int previousvalue = myController->getPWM(channel);
        myController->setPWM(channel,2000);
        QTime t;
        t.start();
        while (t.elapsed() < 250)
        {
            ui->lcdNumber_timer->display(t.elapsed());
            ui->label_timer->setText(QString::number(t.elapsed()));
            qApp->processEvents();
        }
        myController->setPWM(channel, previousvalue);
    }
}
