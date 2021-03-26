#ifndef COMMANDE_H
#define COMMANDE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class commande
{
    QString plats;
    float prixtotale;
    int id;

public:

    //Constructeurs
    commande(){}
    commande(int,QString,float);

    //Getters
    QString get_plats(){return plats;}
    float get_prixtotale(){return prixtotale;}
    int get_id(){return id;}

     //Setters
    void set_plats(QString n){plats=n;}
    void set_prixtotale(float p){prixtotale=p;}
    void set_id(int id){this->id=id;}

    //Fonctionnalites de Base relatives a l'entite commande
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer (int);



};


#endif // COMMANDE_H
