#ifndef API_H
#define API_H

#include <QMainWindow>
#include <QtNetwork>

class API
{
public:
    API(QString arg_base_url) {base_url = arg_base_url;}
    void Register();
    void Auth();
    void GetSong();
    void GetPlaylist();

private:
    // <REMOVE_THIS>
    // QString token, password_auth, username_auth;
    // QNetworkAccessManager man;
    // QNetworkRequest request;
    // QJsonObject JSON;
    // QVariant response_code;
    // </REMOVE_THIS>
    QString base_url;
};
#endif // API_H
