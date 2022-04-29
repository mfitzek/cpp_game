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
    float movement_speed = 1.f;
    float jump_height = 1.f;
    int max_health = 60;
};

struct state{
    uint32_t last_shot = 0;
    int current_health = 60;
};


const float X_BASE_SPEED = 200.f;
const float GRAVITY_FALL = 25.f;
const float JUMP_VEL = 500.f;

class Player: public Entity{

private:

    float x_velocity = 0.f;
    float y_velocity = 0.f;

    float width = 50.f;
    float height = 100.f;

    stats stats;
    state state;
    
    bool is_falling();

public:
    Player(float x, float y);

    void update(float delta) override;
    void render() override;
    void tick() override;

    void handle_input();

    void jump();
    void gravity();


};
