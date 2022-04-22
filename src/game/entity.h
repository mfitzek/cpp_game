#pragma once


#include <SDL.h>


class Entity {
    protected:

    float x, y;


    public:

    virtual void update(float delta) = 0;
    virtual void render(SDL_Renderer *renderer) = 0;
    virtual void tick() = 0;
    

};