#pragma once

#include <SDL.h>

#include "../window.h"
#include <vector>
#include "../collisions/Line.h"



class Map {
    public:
    std::vector<Line> map;
    Map();
    void render();

};


