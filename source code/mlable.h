#ifndef MLABLE_H
#define MLABLE_H

#include<QPushButton>
#include "mpixmap.h"
class MLable : public QPushButton
{
    Q_OBJECT
public:
    MLable(QWidget *parent = 0,QString text="");
    ~MLable();
     MPixmap *Cp;
};

#endif // MLABLE_H
