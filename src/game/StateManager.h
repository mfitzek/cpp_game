#pragma once


#include "entity.h"
#include "player.h"
#include "window.h"



#include <vector>
#include <memory>
#include <algorithm>

using std::vector;
using std::shared_ptr;


class Player;

class StateManager {

    private:

        vector<shared_ptr<Entity>> entities;
        shared_ptr<Player> player;
        shared_ptr<Window> window;

        static StateManager s_instance;
        StateManager();

    public:

        void AddEntity(shared_ptr<Entity> entity);

        void SetWindow(shared_ptr<Window> window);
        shared_ptr<Window> GetWindow();

        void Update(float delta);
        void Tick();
        void Render();
        static StateManager& Get();
};



