#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_openall_clicked();

    void on_pushButton_closeall_clicked();

    void on_pushButton_graball_clicked();
    void newTCPIPConnection();
    void newMessageReceived();

private:
    Ui::MainWindow *ui;

    QTcpServer *server;
    QTcpSocket *socket;

};
#endif // MAINWINDOW_H
