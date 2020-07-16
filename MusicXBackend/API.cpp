#include "API.h"
#include "HttpUtils.h"

#include <QMainWindow>
#include <QtNetwork>

using namespace std;


void API::Register()
{
    QString reply = HttpUtils::GET(base_url + "api/register", NULL);
}

QString API::Auth(QString username, QString password) {
    QString reply = HttpUtils::GET(base_url + "api/login", NULL);
    // TODO: Release this function
    return QString("");
}
