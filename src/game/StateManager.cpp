#include "StateManager.h"





StateManager StateManager::s_instance;

StateManager& StateManager::Get(){
    return s_instance;
}


StateManager::StateManager(){
    player = std::make_shared<Player>(0.5, 0.5);
    entities.push_back(player);
}


void StateManager::Update(double delta){
    for(auto e: entities){
        e->update(delta);
    }
}

void StateManager::Tick(){
    
    auto to_remove = std::remove_if(entities.begin(), entities.end(), [](shared_ptr<Entity> e){
        return e->next_remove;
    });

    entities.erase(to_remove, entities.end());

    if(append_entity.size()){
        move(append_entity.begin(), append_entity.end(), std::back_inserter(entities));
        append_entity.clear();
    }

    for(auto e: entities){
        e->tick();
    }

    ticks++;
}

void StateManager::Render(){
    map.render();
    for(auto e: entities){
        e->render();
    }
}


void StateManager::AddEntity(shared_ptr<Entity> ent){
    append_entity.push_back(ent);
}


size_t StateManager::GetTicks() const{
    return ticks;
}