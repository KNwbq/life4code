#include "mysystem.h"
#include <QPainter>
#include <QPainterPath>
#include<QDebug>
#include <QTimer>
#include <stdlib.h>
#include <time.h>

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
    // testcreature *a1= new testcreature(Qt::blue,this->width()/2,this->height());
    // creaturelist.push_back(a1);
    // qDebug()<<this->width()<<this->height();
    // testcreature *a2=new testcreature(Qt::red,this->width(),this->height()/2);
    // creaturelist.push_back(a2);
    // testcreature *a3 =new testcreature(Qt::green,400,300);
    // creaturelist.push_back(a3);
    const int numGrass = 1000, numGroupCow = 10, numCowPerG = 10, numTiger = 10;
    const double energyGrass = 1e2, energyCow = 1e3, energyTiger = 1e4;
    srand(0);
    for (int i = 0; i < numGrass; ++i)
        grasslist.push_back(0.0, energyGrass, 0,   // 构造函数还有很多要改
                            rand()/double(RAND_MAX)*this->width(),
                            rand()/double(RAND_MAX)*this->height());
    for (int i = 0; i < numGroupCow; ++i) {                  // Cow群落生成
        double centerx = rand()/double(RAND_MAX)*this->width(),
                centery = rand()/double(RAND_MAX)*this->height();
        const double limx = 10, limy = 10;
        for (int j = 0; j < numCowPerG; ++j)
            cowlist.push_back(rand()/double(RAND_MAX)*limx-limx/2+centerx,
                                rand()/double(RAND_MAX)*limy-limy/2+centery);
    }
    for (int i = 0; i < numTiger; ++i)
        tigerlist.push_back(rand()/double(RAND_MAX)*this->width(),
                            rand()/double(RAND_MAX)*this->height());
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
