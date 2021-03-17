#ifndef ARTICLE_H
#define ARTICLE_H
#include <QSqlQuery>
#include <QSqlQueryModel>

class Article
{
    QString nom ;
    int q,id;

public:
    Article();
    Article( int,int,QString);
    //getters
    QString getNom() {return nom;}
    int getID(){return id;}
    int getQ(){return q;}
    //setters
    void setNom(QString n){nom=n;}
    void setID(int id){this-> id=id;}
    void setQ(int q){this-> q=q;}
bool ajouter();
QSqlQueryModel * afficher();
bool supprimer(int);



};

#endif // ARTICLE_H
