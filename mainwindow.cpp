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

    server = new QTcpServer(this);
    socket = new QTcpSocket(this);

    connect (server, SIGNAL(newConnection()), this, SLOT(newTCPIPConnection()));

    if (!server->listen(QHostAddress::Any,1234))
        qDebug() << "Server could not start";

    else
        qDebug() << "Server started";

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
    w.showMaximized();

    return a.exec();
}

void MainWindow::on_pushButton_openall_clicked()
{
    ui->myIMU->openConnection();
    ui->myPololuController->openConnection();
}

void MainWindow::on_pushButton_closeall_clicked()
{
    ui->myIMU->closeConnection();
    ui->myPololuController->closeConnection();
}

void MainWindow::on_pushButton_graball_clicked()
{
    ui->myPololuController->impulseChannel0();
    Eigen::Quaternionf quat = ui->myIMU->getQuaternion();
}




void MainWindow::newTCPIPConnection()
{
    socket = server->nextPendingConnection();

    connect (socket, SIGNAL(readyRead()), this, SLOT(newMessageReceived()));

    qDebug() << "New connection found";

    socket->write("hello client");
    socket->flush();

    socket->waitForBytesWritten(3000);

   // socket->close();
}

void MainWindow::newMessageReceived()
{
    QString message = QString(socket->readAll());
    qDebug() << "Server received the following message : " << message;
    if (message == QString("Connect"))
    {
        ui->myIMU->openConnection();
        ui->myPololuController->openConnection();
    }
    else if(message == QString("Disconnect"))
    {
        ui->myIMU->closeConnection();
        ui->myPololuController->closeConnection();
    }
    else if(message == QString("Grab"))
    {
        ui->myPololuController->impulseChannel0();
        Eigen::Quaternionf quat = ui->myIMU->getQuaternion();
    }
}


