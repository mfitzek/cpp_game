#include "ResourceManager.h"


ResourceManager::ResourceManager(){

}

ResourceManager::~ResourceManager(){

}


ResourceManager& ResourceManager::Get(){
    return ResourceManager::instance;
}


ResourceManager ResourceManager::instance;




