#ifndef HTTPUTILS_H
#define HTTPUTILS_H

#include <string>
#include <QDebug>
#include <QMap>
#include <QtNetwork>

class HttpUtils
{
public:
    std::string static GET(QUrl URL, QMap<QString, QString>*headers);
    void static POST();
    void static PUT();
    void static DELETE();
};

#endif // HTTPUTILS_H
