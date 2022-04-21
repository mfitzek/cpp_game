#pragma once

#include <memory>
#include "window.h"


#include <SDL.h>

class Game
{
private:
    bool running = false;
    std::unique_ptr<Window> window;

public:
    Game();
    ~Game();
    void init();   // initialize window, ..
    void loop();   // loop every delta time
    void render(); // render window
    void handle_events();
    void run(); // run game
};
