//Fish Life
//David Munson
//4/25/2016
//the enemy class for fish life.
#include "Enemy.h"
#include <stdlib.h>
Enemy::Enemy(std::string _image,int x,int y)
{
    image = _image;
    x_position = x;
    y_position = y;
    height = 80;
    width = 80;

}

Enemy::~Enemy()
{

}
//movement for enemy
void Enemy::hunt(Player p,int d_width,int d_height)
{
    //when the enemy hits a boundry they reverse directions with psudo-random velocity
    if(x_position <= 0)
    {
        x_velocity=rand() % 5 + 1;
        y_velocity= -5 + (rand() % 10 + 1);
    }
    else if(x_position+width >= d_width)
    {
        x_velocity = -1*(rand() % 5 + 1);
        y_velocity= -5 + (rand() % 10 + 1);
    }
    if(y_position <= 0)
        y_velocity=rand() % 5 + 1;
    else if(y_position+height >= d_height)
        y_velocity=-1*(rand() % 5 + 1);


    // If the player is in line of site the enemy will rush after them.
    if(p.getY_position()+p.getWidth()>y_position && p.getY_position()<y_position+width)
    {
        if(p.getX_position()<x_position && x_velocity<0)
        {
            x_velocity = -16;
            y_velocity = 0;
        }

        if(p.getX_position()>x_position && x_velocity>0)
        {
            x_velocity = 16;
            y_velocity = 0;
        }


    }


}
