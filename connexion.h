#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>

class connexion
{
private:
    QSqlDatabase db;

public:
    connexion();
    void fermerConnexion();
     bool ouvrirConnexion();
};

#endif // CONNEXION_H
