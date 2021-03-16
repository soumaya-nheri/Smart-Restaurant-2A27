#ifndef MENU_H
#define MENU_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
class menu
{
    QString nom, prix;
    int id;

public:

    //Constructeurs
    menu(){}
    menu(int,QString,QString);

    //Getters
    QString get_nom(){return nom;}
    QString get_prix(){return prix;}
    int get_id(){return id;}

     //Setters
    void set_nom(QString n){nom=n;}
    void set_prix(QString p){prix=p;}
    void set_id(int id){this->id=id;}

    //Fonctionnalites de Base relatives a l'entite menu
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer (int);



};

#endif // MENU_H
