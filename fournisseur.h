#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QSqlQuery>
#include <QSqlQueryModel>

class Fournisseur
{
    QString nom_f,type,date ;
    int tel,id_f;
public:
    Fournisseur();
    Fournisseur( int,int,QString,QString,QString);
    //getters
    QString getNom() {return nom_f;}
     QString getType() {return type;}
      QString getDate() {return date;}
    int getID(){return id_f;}
    int getTel(){return tel;}
    //setters
    void setNom(QString n_f){nom_f=n_f;}
    void setType(QString t){type=t;}
    void setDate(QString d){date=d;}
    void setID(int id_f){this-> id_f=id_f;}
    void setTel(int tel){this-> tel=tel;}
bool ajouter();
QSqlQueryModel * afficher();
bool supprimer(int);


};

#endif // FOURNISSEUR_H
