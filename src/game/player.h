#pragma once


#include <memory>
#include <SDL.h>

#include "entity.h"
#include "window.h"
#include "input.h"
#include "StateManager.h"
#include "projectiles/projectile.h"

#include "ResourceManager/ResourceManager.h"
#include "ResourceManager/Texture.h"

#include <stdint.h>
#include <cmath>

#include "collisions/BoundingBox.h"
#include "collisions/Line.h"

#include "utils/Observer.h"

class StateManager;
class Projectile;

struct stats {
    double attack_damage = 1.0;
    double attack_speed = 1.0;
    double movement_speed = 1.0;
    double projectile_size = 1.0;
    double life_steal = 0.0;
    double max_health = 40.0;
    double armor = 0.0;
    double jump_height = 1.0;
    uint8_t max_jumps = 1;

};

struct state{
    size_t last_shot = 0;
    double health = 40.0;
    bool is_on_ground = false;
    uint8_t jumps = 0;
};


const double X_BASE_SPEED = 0.15;
const double GRAVITY_FALL = 0.01;
const double JUMP_VEL = 0.5;

class Player: public Entity{

private:

    double x_velocity = 0.0;
    double y_velocity = 0.0;

    double width = 0.05;
    double height = 0.12;    

public:
    Player(double x, double y);

    void update(double delta) override;
    void render() override;
    void tick() override;
    void handle_input();


    stats stats;
    state state;

    BoundingBox GetBounds() const;
    int GetActualWidth() const;
    int GetActualHeight() const;

    double GetHeight() const;
    double GetWidth() const;

    void jump();
    void gravity();

    void heal(double health);
    void hit_enemy(std::shared_ptr<Projectile> proj);


    void shoot();
    void projectile_hit(std::shared_ptr<Projectile> projectile);

};
