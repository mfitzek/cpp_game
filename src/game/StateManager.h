#pragma once


#include "entity.h"
#include "player.h"
#include "window.h"



#include <vector>
#include <memory>

using std::vector;
using std::shared_ptr;

class StateManager {

    private:

        vector<shared_ptr<Entity>> entities;
        shared_ptr<Player> player;

        static StateManager s_instance;
        StateManager();

    public:

        void AddEntity(shared_ptr<Entity> entity);

        void Update(float delta);
        void Tick();
        void Render();
        static StateManager& Get();
};



