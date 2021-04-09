#include "fournisseur.h"
#include "mainwindow.h"
#include "categorie_impl.h"
#include "ui_fournisseur.h"
#include "fournisseur_impl.h"

#include <QMessageBox>
Fournisseur::Fournisseur(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Fournisseur)
{
    ui->setupUi(this);
    Categorie_Impl c;
     ui->comboBox->addItems(c.getNames());
}

Fournisseur::~Fournisseur()
{
    delete ui;
}

void Fournisseur::on_pushButton_clicked()
{
    QString nom_f = ui->lineEdit->text();
    int tel = ui->lineEdit_2->text().toInt();
    QString categorie = ui->comboBox->currentText();



    if(nom_f == "")
    {
        QMessageBox::critical(nullptr, QObject::tr("problem nom_f"),
                                       QObject::tr("verifier nom_f\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
    }

else if (tel<8){
        QMessageBox::critical(nullptr, QObject::tr("problem tel"),
                                       QObject::tr("verifier tel\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else if (categorie == ""){
            QMessageBox::critical(nullptr, QObject::tr("problem categorie"),
                                           QObject::tr("verifier categorie\n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);
        }
    else
    {
        fournisseur_impl art ;
        art.ajouter(nom_f,categorie,tel);
           ui->tableView->setModel(art.afficher());
    }
}

void Fournisseur::on_pushButton_2_clicked()
{
    fournisseur_impl art ;
    art.supprimer()->removeRow(ui->tableView->currentIndex().row());
      ui->tableView->setModel(art.afficher());
}

void Fournisseur::on_pushButton_3_clicked()
{ hide();
    MainWindow *m = new MainWindow();
    m->show();
}
