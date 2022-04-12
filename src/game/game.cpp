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

    void Game::loop(){
        SDL_Event test_event;

        while(running){
            SDL_PollEvent(&test_event);

            if(test_event.type == SDL_QUIT){
                running = false;
            }        

            render();

            sleep(0);
        }

    }

    void Game::render(){
        window->Clear();
    }

    void Game::start(){
        running=true;
        loop();
    }

}
