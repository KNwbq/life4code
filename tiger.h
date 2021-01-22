//first version of class Tiger (prototype
//2021/1/18

#ifndef TIGER_H
#define TIGER_H
#include "creature.h"

class Tiger:public Creature {
public:
        virtual int getspeed() = 0;//every species has its own random speed
        virtual void energyloss(int) = 0;//how we define the energy loss, using speed or else?
        virtual bool ishungry() = 0;
        int getenergy();
        int displayx();
        int displayy();
        Tiger(int, int, int, int, int, int);


private:
        const int matingage;//the age whether the tigers can mating
        const int energy_threshhold;//when tiger is hungry
};

Tiger::Tiger(int speed_, int energy_, int x, int y, int matingage_, int energy_threshhold_):matingage(matingage_), energy_threshhold(energy_threshhold_) {
        speed = speed_;
        energy = energy_;
        coordinatex = x; 
        coordinatey = y;
        hungry = false;
}

int Tiger::getspeed() { return speed; }
void Tiger::energyloss(int cost) { energy -= cost; if(energy < energy_threshhold) hungry = true; }
bool Tiger::ishungry() { return hungry; }
int Tiger::getenergy() { return energy; }
int Tiger::displayx() { return coordinatex; }
int Tiger::displayy() { return coordinatey; }

#endif // TIGER_H