#ifndef TABLE_H
#define TABLE_H
#include "gestion_table.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCore/qglobal.h>

class table
{
public:
    table();
    table(QString num_table, int nombre_places);

    QString getNum_table();
    void setNum_table(QString &value);
    int getNombre_places();
    void setNombre_places(int &value);
    bool ajouter();
    void afficher(Ui::Gestion_table *ui);
    bool Supprimer(Ui::Gestion_table *ui);
    bool modifier(Ui::Gestion_table *ui);
    void afficher_vide(Ui::Gestion_table *ui);
    void afficher_reserve(Ui::Gestion_table *ui);

private:
 QString num_table;
 int nombre_places;
};

#endif // TABLE_H
