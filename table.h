#ifndef TABLES_H
#define TABLES_H

#include <QMainWindow>

namespace Ui {
class Tables;
}

class Tables : public QMainWindow
{
    Q_OBJECT

public:
    explicit Tables(QWidget *parent = nullptr);
    ~Tables();

private slots:
    void on_Ajouter_clicked();

    void on_Supprimer_clicked();

    void on_txt_Search_textChanged(const QString &arg1);

private:
    Ui::Tables *ui;
};

#endif // TABLES_H
