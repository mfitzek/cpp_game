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
    throw "Texture not found";
}



shared_ptr<Font> ResourceManager::LoadFont(std::string path, std::string name, int font_size){
    auto font = std::make_shared<Font>(path, font_size);
    fonts.insert_or_assign(name, font);
    return font;
}


shared_ptr<Font> ResourceManager::GetFont(std::string name){
    if(fonts.contains(name)){
        return fonts[name];
    }
    throw "Font not found";
}


