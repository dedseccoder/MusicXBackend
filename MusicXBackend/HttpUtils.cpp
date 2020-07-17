#include "HttpUtils.h"

#include <QNetworkRequest>
#include <string>
#include <QDebug>
#include <QMap>
#include <QtNetwork>


QString HttpUtils::GET(QUrl URL, QMap<QByteArray, QByteArray> *headers)
{
    QNetworkRequest request (URL);
    request.setRawHeader("Content-Type", "application/json");
    if(headers != NULL)
    {
        for (auto e : headers->keys())
        {
            request.setRawHeader(e, headers->value(e));
        }
    }
    return QString ("");
}

QNetworkReply* HttpUtils::POST(QUrl URL, QJsonObject JSON_obj, QMap<QByteArray, QByteArray> *headers)
{
    QNetworkRequest request (URL);
    request.setRawHeader("Content-Type", "application/json");
    if(headers != NULL)
    {
        for (auto e : headers->keys())
        {
            request.setRawHeader(e, headers->value(e));
        }
    }
     QNetworkAccessManager network_manager;
     QNetworkReply *reply = network_manager.post(request, QJsonDocument(JSON_obj).toJson());
     while (!reply->isFinished())
         {
             qApp->processEvents();
         }
     if (reply->error())
        {
            qDebug () << "ERROR: " << reply->error() << endl;
        }
     return reply;
}
