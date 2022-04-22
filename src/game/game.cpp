#include "game.h"

#include <iostream>

using std::cout;
using std::endl;

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
    player = std::make_shared<Player>(100, 200);
    entities.push_back(player);
}

void Game::run()
{
    SDL_Event event;
    running = true;

    uint32_t last_time = 0,last_tick=0, current_time;

    const int TARGET_TICK = 60;

    while (running)
    {   
        while(SDL_PollEvent(&event)){
            handle_events(event);
        }

        current_time = SDL_GetTicks();

        if((current_time-last_tick) >= (1000/TARGET_TICK)){
            tick();
            last_tick = current_time;
        }

        float delta = (current_time - last_time) / 1000.f;
        update(delta);

        last_time = current_time;

        render();


        SDL_Delay(1000/TARGET_FPS);

    }
}


void Game::tick(){
    for (auto e : entities)
    {
        e->tick();
    }
}

void Game::update(float delta)
{
    for (auto e : entities)
    {
        e->update(delta);
    }
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
    window->Clear();
    auto render = window->get_renderer();
    for (auto e : entities)
    {
        e->render(render);
    }

    int x;
    int y;

    Input::Get().GetMouseCoords(x,y);

    SDL_Rect rect {
        .x = x-5,
        .y = y-5,
        .w = 10,
        .h = 10
    };

    SDL_SetRenderDrawColor(render, 255,255,255,255);
    SDL_RenderFillRect(render, &rect);


    SDL_RenderPresent(render);
}
