#include "Texture.h"





Texture::Texture(std::string path){
    auto surface = IMG_Load(path.c_str());

    if(!surface){
        std::cout << "Image error handling: " << SDL_GetError() << std::endl;
    }


    texture = SDL_CreateTextureFromSurface(Window::Get().get_renderer(), surface);

    
    SDL_FreeSurface(surface);
}

Texture::Texture(SDL_Texture* text){
    texture = text;
}


SDL_Texture* Texture::get() const {
    return texture;
}

Texture::~Texture(){
    if(texture){
        SDL_DestroyTexture(texture);
    }
}