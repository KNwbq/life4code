//first version of class Tiger (prototype
//2021/1/18

#ifndef TIGER_H
#define TIGER_H

class Cow
       : public Creature {

public:
        void getspeed();//the random speed of a tiger
        void energyloss;
        bool ishungry();//find if the energy is too low
        Tiger(int, int, int);

private:
        const int matingage;//the age whether the tigers can mating
};

#endif // TIGER_H
