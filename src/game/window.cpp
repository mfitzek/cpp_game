#include "window.h"

#include <iostream>
Window::Window()


{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "error initializing SDL: " <<  SDL_GetError() << std::endl;
    }

    window = SDL_CreateWindow(
        "SDL2Test",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1280,
        720,
        0);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    Clear();
}

Window::~Window()
{
    SDL_DestroyWindow(window);
    SDL_Quit();

    free(window);
    free(renderer);
}


void Window::Clear(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

SDL_Renderer* Window::get_renderer(){
    return this->renderer;
}


void Window::SetResolution(unsigned int width, unsigned int height){
    this->width = width;
    this->height = height;

}


Window& Window::Instance(){
    return s_instance;
}


Window Window::s_instance;