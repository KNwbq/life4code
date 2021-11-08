﻿#include "mysystem.h"
bool got_sleep=0;
int map_w=3000,map_h=618*3;
int init_timer=1000/24;
double scale_ofpix=1;
double shiftx=0,shifty=0,lastshiftx=0,lastshifty=0;
double addtigerv=0,addgrassv=0,addcowv=0;
//QPixmap tiger_move(":/tiger_PNG23229.png");
//QPixmap cow_move(":/cow_move.png");
//QPixmap grass_green(":/grass.png");

mysystem::mysystem(QWidget *parent)
    :QWidget(parent)
{
    tiger_move.load(":/tiger_PNG23229.png");
    cow_move.load(":/cow_move.png");
    grass_green.load(":/grass.png");
    srand(time(NULL));
    this->setGeo(1000,618);
    timer= new QTimer(this);
    connect(timer,&QTimer::timeout,this,[=]{
        updatesystem();
        update();
    });
    timer->start(init_timer);
}
mysystem::~mysystem(){
}

void mysystem::paintEvent(QPaintEvent *event){
    Q_UNUSED(event)
    QPixmap pixmap(size()*3);
    QPainter painter(&pixmap);
    painter.setRenderHints(QPainter::HighQualityAntialiasing
                           | QPainter::Antialiasing
                           | QPainter::TextAntialiasing, true);
    painter.fillRect(pixmap.rect(),Qt::white);
    drawsystem(&painter);
    painter.end();
    painter.begin(this);
    //    qDebug()<<pixmap.size();
    //    painter.scale(1,1);
    //    qDebug()<<this->size();
    painter.drawPixmap(shiftx,shifty,map_w/scale_ofpix,map_h/scale_ofpix,pixmap);
    painter.setBrush(Qt::red);
    painter.drawEllipse(QPointF(500,309),2,2);
//    painter.setFont();
    painter.drawText(800,10,QString("cow: ")+QString::number(cowlist.size()));
    painter.drawText(800,50,QString("tiger: ")+QString::number(tigerlist.size()));
    painter.drawText(800,90,QString("grass: ")+QString::number(grasslist.size()));
}
bool win_move=0;
void mysystem::mousePressEvent(QMouseEvent *event){
    //    qDebug()<<'addtiger:'<<addtigerv;
    qDebug()<<shiftx;
    if (addtigerv==1) tigerlist.insert(new Tiger(2000,(event->localPos().x()-shiftx)*scale_ofpix,(event->localPos().y()-shifty)*scale_ofpix,rand()%2,cnt));
    if (addcowv==1) cowlist.insert(new Cow(2000,(event->localPos().x()-shiftx)*scale_ofpix,(event->localPos().y()-shifty)*scale_ofpix,rand()%2,cnt));
    if (addgrassv==1) grasslist.insert(new Grass(1000,(event->localPos().x()-shiftx)*scale_ofpix,(event->localPos().y()-shifty)*scale_ofpix,10,10,cnt));
    if (!(addtigerv||addcowv||addgrassv)){
        m_lastPoint=event->localPos();
        lastshiftx=shiftx;
        lastshifty=shifty;
        win_move=1;
    }
    update();
}
void mysystem::mouseMoveEvent(QMouseEvent *event){
    if (win_move==1){
        m_nowPoint=event->localPos();
        shiftx=lastshiftx+m_nowPoint.x()-m_lastPoint.x();
        shifty=lastshifty+m_nowPoint.y()-m_lastPoint.y();
        //        qDebug()<<shiftx<<shifty;
    }
    update();
}
void mysystem::mouseReleaseEvent(QMouseEvent *event){
    win_move=0;
    lastshiftx=shiftx;
    lastshifty=shifty;
}

double mysystem::ld_delay(double x){
    if (x>1) return 1;
    if (x<0) return 0;
    return x;
}

void mysystem::initSystem(int x,int y,int z){
    
    const int numGrass = z, numGroupCow = 5, numCowPerG = x/5, numTiger = y;//
    qDebug()<<"fuckkkkkk";
    for (int i = 0; i < numGrass; ++i)
        grasslist.insert(new Grass(1000,
                                   rand()/double(RAND_MAX)*map_w,
                                   rand()/double(RAND_MAX)*map_h,10,10,cnt));
    for (int i = 0; i < numGroupCow; ++i) {
        double centerx = rand()/double(RAND_MAX)*map_w,
                centery = rand()/double(RAND_MAX)*map_h;
        const double limx = 10, limy = 10;
        for (int j = 0; j < rand()%numCowPerG; ++j)
            cowlist.insert(new Cow(2000,rand()/double(RAND_MAX)*limx-limx/2+centerx,
                                   rand()/double(RAND_MAX)*limy-limy/2+centery,rand()%2,cnt));//
    }
    for (int i = 0; i < numTiger; ++i){
        int tmp = rand()%2;
        tigerlist.insert(new Tiger(2000,rand()/double(RAND_MAX)*(map_w-200)+100,
                                   rand()/double(RAND_MAX)*(map_h-200)+100,tmp,cnt));
    }
}

void mysystem::drawsystem(QPainter *painter){

    //    QLinearGradient Linear(100,120,300,350);
    //    Linear.setColorAt(0,Qt::darkGray);
    //    Linear.setColorAt(1,Qt::white);
    //    painter->setPen(Qt::transparent);
    //    painter->setBrush(Qt::darkGray);
    //    painter->drawRect(0,0,800,600);
    for(Grass* iter:grasslist){
        double tmpx=iter->getLoc().real(),tmpy=iter->getLoc().imag();
        if (!(tmpx>=-shiftx*scale_ofpix && tmpx<=(-shiftx+1000)*scale_ofpix && tmpy>=-shifty*scale_ofpix && tmpy<=(-shifty+618)*scale_ofpix)) continue;
        
        //        painter->setBrush(iter->owncolor);
        //        painter->drawEllipse(QPointF(iter->getLoc().real(), iter->getLoc().imag()),2,2);
        //        painter->drawImage(QRectF(iter->getLoc().real(), iter->getLoc().imag(),iter->getLoc().real()+50, iter->getLoc().imag()+50),cow_move,QRectF(0,0,28,18));
        painter->drawPixmap(iter->getLoc().real(), iter->getLoc().imag(),30,30,grass_green);
        //        painter->drawRect(QRectF(iter->getLoc().real(), iter->getLoc().imag(),50, 50));
        //        painter->drawImage(QRectF(iter->getLoc().real(), iter->getLoc().imag(),50, 50),cow_move);
    }
    for(Cow* iter:cowlist){
        double tmpx=iter->getLoc().real(),tmpy=iter->getLoc().imag();
        if (!(tmpx>=-shiftx*scale_ofpix && tmpx<=(-shiftx+1000)*scale_ofpix && tmpy>=-shifty*scale_ofpix && tmpy<=(-shifty+618)*scale_ofpix)) continue;
        painter->setBrush(Qt::white);
        painter->drawRect(tmpx-4,tmpy-4,32,8);
        painter->setBrush(Qt::green);
        painter->drawRect(tmpx-4,tmpy-4,iter->energy/iter->energy_threshhold2*32,8);
        painter->drawEllipse(tmpx,tmpy,2,2);
        if(cnt-iter->getage()>iter->matingage)
        {
            if(cnt-iter->lastgen>100)
                painter->drawPixmap(iter->getLoc().real(), iter->getLoc().imag(),50,50,cow_move);
            //                painter->drawEllipse(QPointF(iter->getLoc().real(), iter->getLoc().imag()),5,5);
            else
                painter->drawPixmap(iter->getLoc().real(), iter->getLoc().imag(),50,50,cow_move);
        }
        else
            painter->drawPixmap(iter->getLoc().real(), iter->getLoc().imag(),50,50,cow_move);
    }
    for(auto iter:tigerlist){
        double tmpx=iter->getLoc().real(),tmpy=iter->getLoc().imag();
        if (!(tmpx>=-shiftx*scale_ofpix && tmpx<=(-shiftx+1000)*scale_ofpix && tmpy>=-shifty*scale_ofpix && tmpy<=(-shifty+618)*scale_ofpix)) continue;
        painter->setBrush(Qt::white);
        painter->drawRect(tmpx-4,tmpy-4,32,8);
        painter->setBrush(Qt::green);
        painter->drawRect(tmpx-4,tmpy-4,iter->energy/iter->energy_threshhold2*32,8);
        if(cnt-iter->getage()>iter->matingage)
        {
            if(cnt-iter->lastgen>100)
                painter->drawPixmap(iter->getLoc().real(), iter->getLoc().imag(),50,50,tiger_move);
            else
                painter->drawPixmap(iter->getLoc().real(), iter->getLoc().imag(),50,50,tiger_move);
        }
        else
            painter->drawPixmap(iter->getLoc().real(), iter->getLoc().imag(),50,50,tiger_move);
    }
    painter->setBrush(QColor(128, 128, 128, 150*ld_delay(sin(cnt*3.14159/(daylong/2))+1/3)));
    if(cnt%daylong==50||cnt%daylong==(daylong/2)-50) emit go_to_sleep();
    //    qDebug()<<cnt<<abs(sin(cnt*3.14159/600))<<150*ld_delay(sin(cnt*3.14159/600)+1/3);
    painter->setPen(Qt::transparent);
    painter->drawRect(0,0,map_w,map_h);

}

struct Node { // Tiger A will hunt cow B
    Tiger* A;
    Cow* B;
    double dis;
    Node(Tiger* A=NULL, Cow* B=NULL): A(A), B(B) { dis = abs(A->getLoc()-B->getLoc()); }
    bool operator<(const Node &op) const {
        return dis > op.dis;
    }
};

struct NodeCG { // Cow eats  Grass
    Cow* C;
    Grass* G;
    double dis;
    NodeCG(Cow* C=NULL, Grass* G=NULL): C(C), G(G) { dis = abs(C->getLoc()-G->getLoc()); }
    bool operator<(const NodeCG &op) const {
        return dis > op.dis;
    }
};



const double pred_rad = 100, prey_rad = 100, eps = 2.4, RunTime = 1.0, Theta = M_PI_2 / 5;
const double tA = 0.2, tSpedMax = 2.5, tB = 0.18, cSpedMax = 2.0, engThresh = 0;
const complex<double> I(0, 1);


std::priority_queue<Node> que;
std::priority_queue<NodeCG> pque;
std::set<Tiger*> matchedt;
std::set<Cow*> matchedc;
QList<Node> huntlist;
QList<pair<Cow*, std::complex<double> > > esclist;
std::set<Cow*> matchedC;
std::set<Grass*> matchedG;
QList<NodeCG> eatList;
std::set<Cow*> escC;
std::set<Grass*> matchG;



void mysystem::matchCG() {
    while (!pque.empty()) pque.pop();
    matchedC.clear(); matchedG.clear();
    eatList.clear();
    int safeRad = 50;
    for (Cow* it: cowlist)
        if (!it->getstate() && it->ishungry()) {// condition hungry and condition safe  (it->ishungry())
            for (Grass* itG: grasslist) {
                int flag = 0;
                for (Tiger* itT: tigerlist)
                    if (abs(itG->getLoc()-itT->getLoc()) < safeRad) { flag = 1; break; }
                if (!flag) pque.push(NodeCG(it, itG));
            }
        }
    while (!pque.empty()) {
        NodeCG tmp = pque.top(); pque.pop();
        if (!matchedC.count(tmp.C) && !matchedG.count(tmp.G)) {
            eatList.push_back(tmp);
            matchedC.insert(tmp.C);
            matchedG.insert(tmp.G);
        }
    }
}

void eatGrass(Cow* C, Grass* G) {
    complex<double> cLoc = C->getLoc(), gLoc = G->getLoc(), cTg = gLoc-cLoc, speed = abs(C->getVel());
    if (abs(cTg) < eps) return; // Cow has eaten the grass
    C->setVel(cTg/abs(cTg)*speed);
    C->setLoc(cLoc+C->getVel());
}

void updateFreeWalk(Creature *it) {
    it->setVel(it->getVel()*exp((Theta*rand()/RAND_MAX*2-Theta)*I));
    int tmp1=1,tmp2=1;
    if (it->getLoc().real()+it->getVel().real()<0 || it->getLoc().real()+it->getVel().real()>800) tmp1=-1;
    if (it->getLoc().imag()+it->getVel().imag()<0 || it->getLoc().imag()+it->getVel().imag()>600) tmp2=-1;
    else {
        if (abs(it->getVel())<0.1){
            double speed=1;
            it->setVel(speed*exp(std::complex<double>(0, (double)rand()/RAND_MAX*M_PI*2)));
        }
        it->setVel(tmp1*it->getVel().real(),tmp2*it->getVel().imag());
    }
    it->setLoc(it->getLoc()+it->getVel()*RunTime);
}

void mysystem::freeWalk() { // cow and tiger would like free walking if they are not hunting or escaping.

    for (Cow *it: cowlist)
        if (it->getenergy() > engThresh && it->getstate() != 3) {
            bool flag = true;
            for (Tiger *pred: tigerlist)
                if (std::abs(it->getLoc()-pred->getLoc()) < prey_rad) {
                    flag = false;
                    break;
                }
            if (flag) updateFreeWalk(it);
        }
    for (Tiger *it: tigerlist)
        if (it->getenergy() > engThresh && !it->getstate() && it->getstate() != 3)
            updateFreeWalk(it);
}

void hunt(Tiger *T, Cow *C) {
    std::complex<double> tLoc = T->getLoc(), cLoc = C->getLoc(), tVel = T->getVel(), TtoC = cLoc-tLoc;
    double dist = abs(TtoC), tSped = abs(tVel);
    if (dist < eps || T->getenergy() < engThresh) return; // hunt will end if T got the C or T has no energy
    if (dist > pred_rad) {
        // get close to the cow slowly
        T->setVel(TtoC/dist*tSped);
        T->setLoc(tLoc+tVel*RunTime);
    }
    else {
        // accelerate
        T->setVel(TtoC/dist*min(tSped+tA*RunTime, tSpedMax));
        T->setLoc(tLoc+tVel*RunTime);
    }
}

void escape() { // update the cows in esclist
    for (auto it: esclist) {
        if (it.first->getenergy() < engThresh) continue;
        double speed = abs(it.first->getVel());
        complex<double> dir = it.second/abs(it.second);
        it.first->setVel(speed*dir);
        int tmp1=1,tmp2=1;
        if (it.first->getLoc().real()+it.first->getVel().real()<0 || it.first->getLoc().real()+it.first->getVel().real()>800) tmp1=-1;
        if (it.first->getLoc().imag()+it.first->getVel().imag()<0 || it.first->getLoc().imag()+it.first->getVel().imag()>600) tmp2=-1;
        it.first->setVel(tmp1*it.first->getVel().real(),tmp2*it.first->getVel().imag());
        it.first->setLoc(it.first->getLoc()+dir*min(cSpedMax, speed+tB*RunTime)*RunTime);
    }
}


double Cross(complex<double> A, complex<double> B) {
    return A.real()*B.imag() - A.imag()*B.real();
}


void mysystem::match() { // clarify the relationship between the creature
    // initialize
    while (!que.empty()) que.pop();
    matchedt.clear(); matchedc.clear();
    huntlist.clear();
    // find out hungry tigers and match the cows
    for (Tiger* it: tigerlist)
        if (it->isadult()) {  // condition hungry or its children is hungry, (what if tiger is children)
            if (it->ishungry() || it->getstate() == 3)
                for (Cow* itcow: cowlist)
                    que.push(Node(it, itcow));
            else it->setstate(0);
        }
    //        else if (it->getstate() != 3) it->setstate(0);
        else {
            if (it->ishungry()) it->setstate(3);
            else it->setstate(0);
        }
    while (!que.empty()) {
        Node tmp = que.top(); que.pop();
        if (!matchedc.count(tmp.B) && !matchedt.count(tmp.A)) {
            huntlist.push_back(tmp);
            matchedc.insert(tmp.B);
            matchedt.insert(tmp.A);
            if (tmp.A->getstate() != 3) tmp.A->setstate(1);
        }
    }
    esclist.clear();          // check which cows will escape
    for (Cow *it: cowlist) {
        bool flag = true;
        complex<double> tmp(0, 0);
        for (Tiger *pred: tigerlist) {
            double dis = std::abs(it->getLoc()-pred->getLoc());
            if (dis < eps) {
                flag = true;
                break;
            }
            if (dis < prey_rad) {
                flag = false;
                tmp += (it->getLoc()-pred->getLoc())/dis/dis;
            }
        }
        if (it->getstate() == 3) flag = true;
        if (flag) {
            it->setstate(0);
            continue;
        }
        it->setstate(1);
        // the cow may choose a "vague" direction to run
        esclist.push_back(make_pair(it, tmp*exp(I*(Theta*rand()/RAND_MAX*2-Theta))));
    }
}

double calEnergy(Creature *it, double k, double t) {
    double v = abs(it->getVel());
    return k*v*v + t;
}

void mysystem::updateEnergy() {
    for (Cow *it: cowlist) if (it->getstate() != 3)
        it->energyloss(calEnergy(it, 0.01, 1));
    for (Tiger *it: tigerlist) {
        it->energyloss(calEnergy(it, 0.01, 1));

    }
    for (Grass *it: grasslist)
        it->energyloss(-0.1);
}
void mysystem::sleep_energy(){
    for (Cow *it: cowlist)
        it->energyloss(300/(daylong*0.33));
    for (Tiger *it: tigerlist) {
        it->energyloss(300/(daylong*0.33));

    }
    for (Grass *it: grasslist)
        it->energyloss(0.1);
}

void mysystem::takeFood() {
    for (auto it: eatList)
        if (abs(it.C->getLoc()-it.G->getLoc()) < eps*4) {
            it.C->energyloss(-it.G->getenergy()*0.9);
            grasslist.erase(it.G);
            delete it.G;
        }
    for (auto it: huntlist)
        if (abs(it.A->getLoc()-it.B->getLoc()) < eps*4) {
            if (it.A->getstate() != 3) {
                it.A->energyloss(-it.B->getenergy()*0.8);
                cowlist.erase(it.B);
                delete it.B;
            }
            else {
                it.B->setstate(3); // how to erase it from esclist?
            }
        }
}

template<class T>
void helpclear(std::set<T*> &s) {
    QList<T*> tmp;
    tmp.clear();
    for (auto it: s)
        if (it->getenergy() < 0) tmp.push_back(it);
    for (auto it: tmp) {
        s.erase(it);
        delete it;
    }
}

void mysystem::clearDeath() {
    helpclear(cowlist);
    helpclear(grasslist);
    helpclear(tigerlist);
}

void mysystem::motherCheck() {
    for (auto it: tigerlist)
        for (auto child: it->childlist)
            if (child->ishungry()) {
                it->setstate(3);
                break;
            }
}

void mysystem::motherFetch() {
    for (auto it: huntlist) {
        if (it.A->getstate() == 3) {
            complex<double> territory(it.A->territoryx, it.A->territoryy);
            if (abs(it.A->getLoc()-territory) < eps) {
                bool flag = false;
                for (auto child: it.A->childlist) if (child) {
                    child->setstate(3);
                    child->setVel(abs(child->getVel())*normalize(it.B->getLoc()-child->getLoc()));
                    child->setLoc(child->getLoc()+child->getVel()*RunTime);
                    if (abs(child->getLoc()-it.B->getLoc()) < eps) {
                        flag = true;
                        child->energyloss(-it.B->getenergy()*0.9);
                        cowlist.erase(it.B);
                        delete it.B;
                        break;
                    }
                }
                if (flag) {
                    it.A->setstate(0);
                    for (auto child: it.A->childlist) if (child) {
                        child->setstate(0);
                    }
                }
            }
            else {
                it.A->setVel(abs(it.A->getVel())*normalize(territory-it.A->getLoc()));
                it.B->setVel(abs(it.B->getVel())*normalize(territory-it.B->getLoc()));
                it.A->setLoc(it.A->getLoc()+it.A->getVel()*RunTime);
                it.B->setLoc(it.B->getLoc()+it.A->getVel()*RunTime);
            }
        }
    }
}

void mysystem::Hang_out(Creature* x){
    if (x->ifsleep==1){
        if (got_sleep==1) return;
        x->ifsleep=0;
    }
    else if (got_sleep==1){
        if (rand()%15<11) {
            x->ifsleep=1;
            return;
        }
    }
    if(typeid(*x).name()==typeid(Tiger).name()){
        Tiger* xx=dynamic_cast<Tiger*>(x);
        double vecx=0,vecy=0,svecx=0,svecy=0;
        for(auto iter:tigerlist){
            if(xx->sex==0) xx->territoryr=20;
            vecx=iter->getLoc().real() - xx->getLoc().real();
            vecy=iter->getLoc().imag() - xx->getLoc().imag();
            if(vecx>-20&&vecx<=20 && -20<=vecy && vecy<=20){
                if(rand()%15<2 && xx->getenergy()>=xx->energy_threshhold2 && iter->getenergy()>=iter->energy_threshhold2 && xx->sex^iter->sex && cnt-xx->getage()>xx->matingage && cnt-iter->getage()>iter->matingage){
                    iter->mate=xx;
                    xx->mate=iter;
                    Tiger* babe = new Tiger(xx->getenergy()/3,iter->getLoc().real(),iter->getLoc().imag(),rand()%2,cnt);
                    tigerlist.insert(babe);
                    if(iter->sex==0) iter->childlist.push_back(babe);
                    else xx->childlist.push_back(babe);
                    iter->lastgen=xx->lastgen=cnt;
                    xx->energyloss(xx->getenergy()/3);
                    iter->energyloss(iter->getenergy()/3);
                }
                continue;
            }
        }
        double fir=rand()%10;
        double dis_sum[37];
        dis_sum[0]=0;
        if (xx->change_time==0){
            for(int i=0;i<36;i++)
            {
                double angle_next=i*10+fir;
                double x_next=xx->territoryx+xx->territoryr*cos(angle_next*3.14159/180);
                double y_next=xx->territoryy+xx->territoryr*sin(angle_next*3.14159/180);
                double x_dif=x_next-xx->getLoc().real();
                double y_dif=y_next-xx->getLoc().imag();
                double dis=sqrt(x_dif*x_dif+y_dif*y_dif);
                dis_sum[i+1]=dis_sum[i]+dis;
            }
            int pos=upper_bound(dis_sum,dis_sum+37,rand()/double(RAND_MAX)*dis_sum[36])-dis_sum;
            double angle_pos=10*pos+fir;
            double x_next=xx->territoryx+xx->territoryr*cos(angle_pos*3.14159/180);
            double y_next=xx->territoryy+xx->territoryr*sin(angle_pos*3.14159/180);

            svecx=x_next-xx->getLoc().real();
            svecy=y_next-xx->getLoc().imag();
            normalize(svecx,svecy);
            xx->now_vecx=svecx;
            xx->now_vecy=svecy;
            if(xx->sex==1)
                xx->change_time=75+rand()%10;
            else xx->change_time=30+rand()%10;
        }
        else xx->change_time--;
        complex<double> tmp1=xx->getVel();
        complex<double> tmp2(xx->now_vecx,xx->now_vecy);
        double tmp3=(tmp1.real()*tmp2.real()+tmp1.imag()*tmp2.imag())/abs(tmp1)/abs(tmp2);
        if (tmp3>1) tmp3=0.99;
        if (tmp3<-1) tmp3=-0.99;
        double the1=acos(tmp3);
        if (abs(the1)>Theta){
            if (the1>0)
                xx->setVel(xx->getVel()*exp((Theta)*I));
            else
                xx->setVel(xx->getVel()*exp((-Theta)*I));
        }
        else{
            xx->setVel(xx->getVel()*exp((the1)*I));
        }
        xx->setLoc(xx->getLoc()+xx->getVel()*RunTime);
    }
    else if(typeid(*x).name()==typeid(Cow).name()){
        double vecx=0,vecy=0,svecx=0,svecy=0;
        Cow* xx=dynamic_cast<Cow*>(x);
        for(auto iter:cowlist){
            vecx=iter->getLoc().real() - xx->getLoc().real();
            vecy=iter->getLoc().imag() - xx->getLoc().imag();
            if(vecx>-20&&vecx<=20 && -20<=vecy && vecy<=20){
                if(rand()%15<2 && xx->getenergy()>=xx->energy_threshhold2
                        && iter->getenergy()>=iter->energy_threshhold2 && xx->sex^iter->sex &&
                        cnt-xx->getage()>xx->matingage && cnt-iter->getage()>iter->matingage){
                    cowlist.insert(new Cow(xx->getenergy()/3,iter->getLoc().real(),iter->getLoc().imag(),rand()%2,cnt));
                    iter->lastgen=xx->lastgen=cnt;
                    xx->energyloss(xx->getenergy()/3);
                    iter->energyloss(iter->getenergy()/3);
                }
                continue;
            }
            double weight=1;
            if (xx->sex^iter->sex) weight=2;
            svecx+=weight*vecx/sqrt(vecx*vecx+vecy*vecy);
            svecy+=weight*vecy/sqrt(vecx*vecx+vecy*vecy);
        }
    }
}

void mysystem::normalize(double &x, double &y) {
    double len = sqrt(x*x + y*y);
    x = x/len;
    y = y/len;
}

complex<double> mysystem::normalize(complex<double> z){
    return z / abs(z);
}

void mysystem::updatesystem(){
    cnt++;
    motherCheck();
    match();
    motherFetch();
    for (auto it: huntlist) hunt(it.A, it.B);
    escape();
    matchCG();
    for (auto it: eatList) eatGrass(it.C, it.G);
    takeFood();
    clearDeath();
    for(auto iter:tigerlist){
        if (iter->getenergy()>iter->energy_threshhold || cnt-iter->getage()<iter->matingage)Hang_out(iter);
    }
    for(auto iter:cowlist){
        if (iter->getenergy()>iter->energy_threshhold || cnt-iter->getage()<iter->matingage)Hang_out(iter);
    }
    freeWalk();
    updateEnergy();
}
void mysystem::get_sleep(){
    got_sleep=!got_sleep;
    qDebug()<<got_sleep;
}
void mysystem::stoptime(){
    timer->stop();
}
void mysystem::retime(){
    timer->start(1000/60);
}

void add_state_clear(){
    addcowv=0,addtigerv=0,addgrassv=0;
}

void mysystem::addcow(){
    if (addcowv==1) addcowv=0;
    else{
        add_state_clear();
        addcowv=1;
    }
}
void mysystem::addtiger(){
    if (addtigerv==1) addtigerv=0;
    else{
        add_state_clear();
        addtigerv=1;
    }
}
void mysystem::addgrass(){
    if (addgrassv==1) addgrassv=0;
    else{
        add_state_clear();
        addgrassv=1;
    }
}
void mysystem::change_speed(int x){
    x/=5;
    x++;
    //    qDebug()<<x;
    timer->setInterval(init_timer/x);
}
void mysystem::scale_inc(){
    scale_ofpix*=2;
    shiftx=-(-shiftx/2-1000/4);
    shifty=-(-shifty/2-618/4);

}
void mysystem::scale_dec(){
    scale_ofpix/=2;
    shiftx=-(-shiftx*2+1000/2);
    shifty=-(-shifty*2+618/2);
}
//void mysystem::tss(){
//    int a=1;
//}


