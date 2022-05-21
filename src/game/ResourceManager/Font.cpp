#include "Font.h"

Font::Font(std::string path, int size)
{
    font = TTF_OpenFont(path.c_str(), size);
    if(!font){
        std::cout << "Font err: " << TTF_GetError() << std::endl;
    }
    font_size = size;
}

std::shared_ptr<Texture> Font::Text(std::string text, SDL_Color &color) const
{
    auto surface = TTF_RenderText_Solid(font, text.c_str(), color);

    // std::cout << "Font err: "<< TTF_GetError() << std::endl;

    auto texture = std::make_shared<Texture>(SDL_CreateTextureFromSurface(Window::Get().get_renderer(), surface));
    SDL_FreeSurface(surface);

    return texture;
}

Font::~Font()
{
    if(font){
        TTF_CloseFont(font);
    }
}
