#include "mainwindow.h"
#include "connexion.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connection c;
    c.createconnection();
    MainWindow w;
    w.show();
    return a.exec();
}
