#ifndef COMMANDE_H
#define COMMANDE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class commande
{
    QString plats, prixtotale;
    int id;

public:

    //Constructeurs
    commande(){}
    commande(int,QString,QString);

    //Getters
    QString get_plats(){return plats;}
    QString get_prixtotale(){return prixtotale;}
    int get_id(){return id;}

     //Setters
    void set_plats(QString n){plats=n;}
    void set_prixtotale(QString p){prixtotale=p;}
    void set_id(int id){this->id=id;}

    //Fonctionnalites de Base relatives a l'entite commande
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer (int);



};


#endif // COMMANDE_H
