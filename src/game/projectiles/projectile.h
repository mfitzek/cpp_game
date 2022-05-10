#pragma once


#include "../entity.h"

#include <SDL.h>
#include "../window.h"
#include "../StateManager.h"



class Projectile: public Entity{

    double velocity_x;
    double velocity_y;

public:

    Projectile(double x, double y, double vel_x, double vel_y);

    void update(double delta) override;
    void tick() override;
    void render() override; 

};