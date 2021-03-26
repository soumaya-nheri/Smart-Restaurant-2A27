#include "commande.h"

commande::commande(int id,QString plats ,float prixtotale)
{
    this->id=id;
    this->plats=plats;
    this->prixtotale=prixtotale;

}



bool commande::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id);

    //prepare() prend la requete en parametre pour la preparer a l'execution

    query.prepare("insert into commande (id,plats,prixtotale)" "values (:id, :plats, :prixtotale)");

    //Creation des variables liées
    query.bindValue(":id",res);
    query.bindValue(":plats",plats);
    query.bindValue(":prixtotale",prixtotale);

    return query.exec(); //exec() envoie la requete pour l"executeur

}


QSqlQueryModel * commande::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from commande");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("plats"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prixtotale"));

    return model;
}

bool commande::supprimer(int id)
{
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("Delete from commande where ID=:id");
    query.bindValue(":id",res);
    return query.exec();
}
