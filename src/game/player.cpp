#include "player.h"

#include <iostream>

Player::Player(double x, double y)
{

    // Window::Get().Attach(this);

    this->currentPos.x = x;
    this->currentPos.y = y;
}

void Player::update(double delta)
{
    //    CheckCollisions(delta);

    auto bounds_x = GetBounds();
    bounds_x.x1 += x_velocity * stats.movement_speed * delta;
    bounds_x.x2 += x_velocity * stats.movement_speed * delta;

    auto bounds_y = GetBounds();
    bounds_y.y1 += (y_velocity * delta);
    bounds_y.y2 += (y_velocity * delta);

    auto &map = StateManager::Get().map;

    bool on_ground = false;
    bool can_move_Y = true;
    bool can_move_X = true;

    for (auto &l : map.map)
    {

        if (l.IsHorizontal())
        {
            if (bounds_y.CheckCollision(l))
            {
                if(currentPos.y + this->height <= l.y1){
                    on_ground = true;
                }else{
                    y_velocity = 0;
                }
                can_move_Y = false;
            }
        }
        if (l.IsVertical())
        {
            if (bounds_x.CheckCollision(l))
            {
                can_move_X = false;
            }
        }
    }

    state.is_on_ground = on_ground;

    if (!state.is_on_ground && can_move_Y)
    {
        this->currentPos.y += (y_velocity * delta);
    }
    if(can_move_X){
        this->currentPos.x += (x_velocity * stats.movement_speed * delta);
    }
}

void Player::gravity()
{
    if (!state.is_on_ground)
    {
        this->y_velocity += GRAVITY_FALL;
    }
    else
    {
        this->y_velocity = 0;
    }
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
    }
    else
    {
        this->x_velocity = 0;
    }

    if (Input::Get().GetMouseBtn(SDL_BUTTON_LEFT))
    {
        if ((StateManager::Get().GetTicks() - state.last_shot) >= 5)
        {

            state.last_shot = StateManager::Get().GetTicks();
            int mouseX, mouseY;

            Input::Get().GetMouseCoords(mouseX, mouseY);

            double mx = (double)mouseX / (double)Window::Get().GetWidth();
            double my = (double)mouseY / (double)Window::Get().GetHeight();

            double x_diff = mx - this->currentPos.x;
            double y_diff = my - this->currentPos.y;

            double dist = sqrt(pow(x_diff, 2) + pow(y_diff, 2));

            double x_dir = x_diff / dist;
            double y_dir = y_diff / dist;

            auto p = std::make_shared<Projectile>(this->currentPos.x, this->currentPos.y, x_dir * 0.5, y_dir * 0.5);

            StateManager::Get().AddEntity(p);
        }
    }

    if (Input::Get().GetKeyDown(SDLK_SPACE) || Input::Get().GetKeyDown(SDLK_w))
    {
        jump();
    }
}

void Player::jump()
{
    if (state.is_on_ground)
    {
        this->y_velocity -= JUMP_VEL;
        state.is_on_ground = false;
    }
}

void Player::render()
{
    Window &window = Window::Get();

    SDL_Rect rect{
        .x = (int)(this->currentPos.x * window.GetWidth()),
        .y = (int)(this->currentPos.y * window.GetHeight()),
        .w = this->GetActualWidth(),
        .h = this->GetActualHeight()};

    auto renderer = window.get_renderer();

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}

int Player::GetActualWidth() const
{
    return this->width * Window::Get().GetWidth();
}
int Player::GetActualHeight() const
{
    return this->height * Window::Get().GetHeight();
}

BoundingBox Player::GetBounds() const
{
    return BoundingBox(currentPos.x, currentPos.y, width, height);
}

void Player::OnUpdate()
{

}