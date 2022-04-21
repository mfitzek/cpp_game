#include "game.h"

 #include <stdlib.h>

Game::Game()
{
}

Game::~Game()
{
    window.release();
}

void Game::init()
{
    window = std::make_unique<Window>();
}

void Game::loop()
{

    while (running)
    {
        handle_events();

        render();

    }
}

void Game::handle_events()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        running = false;
        break;

    default:
        break;
    }
}

void Game::render()
{
    window->Clear();
}

void Game::run()
{
    running = true;
    loop();
}
