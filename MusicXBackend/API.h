#ifndef API_H
#define API_H

#include <QMainWindow>
#include <QtNetwork>

class API
{
public:
    API (QString arg_base_url){base_url = arg_base_url;}
    void Register();
    void Austh();
    void GetSong();
    void GetPlaylist();
private:
    QString token, password_auth, username_auth;
    QNetworkAccessManager man;
    QNetworkRequest request;
    QJsonObject JSON;
    QVariant response_code;
    QString base_url;
};
#endif // API_H
