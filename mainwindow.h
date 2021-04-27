#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <livreur.h>
#include <livraison.h>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_lineEdit_recherche_textChanged(const QString &arg1);

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_tab_livreur_activated(const QModelIndex &index);

    void on_tab_livraison_activated(const QModelIndex &index);


    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    livreur L ;
    livraison liv;
};
#endif // MAINWINDOW_H
