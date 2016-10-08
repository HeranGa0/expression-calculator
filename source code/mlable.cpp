#include "mlable.h"

MLable::MLable(QWidget *parent, QString text)
    : QPushButton(parent)
{   this->setFlat(true);
    this->setFixedSize(100,100);
  MPixmap *Cp=new MPixmap(text);
  QPixmap * pic=Cp->ReturnIcon();
  this->setIcon(*pic);
  this->setIconSize(pic->rect().size());

  //this->setText("Hello");

}

MLable::~MLable()
{
    delete Cp;
}
