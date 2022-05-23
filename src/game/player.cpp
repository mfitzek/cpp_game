#include "player.h"

#include <iostream>

Player::Player(double x, double y)
{

    this->currentPos.x = x;
    this->currentPos.y = y;
}

void Player::update(double delta)
{
    
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



    auto entities = StateManager::Get().GetEntities();

    auto bounds = GetBounds();

    for (auto &e : entities)
    {
        if (e.get() == this)
            continue;

        if (auto projectile = std::dynamic_pointer_cast<Projectile>(e))
        {
            if (bounds.CheckCollision(projectile->GetBounds()))
            {
                projectile_hit(projectile);
            }
        }
    }
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
        shoot();
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
        .x = static_cast<int>(this->currentPos.x * window.GetWidth()),
        .y = static_cast<int>(this->currentPos.y * window.GetHeight()),
        .w = this->GetActualWidth(),
        .h = this->GetActualHeight()};

    auto renderer = window.get_renderer();

    auto p_texture = ResourceManager::Get().GetTexture("player");
    SDL_RenderCopy(renderer, p_texture->get(), nullptr, &rect);

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



void Player::shoot(){
     if ((StateManager::Get().GetTicks() - state.last_shot) >= (60 / stats.attack_speed))
        {

            state.last_shot = StateManager::Get().GetTicks();
            int mouseX, mouseY;

            Input::Get().GetMouseCoords(mouseX, mouseY);

            double mx = (double)mouseX / (double)Window::Get().GetWidth();
            double my = (double)mouseY / (double)Window::Get().GetHeight();


            double player_x = this->currentPos.x + (width/2);
            double player_y = this->currentPos.y + (height/2);

            double x_diff = mx - player_x;
            double y_diff = my - player_y;

            double dist = sqrt(pow(x_diff, 2) + pow(y_diff, 2));

            double x_dir = x_diff / dist;
            double y_dir = y_diff / dist;

            auto p = std::make_shared<Projectile>(player_x, player_y , x_dir * 0.5, y_dir * 0.5);

            p->player_shot = true;
            p->dmg = stats.attack_damage;

            StateManager::Get().AddEntity(p);
        }
}

void Player::projectile_hit(std::shared_ptr<Projectile> projectile){
    if(!projectile->player_shot){

        double resist = 1.0 - stats.armor;
        if(resist < 0.1) {
            resist = 0.1;
        }

        this->state.health -= projectile->dmg * resist;
        projectile->next_remove = true;

        if(state.health <= 0 ){
            StateManager::Get().Death();
        }
    }
}


double Player::GetHeight() const {
    return height;
}

double Player::GetWidth() const {
    return width;
}

void Player::heal(double health){
    state.health += health;
    if(state.health > stats.max_health){
        state.health = stats.max_health;
    }
}

void Player::hit_enemy(std::shared_ptr<Projectile> proj){
    heal(proj->dmg * stats.life_steal);
}