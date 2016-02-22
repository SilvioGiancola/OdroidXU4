#include "mainwindow.h"
#include "ui_mainwindow.h"


// Constructor
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // Set the user interface from Qt Designer
    ui->setupUi(this);

    server = new QTcpServer(this);
    socket = new QTcpSocket(this);

    connect (server, SIGNAL(newConnection()), this, SLOT(newTCPIPConnection()));

    if (!server->listen(QHostAddress::Any, 1234))
        qDebug() << "Server could not start";

    else
        qDebug() << "Server started";

}

// Destructor
MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::OpenAllDevices()
{
    ui->myIMU->openConnection();
    ui->myPololuController->openConnection();
}

void MainWindow::CloseAllDevices()
{
    ui->myIMU->closeConnection();
    ui->myPololuController->closeConnection();
}

void MainWindow::GrabAllDevices()
{
    ui->myPololuController->impulseChannel0();
    Eigen::Quaternionf quat = ui->myIMU->getQuaternion();
}




void MainWindow::newTCPIPConnection()
{
    socket = server->nextPendingConnection();

    connect (socket, SIGNAL(readyRead()), this, SLOT(newMessageReceived()));

    qDebug() << "New connection found";

    socket->write("Hello client! :)");
    socket->flush();

    socket->waitForBytesWritten(3000);

}

void MainWindow::newMessageReceived()
{
    QString message = QString(socket->readAll());    
    socket->write(message.append(" received!").toStdString().c_str());
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







