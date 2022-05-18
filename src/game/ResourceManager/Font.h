#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "Texture.h"

#include "../window.h"

#include <memory>

class Font{
    private:

        TTF_Font* font;
        int font_size;

    public:
        Font(std::string path, int size);
        
        std::shared_ptr<Texture> Text(std::string text, SDL_Color& color) const;

        ~Font();


};