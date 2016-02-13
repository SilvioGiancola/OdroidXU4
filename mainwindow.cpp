#if QT_VERSION >= 0x050000
#include <QApplication>
#else
#include <QtGui>
#endif
#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"



using namespace std;

// Constructor
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // Set the user interface from Qt Designer
    ui->setupUi(this);
    ui->lineEdit_path->setText(QString("%1/test.txt").arg(QDir::homePath()));
}

// Destructor
MainWindow::~MainWindow()
{
    delete ui;
}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}

void MainWindow::on_pushButton_openall_clicked()
{
    ui->myAdafruit->openConnection();
    ui->myPololuController->open();
}

void MainWindow::on_pushButton_closeall_clicked()
{
    ui->myAdafruit->closeConnection();
    ui->myPololuController->close();
}

void MainWindow::on_pushButton_graball_clicked()
{
    Eigen::Quaternionf quat = ui->myAdafruit->getQuaternion();
    ui->myPololuController->impulse(0);
}
