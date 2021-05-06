#include "articles.h"
#include "ui_articles.h"
#include "articles_impl.h"
#include "mainwindow.h"
#include <QMessageBox>
articles::articles(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::articles)

{
    ui->setupUi(this);

    articles_impl art;
    ui->tableView->setModel(art.afficher());
    art.verifier();

}

articles::~articles()
{
    delete ui;
}

void articles::on_pushButton_clicked()
{

    QString nom = ui->txt_Nom->text();
    int quantite = ui->spinBox->text().toInt();


    if(nom == "")
    {
        QMessageBox::critical(nullptr, QObject::tr("problem nom"),
                                       QObject::tr("verifier nom\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
    }

else if (quantite<=0){
        QMessageBox::critical(nullptr, QObject::tr("problem quantite"),
                                       QObject::tr("verifier quantite\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        articles_impl art ;
        art.ajouter(nom,quantite);
           ui->tableView->setModel(art.afficher());

          art.verifier();
    }

}

void articles::on_pushButton_2_clicked()
{
    articles_impl art ;
    art.supprimer()->removeRow(ui->tableView->currentIndex().row());
      ui->tableView->setModel(art.afficher());
}

void articles::on_pushButton_3_clicked()
{  hide();
    MainWindow *m = new MainWindow();
    m->show();
}

void articles::on_imprimer_clicked()
{    articles_impl art ;
  art.telecharger();

    QMessageBox::information(nullptr,QObject::tr("OK"),
               QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);



}

void articles::on_pushButton_4_clicked()
{
    A.write_to_arduino("1");

}
