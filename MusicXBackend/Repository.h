#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <QObject>
#include <QString>
#include <QMap>

class Repository {
private:
    static Repository* instance;
    QMap<QString, QObject*> repository;
    Repository() {}
    ~Repository() {}

public:
    static Repository* getInstance() {
        if (instance == NULL) {
            instance = new Repository();
        }
        return instance;
    }

    void putItem(QString, QObject*);
    QObject* getItem(QString);
};

#endif // REPOSITORY_H
