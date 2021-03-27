#include "menu.h"
#include "ui_menu.h"
#include "menu_impl.h"
#include "commande_impl.h"
#include <QMessageBox>

/*Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    Commande_Impl cat ;
    ui->tableView2->setModel(cat.afficher());
}
Menu::~Menu()
{
    delete ui;
}*/

void Menu::on_Valider_clicked()
{
    QString plats = ui->txt_Nom->text();
     QString prixtotale = ui->txt_Nom->text();


    if(plats == "")
    {
        QMessageBox::critical(nullptr, QObject::tr("Probleme"),
                                       QObject::tr("Case obligatoire\nverifier le nom\n"), QMessageBox::Cancel);
    }
    else
    {
        Commande_Impl cat ;
        cat.ajouter(plats,prixtotale);
           ui->tableView->setModel(cat.afficher());
    }


}

/*void Menu::on_Supprimer_clicked()
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
*/
