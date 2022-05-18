#pragma once


#include "../entity.h"
#include "../StateManager.h"
#include "SDL.h"
#include "../window.h"

#include "../collisions/BoundingBox.h"
#include "../projectiles/projectile.h"


struct enemy_stats{
    double attack_speed = 1.0;
    double attack_damage = 1.0;
    double projectile_size = 1.0;
    double max_health = 6.0;
    double speed = 0.2;
};


struct enemy_state{
    size_t last_shot = 0;
    double health;
};

class Projectile;

class Enemy: public Entity {
    private: 
        enemy_stats stats;
        enemy_state state;
        double vel_x = 0;
        double vel_y = 0;


        double width = 0.1;
        double height = 0.05;
        
    public:

    Enemy(double x, double y);

    virtual void update(double delta) override;
    virtual void render() override;
    virtual void tick() override;

    void projectile_hit(std::shared_ptr<Projectile> projectile);
    void shoot();
    void ai_move();

    void check_projectile_collisions();

    BoundingBox GetBounds() const;


};