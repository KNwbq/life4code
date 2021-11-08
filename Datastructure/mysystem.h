﻿#ifndef mysystem_H
#define mysystem_H

#include <QWidget>
#include <QMouseEvent>
#include "creature.h"
#include "cow.h"
#include "grass.h"
#include "tiger.h"
#include <set>
#include <QPainter>
#include <QPainterPath>
#include <QDebug>
#include <QTimer>
#include <QPixmap>
#include <stdlib.h>
#include<queue>
#include <time.h>
#include<complex>
#include<cmath>
using namespace std;
class mysystem: public QWidget
{
    Q_OBJECT
public:
    double width(){
        return w;
    }
    double height(){
        return h;
    }
    void setGeo(double x,double y){
        w=x,h=y;
    }
    explicit mysystem(QWidget *parent = nullptr);
    ~mysystem();
    QTimer *timer;
    int cnt=0;
    int daylong=1200;
    void normalize(double &, double &);
    complex<double> normalize(complex<double>);
    void initSystem(int,int,int);
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
private:
    QPointF m_nowPoint;
    QPointF m_lastPoint;
    
    void drawsystem(QPainter *painter);
    void updatesystem();
    void sleep_energy();
    void Hang_out(Creature*);
    void match();
    void matchCG();
    void freeWalk();
    void takeFood();
    void clearDeath();
    double ld_delay(double);
    void updateEnergy();
    void motherCheck();
    void motherFetch();
    set<Tiger*> tigerlist;
    set<Cow*> cowlist;
    set<Grass*> grasslist;
    double w;
    double h;

    bool day_or_night;

    QPixmap grass_green;
    QPixmap cow_move;
    QPixmap tiger_move;
signals:
    void go_to_sleep();
public slots:
    void get_sleep();
    void stoptime();
    void change_speed(int);
    void addgrass();
    void addtiger();
    void addcow();
    void retime();
    void scale_inc();
    void scale_dec();
//    void tss();
};


#endif // mysystem_H
