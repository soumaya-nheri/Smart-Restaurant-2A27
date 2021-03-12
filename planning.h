#ifndef PLANNING_H
#define PLANNING_H
#include<QString>
#include<QSqlQuery>
#include<QsqlQueryModel>
//test
class planning
{
    QString absence, emploi,nom;
    int cin;

public:

    //Constructeurs
    planning(){}
    planning(int,QString,QString,QString);

    //Getters
    QString get_nom(){return nom;}
    QString get_emploi(){return emploi;}
    QString get_absence(){return absence;}
    int get_cin(){return cin;}


     //Setters
    void set_nom(QString n){nom=n;}
    void set_emploi(QString t){emploi=t;}
    void set_absence(QString a){absence=a;}
    void set_cin(int cin){this->cin=cin;}

    //Fonctionnalites de Base relatives a l'entite commande
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer (int);



};


#endif // COMMANDE_H
