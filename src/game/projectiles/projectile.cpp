

#include "projectile.h"

Projectile::Projectile(double x, double y, double vel_x, double vel_y)
{
    this->currentPos.x = x;
    this->currentPos.y = y;
    this->velocity_x = vel_x;
    this->velocity_y = vel_y;
}

void Projectile::update(double delta)
{
    auto &map = StateManager::Get().map.map;
    

    auto bounds = GetBounds();

    bounds.x1 += (velocity_x * delta);
    bounds.x2 += (velocity_x * delta);
    bounds.y1 += (velocity_y * delta);
    bounds.y2 += (velocity_y * delta);

    for(auto& l: map){
        if(bounds.CheckCollision(l)){
            next_remove = true;
            return;
        }
    }

    this->currentPos.x += (velocity_x * delta);
    this->currentPos.y += (velocity_y * delta);
}

void Projectile::render()
{

    auto &window = Window::Get();
    auto render = window.get_renderer();

    int ox = (int)(this->currentPos.x * window.GetWidth());
    int oy = (int)(this->currentPos.y * window.GetHeight());

    SDL_SetRenderDrawColor(render, 255, 255, 255, 255);

    int r = size * window.GetWidth();
    for (int y = -r; y <= r; y++)
    {
        for (int x = -r; x <= r; x++)
        {
            if (x * x + y * y <= r * r)
            {
                SDL_RenderDrawPoint(render, ox + x, oy + y);
            }
        }
    }
}

void Projectile::tick()
{

    if (currentPos.x < 0 || currentPos.y < 0 || currentPos.x > 1 || currentPos.y > 1)
    {
        next_remove = true;
    }
}


BoundingBox Projectile::GetBounds() const {

    return BoundingBox(currentPos.x - (size/2), currentPos.y - (size/2), size, size);
}