#ifndef mysystem_H
#define mysystem_H

#include <QWidget>

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

private:
    //intial mysystem,这里写process
    void initSystem();
    //递归绘制
    void drawsystem(QPainter *painter);
    //更新系统，这里写process
    void updatesystem();
    QList<testcreature*> creaturelist;
    double w;
    double h;
};


#endif // mysystem_H
