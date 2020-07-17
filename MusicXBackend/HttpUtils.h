#ifndef HTTPUTILS_H
#define HTTPUTILS_H

#include <string>
#include <QDebug>
#include <QMap>
#include <QtNetwork>

class HttpUtils
{
public:
    QString static GET(QUrl URL, QMap<QByteArray, QByteArray> *headers);
    QNetworkReply static *POST(QUrl URL, QJsonObject JSON_obj, QMap<QByteArray, QByteArray> *headers);
    void static PUT();
    void static DELETE();
};

#endif // HTTPUTILS_H
