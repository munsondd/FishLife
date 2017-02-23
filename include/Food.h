//Fish Life
//David Munson
//4/25/2016
//food class header file
#ifndef FOOD_H
#define FOOD_H
#include <string>
#include <GameObject.h>


class Food : public GameObject
{
    public:
       Food();
       Food(std::string _image,int x, int y);
       void updatePosition(int w, int h);
        virtual ~Food();
    protected:
    private:
};

#endif // FOOD_H
