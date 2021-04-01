#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <QString>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlTableModel>

class Personnel
{
public:
    Personnel();
    Personnel(int,int,QString,QString,QString,QString);
    int getcin();
    int gettel();
    QString getservice();
    QString getnom();
    QString getmail();
    QString getmot_de_passe();
    void setcin(int);
    void settel(int);
    void setservice(QString);
    void setnom(QString);
    void setmail(QString);
    void setmot_de_passe(QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_CIN();
    QSqlQueryModel * afficher_NOM();
    bool supprimer(int);
    bool modifier(int ,int ,QString , QString , QString ,QString );
    void cleartable(QTableView * table);
    void recherche(QTableView * tabl, QString);


private:
    int tel,cin;
    QString nom, mail, service,mot_de_passe;
};

#endif // PERSONNEL_H
