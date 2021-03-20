#include "supprimer.h"
#include "ui_supprimer.h"
#include "personnel.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"

supprimer::supprimer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supprimer)
{
    ui->setupUi(this);
}

supprimer::~supprimer()
{
    delete ui;
}

void supprimer::on_pb_supprimer_clicked()
{


        Personnel P1; P1.setcin(ui->le_id_supp->text().toInt());
        bool test=P1.supprimer(P1.getcin());

        QMessageBox msgBox;
        if(test)
        {
        msgBox.setText("Suppression avec succes.");
        //ui->tab_personnel->setModel(P.afficher());
        }
        else
        msgBox.setText("Echec de suppression");
        msgBox.exec();

}
