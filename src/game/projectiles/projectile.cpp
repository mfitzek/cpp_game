

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

    int r = 5;
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
