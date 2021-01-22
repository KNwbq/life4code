//first version of class Cow (prototype
//2021/1/18

#ifndef COW_H
#define COW_H
#include "creature.h"

class Cow:public Creature {
public:
        virtual double getspeed() = 0;//every species has its own random speed
        virtual void energyloss(double) = 0;//how we define the energy loss, using speed or else?
        virtual bool ishungry() = 0;
        double getenergy();
        double displayx();
        double displayy();
        Cow(double, double, double, double, double, double);

private:
        const double matingage;//the age whether the Cows can mating
        const double energy_threshhold;//when Cow is hungry
};

Cow::Cow(double speed_, double energy_, double x, double y, double matingage_, double energy_threshhold_):matingage(matingage_), energy_threshhold(energy_threshhold_) {
        speed = speed_;
        energy = energy_;
        coordinatex = x; 
        coordinatey = y;
        hungry = false;
}

double Cow::getspeed() { return speed; }
void Cow::energyloss(double cost) { energy -= cost; if(energy < energy_threshhold) hungry = true; }
bool Cow::ishungry() { return hungry; }
double Cow::getenergy() { return energy; }
double Cow::displayx() { return coordinatex; }
double Cow::displayy() { return coordinatey; }

#endif // COW_H