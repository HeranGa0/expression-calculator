#ifndef MPIXMAP_H
#define MPIXMAP_H
#include<QPixmap>

class MPixmap
{

public:
    MPixmap(QString text);
    ~MPixmap();
    QPixmap* ReturnIcon();
private:
    QPixmap *icon;
};

#endif // MPIXMAP_H
