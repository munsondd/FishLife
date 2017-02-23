//Fish Life
//David Munson
//4/25/2016
//the game class header file
#ifndef GAME_H
#define GAME_H
//Using SDL and SDL image library
#include <SDL2/SDL.h>
#include <stdio.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <vector>
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Food.h"
class Game
{
    public:
        Game(bool *_isRunning);
        virtual ~Game();
        void handleEvents();
        void update();
        void render();
        bool init();
        void clean();
        SDL_Window* getWindow();
        SDL_Renderer* getRenderer();
        bool playerStatus();
        void setScore(int);
        int getScore();
    protected:
    private:
        int score;
        SDL_Window* window = 0;
        SDL_Renderer* renderer = 0;
        bool * isRunning;
        Player p;
        Food f;
        std::vector<Enemy> enemies;
        void spawnEnemy();
        void spawnFood();
        void load(GameObject);



};

#endif // GAME_H
