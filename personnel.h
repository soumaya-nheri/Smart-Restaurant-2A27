#ifndef PERSONNEL_H
#define PERSONNEL_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class personnel
{
    QString nom, mail,service, mot_de_passe;
    int cin,tel;

public:

    //Constructeurs
    personnel(){}
    personnel(int,int,QString,QString,QString,QString);

    //Getters
    QString get_nom(){return nom;}
    QString get_mail(){return mail;}
    QString get_service(){return service;}
    QString get_mot_de_passe(){return mot_de_passe;}
    int get_cin(){return cin;}
    int get_tel(){return tel;}

     //Setters
    void set_nom(QString n){nom=n;}
    void set_mail(QString m){mail=m;}
    void set_service(QString s){service=s;}
    void set_mot_de_passe(QString x){mot_de_passe=x;}
    void set_cin(int cin){this->cin=cin;}
    void set_tel(int tel){this->tel=tel;}

    //Fonctionnalites de Base relatives a l'entite commande
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer (int);



};


#endif // PERSONNEL_H
