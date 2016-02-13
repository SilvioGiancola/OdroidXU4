#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui/QCloseEvent>
#include <pololu_controller.h>

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

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
