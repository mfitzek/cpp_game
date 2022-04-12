#pragma once

#include <memory>
#include <SDL2/SDL.h>
#include "window.h"

namespace GameEngine {
    class Game{
        private:
            bool running = false;
            std::unique_ptr<Window> window;
            
        public: 
            Game();
            ~Game();
            void init();        // initialize window, ..
            void start();
            void loop();        // loop every delta time
            void render();      // render window
            void run();         // run game

    };

}