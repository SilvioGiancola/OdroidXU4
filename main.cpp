#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv,false);

    MainWindow w;
    w.showMaximized();

    return a.exec();
}
