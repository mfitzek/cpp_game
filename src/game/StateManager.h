#pragma once


#include "entity.h"
#include "player.h"
#include "window.h"
#include "map/map.h"



#include <vector>
#include <memory>
#include <algorithm>
#include <iterator>


using std::vector;
using std::shared_ptr;


class Player;

class StateManager {

    private:

        size_t ticks = 0;

        vector<shared_ptr<Entity>> append_entity;
        vector<shared_ptr<Entity>> entities;
        shared_ptr<Player> player;

        static StateManager s_instance;
        StateManager();

    public:

        void AddEntity(shared_ptr<Entity> entity);

        void Update(double delta);
        void Tick();
        void Render();
        static StateManager& Get();

        Map map;

        size_t GetTicks() const;
};



