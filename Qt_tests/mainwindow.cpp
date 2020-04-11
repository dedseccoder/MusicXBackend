#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtNetwork>
#include <QDebug>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->frame->hide();

    ui->UsernameInput->setText("");
    ui->PasswordInput->setText("");
    ui->NameInput->setText("");
    ui->LastNameInput->setText("");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Sing_In_clicked()
{
    ui->frame->show();
}

void MainWindow::on_Sing_In2_clicked()
{
    QNetworkRequest request (QUrl("http://213.59.157.203/api/register"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkAccessManager man;

    QString *username_input = new QString();
    QString *password_input = new QString();
    QString *name_input = new QString();
    QString *lastname_input = new QString();

    *username_input = ui->UsernameInput->text();
    *password_input = ui->PasswordInput->text();
    *name_input = ui->NameInput->text();
    *lastname_input = ui->LastNameInput->text();

    QJsonObject JSON;
    JSON.insert("username", *username_input);
    JSON.insert("password", *password_input);
    JSON.insert ("name", *name_input);
    JSON.insert("lastname", *lastname_input);

    QNetworkReply *reply = man.post(request, QJsonDocument(JSON).toJson());
    while (!reply->isFinished())
    {
        qApp->processEvents();
    }
    QByteArray response_data = reply->readAll();

    qDebug () << "Start reading response" << endl;
    qDebug () << reply->readAll() << endl;
    qDebug () << "End of reading" << endl;

    delete username_input;
    delete password_input;
    delete name_input;
    delete lastname_input;
    reply->deleteLater();
}
