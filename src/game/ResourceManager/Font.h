#pragma once


#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class Font{
    private:

        TTF_Font* font;
        int font_size;

    public:
        Font(std::string path, int size);
        ~Font();


};