#pragma once

#include <SDL.h>

#include "../window.h"
#include <vector>
#include "../collisions/Line.h"



class Map {

    std::vector<Line> map;

    void render();

};


