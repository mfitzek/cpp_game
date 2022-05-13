#pragma once


#include "../entity.h"
#include "../StateManager.h"
#include "SDL.h"
#include "../window.h"



struct enemy_stats{
    size_t last_shot = 0;
    double speed = 0.2;
};


class Enemy: public Entity {
    private: 

        enemy_stats stats;
        double vel_x = 0;
        double vel_y = 0;
        double health;

        double width = 0.03;
        double height = 0.1;
        
    public:

    Enemy(double x, double y);

    virtual void update(double delta) override;
    virtual void render() override;
    virtual void tick() override;


};