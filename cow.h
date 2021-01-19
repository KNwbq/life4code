//first version of class Cow (prototype
//2021/1/18

#ifndef COW_H
#define COW_H

#include "creature.h"

class Cow
       : public Creature {

public:
        void getspeed();//the random speed of a cow
        void energyloss;
        bool ishungry();//find if the energy is too low
        Cow(int, int, int);

private:
        const int matingage;//the age whether the cows can mating
};

#endif // COW_H
