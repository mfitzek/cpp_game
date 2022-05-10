#include "window.h"

#include <iostream>

Window::Window()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "error initializing SDL: " <<  SDL_GetError() << std::endl;
    }

    const int WIDTH = 1600;
    const int HEIGHT = 900;


    window = SDL_CreateWindow(
        "SDL2Test",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        WIDTH,
        HEIGHT,
        SDL_WINDOW_RESIZABLE);
    width = WIDTH;
    height = HEIGHT;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    Clear();
}

Window::~Window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    //free(renderer);
   // free(window);
}


void Window::Clear(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
}

void Window::Render(){
    SDL_RenderPresent(renderer);
}




SDL_Renderer* Window::get_renderer(){
    return this->renderer;
}


void Window::SetResolution(unsigned int width, unsigned int height){
    this->width = width;
    this->height = height;

}

int Window::GetWidth(){
    return SDL_GetWindowSurface(window)->w;
}

int Window::GetHeight(){
    return SDL_GetWindowSurface(window)->h;
}


Window& Window::Get(){
    return s_instance;
}

Window Window::s_instance;




void Window::Notify(){
    for(auto obs: observers){
        if(obs != nullptr)
            obs->OnUpdate();
    }
}