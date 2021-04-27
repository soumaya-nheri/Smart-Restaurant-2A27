#include "connection.h"
#include <QMessageBox>

connection::connection()
{

}

bool connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet2A27");//inserer le nom de la source de données ODBC
db.setUserName("khalil");//inserer nom de l'utilisateur
db.setPassword("khalil");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
