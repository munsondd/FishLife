#include "Food.h"
//Fish Life
//David Munson
//4/25/2016
//the food class for fish life
#include <stdlib.h>
Food::Food()
{
}
Food::Food(std::string _image,int x, int y)
{
    image = _image;
    x_position = x;
    y_position = y;
    width = 20;
    height = 20;
}

Food::~Food()
{
    //dtor
}
//sets the food to another random position on the screen
void Food::updatePosition(int w, int h)
{
    x_position = rand() % (w-21);
    //helps avoid spawn kills from enemySpawn
    y_position = 80 +(rand() % (h-101));

}

