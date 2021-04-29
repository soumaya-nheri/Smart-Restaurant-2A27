#ifndef ALERTE_H
#define ALERTE_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>

class alerte : public QWidget
{
   Q_OBJECT

   public:
   alerte();

   public slots:
   void ouvrirDialogue();

   private:
   QPushButton *m_boutonDialogue;
};

#endif


