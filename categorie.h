#ifndef CATEGORIE_H
#define CATEGORIE_H

#include <QMainWindow>

namespace Ui {
class Categorie;
}

class Categorie : public QMainWindow
{
    Q_OBJECT

public:
    explicit Categorie(QWidget *parent = nullptr);
    ~Categorie();

private slots:
    void on_Ajouter_clicked();

    void on_Supprimer_clicked();

    void on_txt_Search_textChanged(const QString &arg1);

private:
    Ui::Categorie *ui;
};

#endif // CATEGORIE_H
