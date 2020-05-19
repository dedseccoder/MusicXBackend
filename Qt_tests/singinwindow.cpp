#include "singinwindow.h"
#include "ui_singinwindow.h"

#include <QtNetwork>
#include <QtDebug>

SingInWindow::SingInWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SingInWindow)
{
    ui->setupUi(this);
    ui->PasswordInput->setText("");
    ui->UserNameInput->setText("");
}

SingInWindow::~SingInWindow()
{
    delete ui;
}

void SingInWindow::on_Sing_In_clicked()
{
    //link for the app to server
    QNetworkRequest request (QUrl("http://213.59.157.203/api/authenticate"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkAccessManager man;

    //work with input
    QString username_input, password_input;

    username_input = ui->UserNameInput->text();
    password_input = ui->PasswordInput->text();
    //create JSON
    QJsonObject JSON;
    JSON.insert("username", username_input);
    JSON.insert("password", password_input);
    //send JSON
    QNetworkReply *reply = man.post(request, QJsonDocument(JSON).toJson());
    while (!reply->isFinished())
    {
        qApp->processEvents();
    }
    //convert reply to JSON (i hope)
    QJsonDocument reply_document = QJsonDocument::fromJson(reply->readAll());
    //get code response HTTP
    QVariant response_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    //console output
    qDebug () << "start reading sing in response" << endl;
    qDebug () << response_code << endl;
    //getting our token from JSON reply
    QString token = reply_document.object().value("token").toString();
    qDebug () << "Token = " << token << endl;
    qDebug () << "end of reading sing in response" << endl;

    reply->deleteLater();
    this->close();
}
