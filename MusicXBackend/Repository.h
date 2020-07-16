#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <QObject>
#include <QString>
#include <QMap>

class Repository {
private:
    QMap<QString, QObject*> repository;
    Repository() {}

public:
    static Repository& getInstance() {
        static Repository instance;
        return instance;
    };

    void putItem(QString, QObject*);
    QObject* getItem(QString);
};

#endif // REPOSITORY_H
