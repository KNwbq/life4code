//first version of class Grass (prototype
//2021/1/18

#ifndef GRASS_H
#define GRASS_H

#include "creature.h"

class Grass: public Creature {
public:
        int getspeed();//the speed of grass should be zero
        void energyloss();//if a grass doen't be eaten, how does the energy change
        bool ishungry();//will grass be hungry?
        int getenergy();
        int displayx();
        int displayy();
        Grass(int, int, int, int, int, int);

private:
        const int growth_time;//the time a coordinate need to create grass( grass can grow everwhere by the requirements
        const int Eloss_speed;//the speed of lossing the energy for grass
};

Grass::Grass(int speed_, int energy_, int x, int y, int growth_, int Eloss):growth_time(growth_), Eloss_speed(Eloss) {
        speed = speed_;
        energy = energy_;
        coordinatex = x; 
        coordinatey = y;
        hungry = false;
}

int Grass::getspeed() { return speed; }
void Grass::energyloss() { energy -= Eloss_speed; }
bool Grass::ishungry() {}
int Grass::getenergy() { return energy; }
int Grass::displayx() { return coordinatex; }
int Grass::displayy() { return coordinatey; }

#endif // GRASS_H