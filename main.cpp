#include "mainwindow.h"
#include <QApplication>
#include "connexion.h"
int main(int argc, char *argv[])
{
    connexion cnx ;
        cnx.ouvrirConnexion();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
