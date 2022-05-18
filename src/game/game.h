#pragma once

#include <memory>
#include <vector>

#include <SDL.h>

#include "window.h"
#include "entity.h"
#include "player.h"
#include "input.h"
#include "StateManager.h"
#include "ResourceManager/ResourceManager.h"


class Game
{
private:
    bool running = false;

    const int TARGET_FPS = 500;
    const int TICK_RATE = 60;


public:
    Game();
    ~Game();
    void init();   // initialize window, ..
    void tick();
    void update(double delta);   // loop every delta time
    void render(); // render window
    void handle_events(SDL_Event);
    void run(); // run game
};
