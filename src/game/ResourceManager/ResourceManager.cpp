#include "ResourceManager.h"


ResourceManager::ResourceManager(){

}

ResourceManager::~ResourceManager(){

}


ResourceManager& ResourceManager::Get(){
    return ResourceManager::instance;
}


ResourceManager ResourceManager::instance;




shared_ptr<Texture> ResourceManager::LoadTexture(std::string path, std::string name){
    auto texture = std::make_shared<Texture>(path);
    textures.insert_or_assign(name, texture);
    return texture;
}

shared_ptr<Texture> ResourceManager::GetTexture(std::string name){
    if(textures.contains(name)){
        return textures[name];
    }
    return shared_ptr<Texture>();
}





