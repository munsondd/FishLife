//Fish Life
//David Munson
//4/25/2016
//driver class for Fish life


#include "Game.h"
#include "iostream"

using namespace std;
const int FPS = 30;
const int DELAY = 1000.0f / FPS;
int main( int argc, char* args[] )
{
    //variables for handling FPS
    Uint32 frameStart, frameTime;
    bool running = false;
    //g is our instance object of the game
    Game g = Game(& running);
    string welcome = "welcome to fish life. can you handle the endless struggle to stay alive?";
    cout << welcome << endl;
    //initiates sdl and starting objects
    running = g.init();
    //the primary game loop
    while(running && g.playerStatus())
    {
        frameStart = SDL_GetTicks();
        g.handleEvents();
        g.update();
        g.render();


        //this if statement keeps the FPS at 30
        frameTime = SDL_GetTicks() - frameStart;
        if(frameTime< DELAY)
        {
        SDL_Delay((int)(DELAY - frameTime));
        }

    }
    cout << "You consumed "<<g.getScore()<<" worms before your demise.";
    g.clean();
}
