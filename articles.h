#ifndef ARTICLES_H
#define ARTICLES_H

#include <QWidget>

namespace Ui {
class articles;

}

class articles : public QWidget
{
    Q_OBJECT

public:
    explicit articles(QWidget *parent = nullptr);
    ~articles();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::articles *ui;
};

#endif // ARTICLES_H
