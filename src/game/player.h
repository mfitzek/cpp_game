#pragma once


#include "entity.h"
#include <SDL.h>

#include "input.h"



class Player: public Entity{

private:

    float x_speed = 180.f;

    float y_velocity = 0.f;

    float width = 75.f;
    float height = 130.f;


    bool is_falling();

public:
    Player(float x, float y);

    void update(float delta) override;
    void render(SDL_Renderer *renderer) override;
    void tick() override;

    void jump();
    void gravity();


};
