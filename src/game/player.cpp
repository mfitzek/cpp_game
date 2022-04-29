#include "player.h"

#include <iostream>

Player::Player(float x, float y)
{
    this->x = x;
    this->y = y;
}

void Player::update(float delta)
{
    // if (Input::Get().GetKeyDown(SDLK_p))
    // {
    //     next_remove = true;
    // }

    if (this->y + (y_velocity * delta) <= (StateManager::Get().GetWindow()->GetHeight()))
    {
        this->y += (y_velocity * delta);
    }
    else
    {
        this->y = StateManager::Get().GetWindow()->GetHeight();
    }

    this->x += x_velocity * stats.movement_speed * delta;
}

bool Player::is_falling()
{
    return this->y < (StateManager::Get().GetWindow()->GetHeight());
}

void Player::gravity()
{
    if(is_falling())
        this->y_velocity += GRAVITY_FALL;
}

void Player::tick()
{
    handle_input();
    gravity();
}

void Player::handle_input()
{
    if (Input::Get().GetKeyDown(SDLK_a) || Input::Get().GetKeyDown(SDLK_d))
    {
        this->x_velocity = Input::Get().GetKeyDown(SDLK_a) ? -X_BASE_SPEED : X_BASE_SPEED;
    }else{
        this->x_velocity = 0;
    }

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

           // std::cout << x_dir << " " << y_dir << std::endl;

            auto p = std::make_shared<Projectile>(this->x, this->y, x_dir * 200.f, y_dir * 200.f);

            StateManager::Get().AddEntity(p);
        }
    }

    if (Input::Get().GetKeyDown(SDLK_SPACE) || Input::Get().GetKeyDown(SDLK_w)  )
    {
        jump();
    }
}

void Player::jump()
{
    if (!is_falling())
        this->y_velocity -= JUMP_VEL;
}

void Player::render()
{


    auto window = StateManager::Get().GetWindow();

    SDL_Rect rect{
        .x = (int)this->x,
        .y = (int)this->y - (int)this->height,
        .w = (int)this->width,
        .h = (int)this->height};

    auto renderer = window->get_renderer();

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}