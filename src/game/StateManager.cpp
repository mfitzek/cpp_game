#include "StateManager.h"





StateManager StateManager::s_instance;

StateManager& StateManager::Get(){
    return s_instance;
}


StateManager::StateManager(){
    
}