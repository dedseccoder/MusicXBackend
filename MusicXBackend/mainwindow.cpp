#include "mainwindow.h"
#include "API.h"
#include "HttpUtils.h"
#include "Repository.h"
#include "ui_mainwindow.h"
#include "singupwindow.h"
#include "singinwindow.h"

#include <QtNetwork>
#include <QDebug>

Repository repository = Repository::getInstance();

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

void MainWindow::on_close_clicked()
{
    this->close();
}

void MainWindow::on_Sing_In_clicked()
{
    SingUpWindow sing_up;
    sing_up.setModal(true);
    sing_up.exec();
}

void MainWindow::on_pushButton_clicked()
{
    SingInWindow sing_in;
    sing_in.setModal(true);
    sing_in.exec();
}
