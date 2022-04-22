#pragma once

#include <SDL.h>



class Window{

private:
    SDL_Window *window;
    SDL_Renderer *renderer;


public:

    void Clear();

    SDL_Renderer* get_renderer();

    Window();
    ~Window();

};


