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

#include "collisions/BoundingBox.h"
#include "collisions/Line.h"

#include "utils/Observer.h"

class StateManager;

struct stats {
    double attack_speed = 1.0;
    double movement_speed = 1.0;
    double jump_height = 1.0;
    int max_health = 60;
};

struct state{
    size_t last_shot = 0;
    int current_health = 60;
    bool is_on_ground = false;
};


const double X_BASE_SPEED = 0.15;
const double GRAVITY_FALL = 0.01;
const double JUMP_VEL = 0.5;

class Player: public Entity, public Observer{

private:

    double x_velocity = 0.0;
    double y_velocity = 0.0;

    double width = 0.03;
    double height = 0.1;

    stats stats;
    state state;
    

public:
    Player(double x, double y);

    void update(double delta) override;
    void render() override;
    void tick() override;

    void CheckCollisions();

    void handle_input();

    void jump();
    void gravity();

    int GetActualWidth() const;
    int GetActualHeight() const;


    BoundingBox GetBounds() const;

    void OnUpdate() override;

};
