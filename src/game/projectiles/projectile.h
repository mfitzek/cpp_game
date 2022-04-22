#pragma once


#include "../entity.h"

#include <SDL.h>


class Projectile: public Entity{

    float velocity_x;
    float velocity_y;

public:

    Projectile(float x, float y, float vel_x, float vel_y);

    void update(float delta) override;
    void tick() override;
    void render(SDL_Renderer* renderer) override; 

};