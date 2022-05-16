#include "Texture.h"





Texture::Texture(std::string path){
    auto surface = IMG_Load(path.c_str());
}


Texture::~Texture(){
    if(texture){
        SDL_DestroyTexture(texture);
    }
}