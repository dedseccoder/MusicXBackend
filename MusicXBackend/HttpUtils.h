#ifndef HTTPUTILS_H
#define HTTPUTILS_H

#include <string>
#include <QDebug>
#include <QMap>
#include <QtNetwork>

class HttpUtils
{
public:
    static QString GET(QUrl URL, QMap<QByteArray, QByteArray> *headers);
    static QNetworkReply *POST(QUrl URL, QJsonObject JSON_obj, QMap<QByteArray, QByteArray> *headers);
    static void PUT();
    static void DELETE();
};

#endif // HTTPUTILS_H
