#ifndef mysystem_H
#define mysystem_H

#include <QWidget>
#include <QMouseEvent>
#include "creature.h"
#include "cow.h"
#include "grass.h"
#include "tiger.h"

class testcreature{
public:
    testcreature(QColor c,double xx,double yy):owncolor(c),x(xx),y(yy){

    }
    ~testcreature(){

    }
    QColor getcolor(){
        return owncolor;
    }
    double getx(){
        return x;
    }
    double gety(){
        return y;
    }


private:
    QColor owncolor;
    int x,y;
};

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
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
private:
    //intial mysystem,这里写process
    void initSystem();
    //递归绘制
    void drawsystem(QPainter *painter);
    //更新系统，这里写process
    void updatesystem();
    QList<testcreature*> creaturelist;
    QList<Tiger*> tigerlist;
    QList<Cow*> cowlist;
    QList<Grass*> grasslist;
    double w;
    double h;
<<<<<<< Updated upstream
=======

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
>>>>>>> Stashed changes
};


#endif // mysystem_H
