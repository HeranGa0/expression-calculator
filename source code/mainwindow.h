#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QPushButton>
#include <QWidget>
#include "mlable.h"
#include<QLineEdit>
#include<QStringList>
#include<QMap>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent=0);
    ~Widget();
    MLable * mlab[20];
    QLineEdit * output;
    QString flash();
    int count;
    QStringList dark;
    QMap<MLable*,QString> Kv;

};



#endif // MAINWINDOW_H
