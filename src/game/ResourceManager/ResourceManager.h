#pragma once


#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <string>
#include <unordered_map>
#include <memory>

#include "Texture.h"
#include "Font.h"

using std::shared_ptr;


class ResourceManager{

    private:
        static ResourceManager instance;
        ResourceManager();


        std::unordered_map<std::string, shared_ptr<Font>> fonts;
        std::unordered_map<std::string, shared_ptr<Texture>> textures;

    public:
        ~ResourceManager();
        ResourceManager(const ResourceManager&) = delete;

        static ResourceManager& Get();

        shared_ptr<Texture> LoadTexture(std::string path, std::string name);
        shared_ptr<Texture> GetTexture(std::string name);
        shared_ptr<Font> LoadFont(std::string path, std::string name, int font_size);
        shared_ptr<Font> GetFont(std::string font);

//         static shared_ptr<Texture> LoadTexture(std::string path, std::string name);
//         static shared_ptr<Texture> GetTexture(std::string name);

//         static shared_ptr<Font> LoadFont(std::string path, std::string name, int font_size);
//         static shared_ptr<Font> GetFont(std::string font, std::string text);


};



