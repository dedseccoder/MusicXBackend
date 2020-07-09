#include "mainwindow.h"

#include <QApplication>
#include <QtNetwork>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

//test


    w.show();
    return a.exec();
}
