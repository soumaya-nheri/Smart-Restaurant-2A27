#include "articles.h"
#include "connexion.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connection c;
    c.createconnection();
    articles w;
    w.show();
    return a.exec();
}
