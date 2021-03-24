#include "tables.h"
#include "connexion.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connection c;
    c.createconnection();
    Tables w;
    return a.exec();
}
