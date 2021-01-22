//first version of class Cow (prototype
//2021/1/18

#ifndef COW_H
#define COW_H
#include "creature.h"

class Cow:public Creature {
public:
        virtual int getspeed() = 0;//every species has its own random speed
        virtual void energyloss(int) = 0;//how we define the energy loss, using speed or else?
        virtual bool ishungry() = 0;
        int getenergy();
        int displayx();
        int displayy();
        Cow(int, int, int, int, int, int);


private:
        const int matingage;//the age whether the Cows can mating
        const int energy_threshhold;//when Cow is hungry
};

Cow::Cow(int speed_, int energy_, int x, int y, int matingage_, int energy_threshhold_):matingage(matingage_), energy_threshhold(energy_threshhold_) {
        speed = speed_;
        energy = energy_;
        coordinatex = x; 
        coordinatey = y;
        hungry = false;
}

int Cow::getspeed() { return speed; }
void Cow::energyloss(int cost) { energy -= cost; if(energy < energy_threshhold) hungry = true; }
bool Cow::ishungry() { return hungry; }
int Cow::getenergy() { return energy; }
int Cow::displayx() { return coordinatex; }
int Cow::displayy() { return coordinatey; }

#endif // COW_H