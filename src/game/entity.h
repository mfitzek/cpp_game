#pragma once


#include <SDL.h>
#include <memory>
#include "window.h"


struct Point{
    double x, y;
};

class Entity {
    protected:

    Point currentPos;


    public:

    bool next_remove = false;

    virtual void update(double delta) = 0;
    virtual void render() = 0;
    virtual void tick() = 0;
    

};