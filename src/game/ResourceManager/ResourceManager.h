#pragma once


#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <string>
#include <unordered_map>
#include <memory>

#include "Texture.h"


class ResourceManager{

    private:
        static ResourceManager instance;
        ResourceManager();


        std::unordered_map<std::string, TTF_Font*> fonts;
        std::unordered_map<std::string, Texture> textures;
        


    public:
        ~ResourceManager();
        ResourceManager(const ResourceManager&) = delete;

        ResourceManager& Get();
        

        static SDL_Texture* LoadTexture(std::string path, std::string name);
        static SDL_Texture* GetTexture(std::string name);

        static bool LoadFont(std::string path, std::string name, int font_size);
        static SDL_Texture* GetText(std::string font, std::string text);


};



