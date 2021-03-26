#include "menu.h"
#include "ui_menu.h"
#include "menu_impl.h"
#include <QMessageBox>

Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    Menu_Impl cat ;
    ui->tableView->setModel(cat.afficher());
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_Ajouter_clicked()
{ float prixcheck;
    QString nom = ui->txt_Nom->text();
    QString prix = ui->txt_Prix->text();

    if(nom == "")
    {
        QMessageBox::critical(nullptr, QObject::tr("Probleme"),
                                       QObject::tr("Case obligatoire\nverifier le nom\n"), QMessageBox::Cancel);
    }
    if(prix == "")
    {
        QMessageBox::critical(nullptr, QObject::tr("Probleme"),
                                       QObject::tr("Case obligatoire\nverifier le prix\n"), QMessageBox::Cancel);
    }

    if(prix == "")
    {
        QMessageBox::critical(nullptr, QObject::tr("Case obligatoire"),
                                       QObject::tr("verifier le prix\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        Menu_Impl cat ;
        cat.ajouter(nom,prix);
           ui->tableView->setModel(cat.afficher());
    }


}

void Menu::on_Supprimer_clicked()
{
    Menu_Impl cat ;
    cat.supprimer()->removeRow(ui->tableView->currentIndex().row());
      ui->tableView->setModel(cat.afficher());

}

void Menu::on_txt_Search_textChanged(const QString &arg1)
{
    Menu_Impl c;

    c.cleartable(ui->tableView);
QString nom = ui->txt_Search->text();
c.recherche(ui->tableView,nom);
if (ui->txt_Search->text().isEmpty())
{
    ui->tableView->setModel(c.afficher());
}
}
