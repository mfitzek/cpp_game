#pragma once

#include <SDL.h>


class Window{

private:
    SDL_Window *window;
    SDL_Renderer *renderer;

    unsigned int width = 0;
    unsigned int height = 0;
    bool fullscreen = false;



public:

    Window();
    ~Window();

    void Clear();
    void Render();

    SDL_Renderer* get_renderer();

    void SetResolution(unsigned int width, unsigned int height);
    int GetWidth();
    int GetHeight();
};


