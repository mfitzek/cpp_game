#pragma once


namespace Game {
    
    class Game{

        public: 
            void init();        // initialize window, ..
            void loop();        // loop every delta time
            void render();      // render window
            void run();         // run game

    };

}