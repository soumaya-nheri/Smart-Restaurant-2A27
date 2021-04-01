#include "personnel.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QTableView>
#include <QSqlTableModel>
#include <QDate>

Personnel::Personnel()
{
cin=0;
tel=0;
service=" ";
nom=" ";
mail=" ";
mot_de_passe=" ";
}

Personnel::Personnel(int cin,int tel,QString service, QString nom, QString mail,QString mot_de_passe)
{
    this->cin=cin; this->nom=nom; this->mail=mail; this->service=service; this->tel=tel; this->mot_de_passe=mot_de_passe;
}
int Personnel::getcin(){return cin;}
int Personnel::gettel(){return tel;}
QString Personnel::getservice(){return service;}
QString Personnel:: getnom(){return nom;}
QString Personnel:: getmail(){return mail;}
QString Personnel:: getmot_de_passe(){return mot_de_passe;}
void Personnel::setcin(int cin){this->cin=cin;}
void Personnel::settel(int tel){this->tel=tel;}
void Personnel::setservice(QString service){this->service=service;}
void Personnel::setnom(QString nom){this->nom=nom;}
void Personnel::setmail(QString mail){this->mail=mail;}
void Personnel::setmot_de_passe(QString mot_de_passe){this->mot_de_passe=mot_de_passe;}


bool Personnel::ajouter(){

    QSqlQuery query;
    QString id_string = QString::number(cin);
    query.prepare("INSERT INTO personnel (cin, nom, mail, service, tel, mot_de_passe) "
                  "VALUES (:id, :forename, :surname, :service, :tel, :mot_de_passe)");
    query.bindValue(0, id_string);
    query.bindValue(1, nom);
    query.bindValue(2, mail);
    query.bindValue(3, service);
    query.bindValue(4, tel);
    query.bindValue(5, mot_de_passe);


    return query.exec();
}

QSqlQueryModel * Personnel::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT * FROM personnel");

          model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAIL"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("SERVICE"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("TEL"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("MOT DE PASSE"));



    return model;
}

bool Personnel::supprimer(int cin)
{
    QSqlQuery query;
    query.prepare("Delete from personnel where cin=:cin");
    query.bindValue(0, cin);
    return query.exec();

}

bool Personnel::modifier(int cin,int tel,QString service, QString nom, QString mail,QString mot_de_passe)
{

    QSqlQuery query;

    query.prepare("UPDATE personnel SET CIN=:cin,SERVICE=:service,TEL=:tel,NOM=:nom,MAIL=:mail,MOT_DE_PASSE=:mot_de_passe where CIN=:CIN ");
    query.bindValue(":CIN",cin);
    query.bindValue(":TEL",tel);
    query.bindValue(":SERVICE",service);
    query.bindValue(":NOM",nom);
    query.bindValue(":MAIL",mail);
    query.bindValue(":MOT_DE_PASSE",mot_de_passe);
          return    (query.exec());
}

void Personnel :: recherche(QTableView * table ,QString nom )
{
    QSqlQueryModel *model= new QSqlQueryModel();

    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from personnel where NOM like '%"+nom+"%' ;");


    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();

}
void Personnel::cleartable(QTableView * table)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->clear();
    table->setModel(model);
}

QSqlQueryModel * Personnel ::afficher_CIN()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from personnel");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));

        return model;
}

QSqlQueryModel * Personnel ::afficher_NOM()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select nom from personnel");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));

        return model;
}
