#include "StateManager.h"





StateManager StateManager::s_instance;

StateManager& StateManager::Get(){
    return s_instance;
}


StateManager::StateManager(){
    player = std::make_shared<Player>(100, 200);
    entities.push_back(player);
}


void StateManager::SetWindow(shared_ptr<Window> window){
    this->window = window;
}


shared_ptr<Window> StateManager::GetWindow(){
    return this->window;
}


void StateManager::Update(float delta){
    for(auto e: entities){
        e->update(delta);
    }
}

void StateManager::Tick(){
    auto to_remove = std::remove_if(entities.begin(), entities.end(), [](shared_ptr<Entity> e){
        return e->next_remove;
    });

    entities.erase(to_remove, entities.end());

    for(auto e: entities){
        e->tick();
    }
}

void StateManager::Render(){
    for(auto e: entities){
        e->render();
    }
}