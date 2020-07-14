#include "API.h"
#include "HttpUtils.h"

#include <QMainWindow>
#include <QtNetwork>

using namespace std;


void API :: Register()
{
    HttpUtils https;
    https.GET(base_url + "api/register", NULL);
}
