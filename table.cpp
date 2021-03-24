#include "tables.h"
#include "ui_tables.h"
#include "tables_impl.h"
#include <QMessageBox>

Tables::Tables(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Tables)
{
    ui->setupUi(this);
    Tables_Impl cat ;
    ui->tableView->setModel(cat.afficher());
}

Tables::~Tables()
{
    delete ui;
}

void Tables::on_Ajouter_clicked()
{
   int id = ui->txt_Nom->text();

    if(nom == "")
    {
        QMessageBox::critical(nullptr, QObject::tr("problem id"),
                                       QObject::tr("verifier id\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        Tables_Impl cat ;
        cat.ajouter(id);
           ui->tableView->setModel(cat.afficher());
    }


}

void Tables::on_Supprimer_clicked()
{
    Tables_Impl cat ;
    cat.supprimer()->removeRow(ui->tableView->currentIndex().row());
      ui->tableView->setModel(cat.afficher());

}

void Tables::on_txt_Search_textChanged(const int &arg1)
{
    Tables_Impl c;

    c.cleartable(ui->tableView);
int id = ui->txt_Search->text();
c.recherche(ui->tableView,id);
if (ui->txt_Search->text().isEmpty())
{
    ui->tableView->setModel(c.afficher());
}
}




