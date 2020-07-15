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
}
