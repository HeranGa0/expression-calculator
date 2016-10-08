#include "mpixmap.h"
#include<QFont>
#include<QPainter>
#include<QRect>
MPixmap::MPixmap(QString text)
{
   icon= new QPixmap(80,80);
   QRect rect=icon->rect();
    QPainter p(icon);
    p.setBrush(QBrush(Qt::gray));
    p.drawRect(0, 0,100, 100);
    QFont f1;
    f1.setPointSize(18);
    p.setFont(f1);
   p.drawText(rect, Qt::AlignCenter,text);
}


 QPixmap* MPixmap::ReturnIcon()
{
    return icon;
}

MPixmap::~MPixmap()
{
    delete icon;
}
