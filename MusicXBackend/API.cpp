#include "API.h"
#include "HttpUtils.h"

#include <QMainWindow>
#include <QtNetwork>

using namespace std;


void API::Register(QString username, QString password, QString name, QString lastname)
{
    QJsonObject JSON;
    JSON.insert("username", username);
    JSON.insert("password", password);
    JSON.insert ("name", name);
    JSON.insert("lastname", lastname);
    QNetworkReply *reply = HttpUtils::POST(base_url + "api/register", JSON, NULL);
    qDebug() << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
}

QString API::Auth(QString username, QString password) {
    QString reply = HttpUtils::GET(base_url + "api/login", NULL);
    // TODO: Release this function
    return QString("");
}
