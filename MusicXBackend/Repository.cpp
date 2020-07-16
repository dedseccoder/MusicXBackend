#include "Repository.h"
#include <QObject>
#include <QString>

void Repository::putItem(QString id, QObject *obj) {
    if (obj != nullptr) {
        repository.insert(id, obj);
    }
}

QObject* Repository::getItem(QString id) {
    return repository.value(id);
}
