#include "singupwindow.h"
#include "ui_singupwindow.h"
#include "HttpUtils.h"
#include "API.h"
#include "Repository.h"

#include <QtNetwork>
#include <QDebug>

SingUpWindow::SingUpWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SingUpWindow)
{
    ui->setupUi(this);

    ui->UsernameInput->setText("Sher");
    ui->PasswordInput->setText("goldman");
    ui->NameInput->setText("Andrey");
    ui->LastNameInput->setText("Loginov");
}

SingUpWindow::~SingUpWindow()
{
    delete ui;
}

void SingUpWindow::on_Sing_In2_clicked()
{
    Repository* repository = Repository::getInstance();
    API *api = (API *)repository->getItem("API");
    // TODO: USE api object for requests
    // Example:
    // api->Register();
    api->Register(ui->UsernameInput->text(),
                  ui->PasswordInput->text(),
                  ui->NameInput->text(),
                  ui->LastNameInput->text()
                  );

    this->close();
}
