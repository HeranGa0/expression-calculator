#include "mainwindow.h"
#include <QApplication>
#include<QMainWindow>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow * MainWindow= new QMainWindow;
    Widget *w=new Widget(MainWindow);

    MainWindow->show();

    return a.exec();
}
