//first version of class Grass (prototype
//2021/1/18

#ifndef GRASS_H
#define GRASS_H

#include "creature.h"

class Grass
       : public Creature {

public:
        void getspeed();//the speed of grass should be zero
        void energyloss;//if a grass doen't be eaten, how does the energy change
        bool ishungry();//will grass be hungry?
        Grass(int, int, int);

private:
        const int growth-time;//the time a coordinate need to create grass( grass can grow everwhere by the requirements

};

#endif // GRASS_H
