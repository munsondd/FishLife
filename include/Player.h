//Fish Life
//David Munson
//4/25/2016
//header file for player class
#ifndef PLAYER_H
#define PLAYER_H

#include <GameObject.h>

class Player: public GameObject
{
    public:
        Player();
        Player(std::string,int x,int y);
        virtual ~Player();
        bool getIsAlive();
        void setIsAlive(bool _isAlive);


    protected:
    private:
        bool isAlive;
};

#endif // PLAYER_H
