#pragma once


#include <memory>
#include <SDL.h>

#include "entity.h"
#include "window.h"
#include "input.h"
#include "StateManager.h"
#include "projectiles/projectile.h"

#include <stdint.h>
#include <cmath>

class StateManager;

struct stats {
    float attack_speed = 1.f;
};

struct state{
    uint32_t last_shot = 0;
};

class Player: public Entity{

private:


    float x_speed = 180.f;

    float x_velocity = 0.f;
    float y_velocity = 0.f;

    float width = 75.f;
    float height = 130.f;

    stats stats;
    state state;
    
    bool is_falling();

public:
    Player(float x, float y);

    void update(float delta) override;
    void render() override;
    void tick() override;

    void jump();
    void gravity();


};
