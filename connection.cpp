#include "connection.h"

connection::connection(){}
bool connection::createconnection()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");//inserer le nom de la source de données ODBC
    db.setUserName("mahdi");//inserer nom de l'utilisateur
    db.setPassword("esprit18");//inserer mot de passe de cet utilisateur


    if (db.open())
    test=true;

return test;

}
void connection::closeconnection(){db.close();}
