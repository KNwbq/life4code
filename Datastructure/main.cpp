#include "mainwindow.h"
#include "form.h"
#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Form f;
    f.show();
//    MainWindow w;
//    w.resize(1000,618);
//    w.show();
    return a.exec();
}
