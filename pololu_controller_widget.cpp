#include "pololu_controller_widget.h"
#include "ui_pololu_controller_widget.h"


PololuControllerWidget::PololuControllerWidget(QWidget * parent) : QWidget(parent), ui(new Ui::PololuControllerWidget)
{
    ui->setupUi(this);
    myController = new PololuController();
}

PololuControllerWidget::~PololuControllerWidget()
{
    delete ui;
}




void PololuControllerWidget::on_pushButton_Open_clicked()
{
    if (myController->open() == SUCCESS)
        ui->groupBox->setEnabled(true);
}

void PololuControllerWidget::on_pushButton_Close_clicked()
{
    myController->close();
    ui->groupBox->setEnabled(false);
}








