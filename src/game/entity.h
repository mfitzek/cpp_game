#pragma once


#include <SDL.h>


class Entity {
    protected:

    float x, y;


    public:

    virtual void update(float delta) = 0;
    virtual void render() = 0;
    virtual void tick() = 0;
    

};