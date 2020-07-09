#include "API.h"
#include "HttpUtils.h"

#include <QMainWindow>
#include <QtNetwork>

using namespace std;

void API :: Register()
{
    QNetworkRequest request (QUrl("http://213.59.157.203/MusicXBackend/api/register"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkAccessManager man;
}
