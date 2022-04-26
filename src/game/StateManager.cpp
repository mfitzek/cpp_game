#include "StateManager.h"





StateManager StateManager::s_instance;

StateManager& StateManager::Get(){
    return s_instance;
}


StateManager::StateManager(){
    
}


void StateManager::SetWindow(shared_ptr<Window> window){
    this->window = window;
}


shared_ptr<Window> StateManager::GetWindow(){
    return this->window;
}