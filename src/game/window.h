#pragma once

#include <SDL.h>

#include "utils/Observer.h"


class Window: public Subject{

private:
    SDL_Window *window;
    SDL_Renderer *renderer;

    unsigned int width = 0;
    unsigned int height = 0;
    bool fullscreen = false;

    static Window s_instance;
    Window();

public:

    ~Window();
    Window(const Window&) = delete;

    void Clear();
    void Render();

    SDL_Renderer* get_renderer();

    static Window& Get();

    void SetResolution(unsigned int width, unsigned int height);
    int GetWidth();
    int GetHeight();


    void Notify() override;
};


