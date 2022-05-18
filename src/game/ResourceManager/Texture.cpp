#include "Texture.h"





Texture::Texture(std::string path){
    auto surface = IMG_Load(path.c_str());
    texture = SDL_CreateTextureFromSurface(Window::Get().get_renderer(), surface);
    SDL_FreeSurface(surface);
}


SDL_Texture* Texture::get() const {
    return texture;
}

Texture::~Texture(){
    if(texture){
        SDL_DestroyTexture(texture);
    }
}