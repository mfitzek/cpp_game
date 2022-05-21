#include "map.h"

Map::Map()
{
    map.emplace_back(0.01, 0.01, 0.99, 0.01); // Top
    map.emplace_back(0.01, 0.90, 0.99, 0.90); // Bot
    map.emplace_back(0.01, 0.01, 0.01, 0.90); // Left
    map.emplace_back(0.99, 0.01, 0.99, 0.90); // Right

    map.emplace_back(0.01, 0.65, 0.06, 0.65);
    map.emplace_back(0.06, 0.70, 0.11, 0.70);
    map.emplace_back(0.06, 0.65, 0.06, 0.70);
    map.emplace_back(0.11, 0.75, 0.21, 0.75);
    map.emplace_back(0.11, 0.70, 0.11, 0.75);

    map.emplace_back(0.35, 0.9, 0.35, 0.85);
    map.emplace_back(0.35, 0.85, 0.40, 0.85);
    map.emplace_back(0.40, 0.85, 0.4, 0.8);
    map.emplace_back(0.40, 0.8, 0.45, 0.8);
    map.emplace_back(0.45, 0.8, 0.45, 0.75);
    map.emplace_back(0.45, 0.75, 0.50, 0.75);
}

void Map::render()
{

    auto &window = Window::Get();
    auto render = window.get_renderer();
    SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
    for (auto &l : map)
    {
        SDL_RenderDrawLine(render, l.x1 * (double)window.GetWidth(), l.y1 * (double)window.GetHeight(), l.x2 * (double)window.GetWidth(), l.y2 * (double)window.GetHeight());
    }
    // SDL_RenderDrawLine(render, 20, 20, window.GetWidth()-20, 20);
    // SDL_RenderDrawLine(render, 20, 20, 20, window.GetHeight()-20);
    // SDL_RenderDrawLine(render, 20, 20, window.GetWidth()-20, window.GetHeight()-20);
    // SDL_RenderDrawLine(render, 20, 20, window.GetWidth()-20, window.GetHeight()-20);
    // SDL_RenderDrawLine(render, 20, 20, window.GetWidth()-20, window.GetHeight()-20);
}
