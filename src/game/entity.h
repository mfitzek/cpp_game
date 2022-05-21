#pragma once


#include <SDL.h>
#include <memory>
#include "window.h"


typedef struct point{
    double x, y;
} Point;



class Entity {
    protected:

    Point currentPos;


    public:

    bool next_remove = false;

    Point GetPosition() const;

    virtual ~Entity() = default;

    virtual void update(double delta) = 0;
    virtual void render() = 0;
    virtual void tick() = 0;
    

};
