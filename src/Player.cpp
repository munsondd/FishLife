//Fish Life
//David Munson
//4/25/2016
//the player class for fish life
#include "Player.h"

Player::Player()
{
}

Player::Player(std::string _image,int x,int y)
{
    image = _image;
    x_position = x;
    y_position = y;
    height = 40;
    width = 60;
    isAlive = true;

}

Player::~Player()
{
    //dtor
}
bool Player::getIsAlive()
{
    return isAlive;
}
void Player::setIsAlive(bool _isAlive)
{
    isAlive = _isAlive;
}


