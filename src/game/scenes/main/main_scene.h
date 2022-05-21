#pragma once

#include "../scene.h"

#include "../../entity.h"
#include "../../player.h"
#include "../../window.h"
#include "../../enemies/enemy.h"
#include "../../map/map.h"

#include "../../StateManager.h"
#include "../../map/map.h"

#include <vector>
#include <memory>
#include <cmath>

using std::shared_ptr;
using std::vector;

class StateManager;

class MainScene : public Scene
{

private:
    vector<shared_ptr<Entity>> entities;
    Map map;

public:
    virtual void update(double delta) override;
    virtual void tick() override;
    virtual void render() override;

    void AddEntity(shared_ptr<Entity> entity);
    vector<shared_ptr<Entity>> GetEntities();
    size_t GetTicks();
};
