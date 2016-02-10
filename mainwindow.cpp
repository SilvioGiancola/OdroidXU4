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
