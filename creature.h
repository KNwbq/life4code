//first version of class creature (prototype
//2021/1/18

#ifndef CREATURE_H
#define CREATURE_H

class Creature {

public:
        virtual void getspeed() = 0;//every species has its own random speed
        virtual void energyloss() = 0;//how we define the energy loss, using speed or else?
        virtual void ishungry() = 0;
        void getenergy();
        void displaycoordinate();
        void gethungy();
protected:
        Creation(int, int, int);

private:
        int energy;
        int coordinatex;
        int coordinatey;
        int speed;
        bool hungry;
       //int life-span() whether we build in class or realize it by calculating on energy
};

#endif // CREATURE_H
