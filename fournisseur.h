#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <QWidget>

namespace Ui {
class Fournisseur;
}

class Fournisseur : public QWidget
{
    Q_OBJECT

public:
    explicit Fournisseur(QWidget *parent = nullptr);
    ~Fournisseur();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();



    void on_recherche_textChanged(const QString &arg1);

private:
    Ui::Fournisseur *ui;
};

#endif // FOURNISSEUR_H
