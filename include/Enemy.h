//Fish Life
//David Munson
//4/25/2016
//enemy header file
#ifndef ENEMY_H
#define ENEMY_H

#include <GameObject.h>
#include "Player.h"

class Enemy : public GameObject
{
    public:
        Enemy(std::string, int, int);
        virtual ~Enemy();
        void hunt(Player, int,int);
    protected:
    private:

};

#endif // ENEMY_H
