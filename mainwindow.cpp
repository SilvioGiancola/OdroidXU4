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

    if (server->listen(QHostAddress::Any, 1234))
        qDebug() << "Server started";
    else
        qDebug() << "Server could not start";
}

// Destructor
MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::newTCPIPConnection()
{
    socket = server->nextPendingConnection();

    connect (socket, SIGNAL(readyRead()), this, SLOT(newMessageReceived()));
    connect (socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(clientStateChanged(QAbstractSocket::SocketState)));

    socket->write("Hello client! :)");
}

void MainWindow::clientStateChanged(QAbstractSocket::SocketState state)
{
    if (state == QAbstractSocket::UnconnectedState)
        ui->label_ClientState->setText(QString("Client : UnconnectedState"));
    if (state == QAbstractSocket::HostLookupState)
        ui->label_ClientState->setText(QString("Client : HostLookupState"));
    if (state == QAbstractSocket::ConnectingState)
        ui->label_ClientState->setText(QString("Client : ConnectingState"));
    if (state == QAbstractSocket::ConnectedState)
        ui->label_ClientState->setText(QString("Client : ConnectedState"));
    if (state == QAbstractSocket::BoundState)
        ui->label_ClientState->setText(QString("Client : BoundState"));
    if (state == QAbstractSocket::ListeningState)
        ui->label_ClientState->setText(QString("Client : ListeningState"));
    if (state == QAbstractSocket::ClosingState)
        ui->label_ClientState->setText(QString("Client : ClosingState"));
}

void MainWindow::newMessageReceived()
{
    QString message = QString(socket->readAll());
    socket->write("ok!");
    qDebug() << "Server received the following message : " << message;
    if (message == QString("Connect"))
    {
        ui->myIMU->openConnection();
        ui->myPololuController->openConnection();
        socket->write("connected!");
    }
    else if(message == QString("Disconnect"))
    {
        ui->myIMU->closeConnection();
        ui->myPololuController->closeConnection();
        socket->write("disconnected!");
    }
    else if(message == QString("Grab"))
    {
        ui->myPololuController->impulseChannel0();
        Eigen::Quaternionf quat = ui->myIMU->getQuaternion();
        socket->write("grabbed!");
    }
}







