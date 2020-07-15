#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <QObject>
#include <QString>

class Repository {
private:
    Repository() {}

public:
    static Repository& getInstance() {
        static Repository instance;
        return instance;
    };

    void putItem(QString, QObject);
    void getItem(QString);
};

#endif // REPOSITORY_H
