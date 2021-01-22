//first version of class creature (prototype
//2021/1/18

#ifndef CREATURE_H
#define CREATURE_H

class Creature {
public:
        virtual int getspeed() = 0;//every species has its own random speed
        virtual void energyloss() = 0;//how we define the energy loss, using speed or else?
        virtual bool ishungry() = 0;
        int getenergy();
        int displayx();
        int displayy();
protected:
        int speed;
        int energy;
        int coordinatex;
        int coordinatey;
        bool hungry;
       //int life_span() whether we build in class or realize it by calculating on energy
};
#endif // CREATURE_H
