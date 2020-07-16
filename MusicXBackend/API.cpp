#include "API.h"
#include "HttpUtils.h"

#include <QMainWindow>
#include <QtNetwork>

using namespace std;


void API::Register(QString username_input, QString password_input, QString name_input, QString lastname_input)
{
    QString reply = HttpUtils::GET(base_url + "api/register", NULL);
    QJsonObject JSON;
    JSON.insert("username", username_input);
    JSON.insert("password", password_input);
    JSON.insert ("name", name_input);
    JSON.insert("lastname", lastname_input);
    HttpUtils::POST(JSON, base_url, NULL);
}

QString API::Auth(QString username_input, QString password_input) {
    QString reply = HttpUtils::GET(base_url + "api/login", NULL);
    // TODO: Release this function
    return QString("");
}
