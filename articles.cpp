#include "articles.h"
#include "ui_articles.h"
#include "articles_impl.h"
#include <QMessageBox>
articles::articles(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::articles)

{
    ui->setupUi(this);
    articles_impl art;
    ui->tableView->setModel(art.afficher());
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
    }
}

void articles::on_pushButton_2_clicked()
{
    articles_impl art ;
    art.supprimer()->removeRow(ui->tableView->currentIndex().row());
      ui->tableView->setModel(art.afficher());
}
