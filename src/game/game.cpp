#include "game.h"

namespace GameEngine
{

    Game::Game(){

    }

    Game::~Game(){
        window.release();
    }

    void Game::init()
    {
        window = std::make_unique<Window>();
        
    }

}
