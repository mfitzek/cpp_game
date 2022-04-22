#include <iostream>

#include <stdio.h>
#include "game/game.h"



int main(int argc, char *argv[])
{
    
   Game game;
   game.init();
   game.run();


    // if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    //     std::cout << "error initializing SDL: " <<  SDL_GetError() << std::endl;
    // }

    // auto window = SDL_CreateWindow(
    //     "SDL2Test",
    //     SDL_WINDOWPOS_UNDEFINED,
    //     SDL_WINDOWPOS_UNDEFINED,
    //     960,
    //     720,
    //     0);

    // auto renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);



    return 0;
}
