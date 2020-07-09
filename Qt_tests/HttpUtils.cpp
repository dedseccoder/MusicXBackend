#include "HttpUtils.h"

#include <QNetworkAccessManager>
#include <string>
#include <QDebug>
#include <QMap>
#include <QtNetwork>


std::string HttpUtils :: GET(QString URL, QMap<QString, QString>headers)
{
    QNetworkRequest request (QUrl(URL));
    request.setRawHeader("Content-Type", "application/json");
}
//(, "application/json");
//"http://213.59.157.203/MusicXBackend/api/register
