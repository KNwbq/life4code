#include "mainwindow.h"
#include <QApplication>
#include<QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
<<<<<<< Updated upstream
    w.resize(800,600);

=======
    w.resize(1000,618);
>>>>>>> Stashed changes
    w.show();

    return a.exec();
}
