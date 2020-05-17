#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "singupwindow.h"

#include <QtNetwork>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Sing_In_clicked()
{
    SingUpWindow sing_up;
    sing_up.setModal(true);
    sing_up.exec();
}

void MainWindow::on_close_clicked()
{
    this->close();
}
