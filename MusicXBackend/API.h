#ifndef API_H
#define API_H

#include <QMainWindow>
#include <QtNetwork>

class API
{
public:
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
};
#endif // API_H
