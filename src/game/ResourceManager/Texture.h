#pragma once


#include <SDL.h>
#include <SDL_image.h>
#include <string>

class Texture{
    private:

        SDL_Texture* texture;

    public:
        Texture(std::string path);
        ~Texture();


};