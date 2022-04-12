#pragma once

#include <memory>

#include "window.h"

namespace GameEngine {
    class Game{
        private:
            std::unique_ptr<Window> window;
            
        public: 
            Game();
            ~Game();
            void init();        // initialize window, ..
            void loop();        // loop every delta time
            void render();      // render window
            void run();         // run game

    };

}