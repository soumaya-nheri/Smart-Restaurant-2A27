#include "article.h"

Article::Article(int id,int q,QString nom)
{
  this ->id=id;
    this ->q=q;
    this ->nom=nom;

}

bool Article::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("insert into etudiants(id,q,nom)"" values(:id,:q,:nom)");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":q",q);
    return query.exec();


}

QSqlQueryModel * Article::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

        model->setQuery("select * from article");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("q"));

        return model;
}
bool Article::supprimer(int id)
{
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("Delete from article where ID=:Id");
    query.bindValue(":id",res);
      return query.exec();
}
