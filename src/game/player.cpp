#include "player.h"

#include <iostream>

Player::Player(float x, float y)
{
    this->x = x;
    this->y = y;
}

void Player::update(float delta)
{

    if (Input::Get().GetKeyDown(SDLK_w))
    {
        jump();
    }
    if (Input::Get().GetKeyDown(SDLK_a))
    {
        this->x -= x_speed * delta;
    }
    if (Input::Get().GetKeyDown(SDLK_d))
    {
        this->x += x_speed * delta;
    }

    if (Input::Get().GetKeyDown(SDLK_SPACE))
    {
        jump();
    }

    if (Input::Get().GetKeyDown(SDLK_p))
    {
        next_remove = true;
    }

    if (this->y + (y_velocity * delta) < (720 - height))
    {
        this->y += (y_velocity * delta);
    }
    else
    {
        this->y = (720 - height);
    }
}

bool Player::is_falling()
{
    return this->y < (720 - height);
}

void Player::gravity()
{

    this->y_velocity += 20.f;
}

void Player::tick()
{
    if (Input::Get().GetMouseBtn(SDL_BUTTON_LEFT))
    {
        if ((StateManager::Get().GetTicks() - state.last_shot) >= 5)
        {

            state.last_shot = StateManager::Get().GetTicks();
            int x, y;

            Input::Get().GetMouseCoords(x, y);

            float x_diff = (float)x - this->x;
            float y_diff = (float)y - this->y;

            float dist = sqrt(pow(x_diff, 2.f) + pow(y_diff, 2.f));

            float x_dir = x_diff / dist;
            float y_dir = y_diff / dist;

            std::cout << x_dir << " " << y_dir << std::endl;

            auto p = std::make_shared<Projectile>(this->x, this->y, x_dir * 200.f, y_dir * 200.f);

            StateManager::Get().AddEntity(p);
        }
    }

    gravity();
}

void Player::jump()
{
    if (!is_falling())
        this->y_velocity = -500.f;
}

void Player::render()
{

    SDL_Rect rect{
        .x = (int)this->x,
        .y = (int)this->y,
        .w = 50,
        .h = 120};

    auto renderer = StateManager::Get().GetWindow()->get_renderer();

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}