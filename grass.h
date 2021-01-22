//first version of class Grass (prototype
//2021/1/18

#ifndef GRASS_H
#define GRASS_H

#include "creature.h"

class Grass: public Creature {
public:
        double getspeed();//the speed of grass should be zero
        void energyloss();//if a grass doen't be eaten, how does the energy change
        bool ishungry();//will grass be hungry?
        double getenergy();
        double displayx();
        double displayy();
        Grass(double, double, double, double, double, double);

private:
        const double growth_time;//the time a coordinate need to create grass( grass can grow everwhere by the requirements
        const double Eloss_speed;//the speed of lossing the energy for grass
};

Grass::Grass(double speed_, double energy_, double x, double y, double growth_, double Eloss):growth_time(growth_), Eloss_speed(Eloss) {
        speed = speed_;
        energy = energy_;
        coordinatex = x; 
        coordinatey = y;
        hungry = false;
}

double Grass::getspeed() { return speed; }
void Grass::energyloss() { energy -= Eloss_speed; }
bool Grass::ishungry() {}
double Grass::getenergy() { return energy; }
double Grass::displayx() { return coordinatex; }
double Grass::displayy() { return coordinatey; }

#endif // GRASS_H