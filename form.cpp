#include "form.h"
#include "ui_form.h"
#include<QDialog>
extern MainWindow w;
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

}

Form::~Form()
{
    delete ui;
}

void Form::on_simulatebut_clicked()
{
    auto w=new MainWindow;
    //Mainwindow w;
    w->resize(1000,618);
   w->setnum(ui->cowline->text().toInt(),ui->tigerline->text().toInt() , ui->grassline->text().toInt());
    w->show();
//    QDialog dig(this);
//    dig.hide();
//    dig.exec();
    qDebug()<<"here";
    this->hide();

}
