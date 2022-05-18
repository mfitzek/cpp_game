#pragma once


#include "entity.h"
#include "player.h"
#include "window.h"
#include "enemies/enemy.h"
#include "map/map.h"



#include <vector>
#include <memory>
#include <algorithm>
#include <iterator>


using std::vector;
using std::shared_ptr;


class Player;
class Enemy;


struct EnemyStats {
    double health = 6.0;
    double attack_speed = 1.5;
};

struct GameState {
    size_t round = 0;
    size_t enemies_count = 0;
    size_t enemies_spawn_remain = 0;


    size_t health_buffs = 0;
    size_t armor_buffs = 0;
    size_t attack_damage_buffs = 0;
    size_t attack_speed_buffs = 0;
    size_t lifesteal_buffs = 0;
    size_t movement_buffs = 0;
    size_t jump_height_buffs = 0;
};

class StateManager {

    private:

        size_t ticks = 0;

        vector<shared_ptr<Entity>> append_entity;
       

        static StateManager s_instance;
        StateManager();

    public:

        shared_ptr<Player> player;
        vector<shared_ptr<Entity>> entities;

        void AddEntity(shared_ptr<Entity> entity);

        void Update(double delta);
        void Tick();
        void Render();
        static StateManager& Get();

        Map map;

        struct EnemyStats enemy_stats;
        struct GameState game_state;


        void NextRound();
        void EndRound();
        void Death();



        size_t GetTicks() const;
};



