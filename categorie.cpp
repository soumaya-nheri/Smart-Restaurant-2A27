#include "categorie.h"
#include "ui_categorie.h"
#include "categorie_impl.h"
#include <QMessageBox>

Categorie::Categorie(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Categorie)
{
    ui->setupUi(this);
    Categorie_Impl cat ;
    ui->tableView->setModel(cat.afficher());
}

Categorie::~Categorie()
{
    delete ui;
}

void Categorie::on_Ajouter_clicked()
{
    QString nom = ui->txt_Nom->text();

    if(nom == "")
    {
        QMessageBox::critical(nullptr, QObject::tr("problem nom"),
                                       QObject::tr("verifier nom\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        Categorie_Impl cat ;
        cat.ajouter(nom);
           ui->tableView->setModel(cat.afficher());
    }


}

void Categorie::on_Supprimer_clicked()
{
    Categorie_Impl cat ;
    cat.supprimer()->removeRow(ui->tableView->currentIndex().row());
      ui->tableView->setModel(cat.afficher());

}

void Categorie::on_txt_Search_textChanged(const QString &arg1)
{
    Categorie_Impl c;

    c.cleartable(ui->tableView);
QString nom = ui->txt_Search->text();
c.recherche(ui->tableView,nom);
if (ui->txt_Search->text().isEmpty())
{
    ui->tableView->setModel(c.afficher());
}
}




