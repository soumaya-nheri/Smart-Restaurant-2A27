#ifndef MENU_H
#define MENU_H
#include "stat_commande.h"
#include <QMainWindow>

namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_Ajouter_clicked();
    void on_Supprimer_clicked();
    void on_Supprimer2_clicked();
    void on_Supprimer3_clicked();
    void on_txt_Search_textChanged(const QString &arg1);
    void on_Valider_clicked();
    void on_Actualiser_clicked();
    void on_imprimer_clicked();
    void on_Trier_clicked();
    void on_statistique_clicked();

    void on_Retour_clicked();

    void on_Retour_2_clicked();

private:
    Ui::Menu *ui;
    stat_commande *s;
};

#endif // MENU_H
