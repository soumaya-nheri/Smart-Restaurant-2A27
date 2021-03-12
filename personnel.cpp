#include "personnel.h"

personnel::personnel(int cin,int tel,QString nom ,QString mail,QString service,QString mot_de_passe)
{
    this->cin=cin;
    this->tel=tel;
    this->nom=nom;
    this->mail=mail;
    this->service=service;
    this->mot_de_passe=mot_de_passe;

}



bool personnel::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(cin);

    //prepare() prend la requete en parametre pour la preparer a l'execution

    query.prepare("insert into commande (id,plats,prixtotale)" "values (:cin, :tel, :nom, :mail,:service, :mot_de_passe)");

    //Creation des variables liées
    query.bindValue(":cin",res);
    query.bindValue(":tel",tel);
    query.bindValue(":nom",nom);
    query.bindValue(":mail",mail);
    query.bindValue(":service",service);
    query.bindValue(":mot_de_passe",mot_de_passe);

    return query.exec(); //exec() envoie la requete pour l"executeur

}


QsqlQueryModel * personnel::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from personnel");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("tel"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("mail"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("service"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("mot_de_passe"));

    return model;
}

bool personnel::supprimer(int cin)
{
    QSqlQuery query;
    QString res = QString::number(cin);
    query.prepare("Delete from commande where ID=:cin");
    query.bindValue(":cin",res);
    return query.exec();
}
