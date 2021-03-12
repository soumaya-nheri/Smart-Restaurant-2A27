#include "connection.h"

connection::connection(){}
bool connection::createconnection()
{bool test=false;
    QsqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Projet_2A");//inserer le nom de la source de données ODBC
    db.setUserName("ahmed");//inserer nom de l'utilisateur
    db.setPassword("ahmed");//inserer mot de passe de cet utilisateur


    if (db.open())
    test=true;

return test;

}
void connection::closeconnection(){db.close();}
