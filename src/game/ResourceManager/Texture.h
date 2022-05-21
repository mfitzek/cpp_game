#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "../window.h"

class Texture{
    private:

        SDL_Texture* texture;

    public:
        Texture(std::string path);
        Texture(SDL_Texture* texture);
        SDL_Texture* get() const;
        ~Texture();


};
