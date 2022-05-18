#include "game.h"

#include <iostream>

using std::cout;
using std::endl;

Game::Game()
{
    auto& resources = ResourceManager::Get();

    resources.LoadTexture("../assets/images/player/player.png", "player");

}

Game::~Game(){
   // Window::DestroyWindow();
}

void Game::init()
{


}

void Game::run()
{
    SDL_Event event;
    running = true;

    uint32_t last_time = 0,last_tick=0, current_time;


    while (running)
    {   
        while(SDL_PollEvent(&event)){
            handle_events(event);
        }

        current_time = SDL_GetTicks();

        if((current_time-last_tick) >= (1000/TICK_RATE)){
            tick();
            last_tick = current_time;
        }

        double delta = (current_time - last_time) / 1000.0;
        update(delta);

        last_time = current_time;

        render();


        SDL_Delay(1000/TARGET_FPS);

    }
}


void Game::tick(){
   StateManager::Get().Tick();
}

void Game::update(double delta)
{
    StateManager::Get().Update(delta);
}

void Game::handle_events(SDL_Event event)
{
    switch (event.type)
    {
    case SDL_QUIT:
        running = false;
        break;
    case SDL_KEYDOWN:
        Input::Get().SetKeyDown(event.key.keysym.sym);
        break;
    case SDL_KEYUP:
        Input::Get().SetKeyUp(event.key.keysym.sym);
        break;
    case SDL_MOUSEMOTION:
        Input::Get().SetMouseCoords(event.motion.x, event.motion.y);
        break;

    case SDL_MOUSEBUTTONDOWN:
        Input::Get().SetMouseBtn(event.button.button, true);
    break;
    case SDL_MOUSEBUTTONUP:
        Input::Get().SetMouseBtn(event.button.button, false);
    break;

    default:
        break;
    }

    
}

void Game::render()
{
    Window& window = Window::Get();
    
    // Clear screen
    window.Clear();

    //Render objects
    StateManager::Get().Render();

    // Swap buffer
    window.Render();

}
