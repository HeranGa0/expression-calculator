#include "mainwindow.h"
#include<QString>
#include<cal.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QStringList table;
    table<<"1"<<"2"<<"3"<<"+"<<"on"<<"4"<<"5"<<"6"<<"-"<<"off"<<"7"<<"8"<<"9"<<"*"<<"c"<<"0"<<"("<<")"<<"/"<<"=";
    QString recie[20];
    for(int a=0;a<=19;a++)
    {
        recie[a]=table.at(a).toLocal8Bit().constData();
    }

    count=0;
    for(int y=80;y<=320;y+=80)
    {
        for(int x=10;x<=330;x+=80)
        {
             MLable* lab=new MLable(this,recie[count]);
             mlab[count]=lab;
             Kv[lab]=recie[count];
             lab->setGeometry(x,y,100,100);
             connect(lab,&MLable::clicked,this,&Widget::flash);
             count++;
        }
    }
    output=new QLineEdit(this);
    output->setAlignment(Qt::AlignRight);
    output->setGeometry(0,0,500,80);
    this->setGeometry(10,100,600,600);


}

QString Widget::flash()
{
    if (MLable* btn = dynamic_cast<MLable*>(this->sender())){
    if(Kv.value(btn)=="on"){
        dark.clear();
        output->setEnabled(true);
        output->setText("0");
        return Kv.value(btn);

    }
      else if(Kv.value(btn)=="off") {
        dark.clear();
        output->clear();
        output->setEnabled(false);
        return Kv.value(btn);
    }
       else if(Kv.value(btn)=="c"){
        dark.clear();
        output->clear();
        output->setText("0");
        return Kv.value(btn);
    }
        else if(Kv.value(btn)=="="){
        dark.insert(0,"(");
        dark.append(")");
        QString join=dark.join("");
        int anwser=calculate(join);
        dark.clear();
        QString final=QString::number(anwser);
        output->setText(final);
        return Kv.value(btn);
    }



            dark<<Kv.value(btn);
            output->setText(dark.join(""));
            return "cal";

        }
    return "error";

}

Widget::~Widget()
{

}



