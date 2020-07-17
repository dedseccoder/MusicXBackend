#ifndef API_H
#define API_H

#include <QMainWindow>
#include <QtNetwork>

class API : public QObject
{
public:
    API(QString arg_base_url) {base_url = arg_base_url;}
    void Register(QString username, QString password, QString name, QString lastname);
    QString Auth(QString username, QString password);
    void GetSong();
    void GetPlaylist();

private:
    QString base_url;
};
#endif // API_H
