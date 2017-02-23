//Fish Life
//David Munson
//4/25/2016
//GameObject header file
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include<string>;

class GameObject
{
    public:
        GameObject();
        virtual ~GameObject();
        int getY_velocity();
        int getX_velocity();
        int getX_position();
        int getY_position();
        int getHeight();
        int getWidth();
        std::string getImage();
        void setX_velocity(int);
        void setY_velocity(int);
        void setX_position(int _x_position);
        void setY_position(int _y_position);
        void setHeight(int _height);
        void setWidth(int _width);
        void setImage(std::string _image);
        bool isCollision(GameObject);
        void changePosition(int, int);
    protected:
        int x_position;
        int y_position;
        int width;
        int height;
        int x_velocity=0;
        int y_velocity=0;
        std::string image;
    private:
};

#endif // GAMEOBJECT.h
