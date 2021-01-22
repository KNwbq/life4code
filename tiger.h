//first version of class Tiger (prototype
//2021/1/18

#ifndef TIGER_H
#define TIGER_H
#include "creature.h"

class Tiger:public Creature {
public:
        virtual double getspeed() = 0;//every species has its own random speed
        virtual void energyloss(double) = 0;//how we define the energy loss, using speed or else?
        virtual bool ishungry() = 0;
        double getenergy();
        double displayx();
        double displayy();
        Tiger(double, double, double, double, double, double);

private:
        const double matingage;//the age whether the tigers can mating
        const double energy_threshhold;//when tiger is hungry
};

Tiger::Tiger(double speed_, double energy_, double x, double y, double matingage_, double energy_threshhold_):matingage(matingage_), energy_threshhold(energy_threshhold_) {
        speed = speed_;
        energy = energy_;
        coordinatex = x; 
        coordinatey = y;
        hungry = false;
}

double Tiger::getspeed() { return speed; }
void Tiger::energyloss(double cost) { energy -= cost; if(energy < energy_threshhold) hungry = true; }
bool Tiger::ishungry() { return hungry; }
double Tiger::getenergy() { return energy; }
double Tiger::displayx() { return coordinatex; }
double Tiger::displayy() { return coordinatey; }

#endif // TIGER_H