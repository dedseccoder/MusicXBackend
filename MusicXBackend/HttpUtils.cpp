#include "HttpUtils.h"

#include <QNetworkRequest>
#include <string>
#include <QDebug>
#include <QMap>
#include <QtNetwork>


std::string HttpUtils :: GET(QUrl URL, QMap<QString, QString>*headers)
{
    QNetworkRequest request (URL);
    request.setRawHeader("Content-Type", "application/json");
    if(headers != NULL)
    {
        QMap<QString, QString>::iterator i;
        for (int i = *headers->begin(); i != *headers->end(); ++i)
        {
        request.setRawHeader(i.key(), i.value());
        }
    }
}