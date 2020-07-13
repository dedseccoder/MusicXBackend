#include "singupwindow.h"
#include "ui_singupwindow.h"

#include <QtNetwork>
#include <QDebug>

SingUpWindow::SingUpWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SingUpWindow)
{
    ui->setupUi(this);

    ui->UsernameInput->setText("");
    ui->PasswordInput->setText("");
    ui->NameInput->setText("");
    ui->LastNameInput->setText("");
}

SingUpWindow::~SingUpWindow()
{
    delete ui;
}

void SingUpWindow::on_Sing_In2_clicked()
{
    QNetworkRequest request (QUrl("http://213.59.157.203/MusicXBackend/api/register"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkAccessManager man;

    QString username_input;
    QString password_input;
    QString name_input;
    QString lastname_input;

    username_input = ui->UsernameInput->text();
    password_input = ui->PasswordInput->text();
    name_input = ui->NameInput->text();
    lastname_input = ui->LastNameInput->text();

    QJsonObject JSON;
    JSON.insert("username", username_input);
    JSON.insert("password", password_input);
    JSON.insert ("name", name_input);
    JSON.insert("lastname", lastname_input);

    QNetworkReply *reply = man.post(request, QJsonDocument(JSON).toJson());
    while (!reply->isFinished())
    {
        qApp->processEvents();
    }
    QVariant response_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);

    qDebug () << "Start reading sing up response" << endl;
    qDebug () << response_code << endl;
    qDebug () << "End of reading sing up response" << endl;

    reply->deleteLater();
    this->close();
}
