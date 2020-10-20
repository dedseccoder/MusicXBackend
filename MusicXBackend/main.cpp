#include "mainwindow.h"
#include "API.h"
#include "Repository.h"

#include <QApplication>
#include <QtNetwork>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Repository* repository = Repository::getInstance();
    QObject *api = new API("http://192.168.88.2:8080/MusicXBackend/");
    repository->putItem("API", api);

    w.show();
    return a.exec();
}
