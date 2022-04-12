#pragma once

#include <SDL.h>



class Window{

private:
    SDL_Window *window;
    SDL_Renderer *renderer;


public:

    void Clear();


    Window();
    ~Window();

};


