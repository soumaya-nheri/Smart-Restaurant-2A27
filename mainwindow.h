#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_gestio_tables_clicked();

    void on_pushButton_2_clicked();

    void on_menu_clicked();

    void on_gestion_personnel_clicked();

    void on_gestion_livraison_clicked();

    void on_gestion_article_clicked();

    void on_gestion_fournisseur_clicked();

    void on_gestion_categorie_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
