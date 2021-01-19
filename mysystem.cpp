#include "mysystem.h"
#include <QPainter>
#include <QPainterPath>
#include<QDebug>
#include <QTimer>
mysystem::mysystem(QWidget *parent)
    :QWidget(parent)
{
    parent->setGeometry(QRect(0,0,800,600));
    this->setGeo(800,600);
    qDebug()<<this->width();
    initSystem();
    QTimer *timer= new QTimer(this);
    connect(timer,&QTimer::timeout,this,[=]{
        updatesystem();
        update();
    });
    timer->start(100);
}
mysystem::~mysystem(){
}

void mysystem::paintEvent(QPaintEvent *event){
    Q_UNUSED(event)
    QPainter painter(this);
    painter.fillRect(this->rect(),Qt::white);
    drawsystem(&painter);
}

void mysystem::initSystem(){
    testcreature *a1= new testcreature(Qt::blue,this->width()/2,this->height());
    creaturelist.push_back(a1);
    qDebug()<<this->width()<<this->height();
    testcreature *a2=new testcreature(Qt::red,this->width(),this->height()/2);
    creaturelist.push_back(a2);
    testcreature *a3 =new testcreature(Qt::green,400,300);
    creaturelist.push_back(a3);
}

void mysystem::drawsystem(QPainter *painter){
    for(testcreature* iter:creaturelist){
        painter->setBrush(iter->getcolor());
       // qDebug()<<iter->getcolor();
      //  qDebug()<<iter->getx()<<iter->gety();
        painter->drawEllipse(QPointF(iter->getx(),iter->gety()),10,10);

    }
}

void mysystem::updatesystem(){

}
