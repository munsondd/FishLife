//Fish Life
//David Munson
//4/25/2016
//The parent class for all game objects
#include "GameObject.h"

GameObject::GameObject()
{
    //ctor
}

GameObject::~GameObject()
{
    //dtor
}
int GameObject::getX_velocity()
{
    return x_velocity;
}
int GameObject::getY_velocity()
{
    return y_velocity;
}
int GameObject::getX_position()
{
    return x_position;
}
int GameObject::getY_position()
{
    return y_position;
}
int GameObject::getHeight()
{
    return height;
}
int GameObject::getWidth()
{
    return width;
}
std::string GameObject::getImage()
{
    return image;
}
void GameObject::setX_position(int _x_position)
{
    x_position = _x_position;
}
void GameObject::setY_position(int _y_position)
{
    y_position = _y_position;
}
void GameObject::setHeight(int _height)
{
    height = _height;
}
void GameObject::setWidth(int _width)
{
    width = _width;
}
void GameObject::setImage(std::string _image)
{
    image = _image;
}

void GameObject::setX_velocity(int x)
{
    x_velocity = x;
}

void GameObject::setY_velocity(int y)
{
    y_velocity = y;
}

bool GameObject::isCollision(GameObject otherObject)
{
    if (otherObject.getX_position() + otherObject.getWidth() > x_position && otherObject.getX_position() < x_position + width)
    {
			if (otherObject.getY_position() < y_position + height && otherObject.getY_position() + otherObject.getHeight() > y_position)
			{
                return true;
			}
    }
    else
    {
        return false;
    }
}
void GameObject::changePosition(int window_width, int window_height)
{
    if(x_position > 0 && x_velocity < 0)
        x_position += x_velocity;
    if(x_position < window_width - width && x_velocity > 0)
        x_position += x_velocity;
    if(y_position > 0 && y_velocity < 0)
        y_position += y_velocity;
    if(y_position < window_height - height && y_velocity > 0)
        y_position += y_velocity;
}

