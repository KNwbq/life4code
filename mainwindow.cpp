#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    qDebug()<<"herefuck";
    ui->setupUi(this);
    setWindowTitle("Enclosed System");
    connect(ui->hide_but,SIGNAL(clicked(bool)),this,SLOT(hide_them()));
    connect(ui->stop_but,SIGNAL(clicked(bool)),this,SLOT(play_or_pause()));
    ui->play_but->setHidden(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::hide_them(){
    ui->add_group->setHidden(!(ui->add_group->isHidden()));
    qDebug()<<ui->hide_but->text();
    if(ui->hide_but->text()=="hide")
    ui->hide_but->setText("show");
    else ui->hide_but->setText("hide");
}
void MainWindow::setnum(int x, int y, int z){
    ui->centralWidget->initSystem(x,y,z);
}

void MainWindow::play_or_pause(){
    if(ui->stop_but->styleSheet()!="border-image: url(:/st.png);"){
        ui->stop_but->setStyleSheet("border-image: url(:/st.png);");
        ui->centralWidget->stoptime();
    }
    else{
        ui->stop_but->setStyleSheet("border-image: url(:/pause.png);");
        ui->centralWidget->retime();
    }
}
