//Fish Life
//David Munson
//4/25/2016
//the game class with most of fish lifes functionality
#include "Game.h"
#include<string>
#include<iostream>
const int DISPLAY_HEIGHT = 600;
const int DISPLAY_WIDTH = 900;

Game::Game(bool * _isRunning)
{
    isRunning = _isRunning;
    score = 0;
    p = Player("player.png",DISPLAY_WIDTH/2,DISPLAY_HEIGHT/2);
    f = Food("food.png",200,200);
    Enemy e = Enemy("enemy1.png",0,0);
    enemies.push_back(e);



}

Game::~Game()
{
}
void Game::setScore(int _score)
{
    score = _score;

}
int Game::getScore()
{
    return score;
}
SDL_Window* Game::getWindow()
{
    return window;
}

SDL_Renderer* Game::getRenderer()
{
    return renderer;
}
// the SDL initialization function
bool Game::init()
{
    window = 0;
    renderer = 0;
    // set the SDL window and renderer and check for success
    if(SDL_Init(SDL_INIT_VIDEO) >= 0)
    {

        // if succeeded create the window
        window = SDL_CreateWindow("Fish Life",  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        DISPLAY_WIDTH, DISPLAY_HEIGHT, SDL_WINDOW_SHOWN);
        // if the window creation succeeded create renderer
        if(window != 0)
        {
            renderer = SDL_CreateRenderer(window, -1, 0);

            if(renderer != 0) return true;




        }
    }
    else
    {
        return false; // SDL could not initialize
    }
}
//renders the graphics to the screen
void Game::render()
{

    // set background color
    SDL_SetRenderDrawColor(renderer, 28, 107, 160, 255);
    SDL_RenderClear(renderer);
    //draw the player
    load(p);
    //draw the food
    load(f);
    //draw the enemies
    for(int i = 0; i<enemies.size();i++)
    {
        load(enemies.at(i));
    }
    SDL_RenderPresent(renderer);

}
//handler for user input
void Game::handleEvents()
{

    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
               *isRunning  = false;
            break;
            case SDL_KEYDOWN:
                switch( event.key.keysym.sym )
                {
                    case SDLK_LEFT:

                          p.setX_velocity(-10);
                    break;
                    case SDLK_RIGHT:

                          p.setX_velocity(10);
                    break;
                    case SDLK_UP:

                           p.setY_velocity(-10);
                    break;
                    case SDLK_DOWN:

                           p.setY_velocity(10);
                    break;
                    default:
                    break;
                }
                break;
            case SDL_KEYUP:
                switch( event.key.keysym.sym )
                {
                    case SDLK_LEFT:
                        if(p.getX_velocity()<0)
                           p.setX_velocity(0);
                    break;
                    case SDLK_RIGHT:
                        if(p.getX_velocity()>0)
                           p.setX_velocity(0);
                    break;
                    case SDLK_UP:
                        if(p.getY_velocity()<0)
                           p.setY_velocity(0);
                    break;
                    case SDLK_DOWN:
                        if(p.getY_velocity()>0)
                            p.setY_velocity(0);
                    break;
                    default:
                    break;
                }
                break;
            default:
            break;
        }
    }
}
//update in game variables
void Game::update()
{
    //move the player
    p.changePosition(DISPLAY_WIDTH,DISPLAY_HEIGHT);
    for(int i = 0; i < enemies.size();i++)
    {
        enemies.at(i).hunt(p,DISPLAY_WIDTH,DISPLAY_HEIGHT);
        enemies.at(i).changePosition(DISPLAY_WIDTH,DISPLAY_HEIGHT);

    }
    //create more enemies as needed
    spawnEnemy();

    //enemy colission test
    for(int i = 0; i <enemies.size();i++)
        if( p.isCollision(enemies.at(i)) )
        {
        p.setIsAlive(false);

        }
    //food collision test
    if(p.isCollision(f))
    {
        score++;
        f.updatePosition(DISPLAY_WIDTH,DISPLAY_HEIGHT);
        std::cout<<"score: "<<score<<std::endl;
    }

}
//destroy pointers and shut down SDL
void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
//create new enemies when score increases
void Game::spawnEnemy()
{
    if(enemies.size()<score/1.5 || enemies.size()<2)
    {
        Enemy e = Enemy("enemy1.png",0,0);
        enemies.push_back(e);

    }


}
//check to see if player is alive
bool Game::playerStatus()
{
    return p.getIsAlive();

}
//function for loading graphics
void Game::load(GameObject object)
{
        //the rect struct for the source file dimensions to be loaded
        SDL_Rect sourceRectangle;
        sourceRectangle.h = object.getHeight();
        sourceRectangle.w = object.getWidth();
        sourceRectangle.x = 0;
        sourceRectangle.y = 0;
        //where and how the source file will be drawn
        SDL_Rect drawRectangle;
        drawRectangle.h = sourceRectangle.h;
        drawRectangle.w = sourceRectangle.w;
        drawRectangle.x = object.getX_position();
        drawRectangle.y = object.getY_position();
        //load the image file and convert to surface then texture
        std::string fileName = object.getImage();
        SDL_Surface* tempSurface = IMG_Load(fileName.c_str());
        SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer,tempSurface);
        SDL_FreeSurface(tempSurface);
        //flip image to the left for negative velocities
        if(object.getX_velocity()<0)
        {
            SDL_RenderCopyEx(renderer, texture, &sourceRectangle,&drawRectangle,0,0, SDL_FLIP_HORIZONTAL);
        }
        else
        {
            SDL_RenderCopy(renderer, texture, &sourceRectangle,&drawRectangle);
        }
}

