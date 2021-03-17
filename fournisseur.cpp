#include "fournisseur.h"

Fournisseur::Fournisseur(int tel,int id_f,QString nom_f,QString type,QString date)

{

    this ->id_f=id_f;
    this ->tel=tel;
    this ->nom_f=nom_f;
    this ->type=type;
    this ->date=date;

}
bool Fournisseur::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id_f);
    query.prepare("insert into etudiants(id_f,type,nom_f,date,tel)"" values(:id_f,:type,:nom_f,:tel,:date)");
    query.bindValue(":id_f",res);
    query.bindValue(":nom_f",nom_f);
    query.bindValue(":type",type);
    query.bindValue(":date",date);
      query.bindValue(":tel",tel);
    return query.exec();


}

QSqlQueryModel * Fournisseur::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

        model->setQuery("select * from article");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_f"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_f"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("type"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("date"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("tel"));

        return model;
}
bool Fournisseur::supprimer(int id_f)
{
    QSqlQuery query;
    QString res = QString::number(id_f);
    query.prepare("Delete from article where ID=:Id_f");
    query.bindValue(":id_f",res);
      return query.exec();
}
