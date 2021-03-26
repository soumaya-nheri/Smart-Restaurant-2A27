#include "menu.h"
#include "connection.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    connection c;
    c.createconnection();
    Menu w;
    w.show();
    return a.exec();
}
