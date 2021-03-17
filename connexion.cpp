#include "connexion.h"

connection::connection(){}
bool connection::createconnection()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet2A");//inserer le nom de la source de données ODBC
    db.setUserName("rihab3");//inserer nom de l'utilisateur
    db.setPassword("rihab3");//inserer mot de passe de cet utilisateur


    if (db.open())
    test=true;

return test;

}
void connection::closeconnection(){db.close();}
