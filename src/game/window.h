#pragma once

#include <SDL.h>


class Window{

private:
    SDL_Window *window;
    SDL_Renderer *renderer;

    unsigned int width = 0;
    unsigned int height = 0;
    bool fullscreen = false;

    Window();
    ~Window();

    static Window s_instance;


public:

    void Clear();

    SDL_Renderer* get_renderer();

    void SetResolution(unsigned int width, unsigned int height);
    unsigned int GetWidth();
    unsigned int GetHeight();

    static Window& Instance();

    static void DestroyWindow();
};


