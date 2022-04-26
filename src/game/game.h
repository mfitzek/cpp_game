#pragma once

#include <memory>
#include <vector>

#include <SDL.h>

#include "window.h"
#include "entity.h"
#include "player.h"
#include "input.h"
#include "StateManager.h"


class Game
{
private:
    bool running = false;

    const int TARGET_FPS = 120;
    const int TICK_RATE = 20;

    std::vector<std::shared_ptr<Entity>> entities;
    std::shared_ptr<Player> player;
    std::shared_ptr<Window> window;

public:
    Game();
    ~Game();
    void init();   // initialize window, ..
    void tick();
    void update(float delta);   // loop every delta time
    void render(); // render window
    void handle_events(SDL_Event);
    void run(); // run game
};
