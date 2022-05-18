#include "enemy.h"

Enemy::Enemy(double x, double y)
{
    currentPos.x = x;
    currentPos.y = y;

    state.last_shot = StateManager::Get().GetTicks();
    state.health = stats.max_health;
}

void Enemy::update(double delta)
{

    auto &map = StateManager::Get().map;

    auto bounds = GetBounds();

    bounds.x1 += vel_x * stats.speed * delta;
    bounds.x2 += vel_x * stats.speed * delta;
    bounds.y1 += vel_y * stats.speed * delta;
    bounds.y2 += vel_y * stats.speed * delta;

    bool can_move = true;
    for (auto &l : map.map)
    {
        if (bounds.CheckCollision(l))
        {
            can_move = false;
            break;
        }
    }
    auto &entities = StateManager::Get().entities;

    for (auto &e : entities)
    {
        if (e.get() == this)
            continue;

        auto enemy = dynamic_cast<const Enemy *>(e.get());

        if (enemy == nullptr)
        {
            continue;
        }

        if (bounds.CheckCollision(enemy->GetBounds()))
        {
            can_move = false;
            return;
        }
    }

    if (can_move)
    {
        currentPos.x += vel_x * stats.speed * delta;
        currentPos.y += vel_y * stats.speed * delta;
    }
}

BoundingBox Enemy::GetBounds() const
{
    return BoundingBox(currentPos.x, currentPos.y, width, height);
}

void Enemy::tick()
{

    ai_move();
    check_projectile_collisions();

    if ((StateManager::Get().GetTicks() - state.last_shot) >= (60.0 / stats.attack_speed))
    {
        shoot();
    }
}

void Enemy::render()
{

    Window &window = Window::Get();

    SDL_Rect rect{
        .x = (int)(this->currentPos.x * window.GetWidth()),
        .y = (int)(this->currentPos.y * window.GetHeight()),
        .w = (int)(width * (double)window.GetWidth()),
        .h = (int)(height * (double)window.GetHeight())};

    auto renderer = window.get_renderer();

    SDL_SetRenderDrawColor(renderer, (state.health*255.0 /stats.max_health  ), (state.health*255.0 /stats.max_health  ), 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}

void Enemy::shoot()
{
    state.last_shot = StateManager::Get().GetTicks();
    auto player = StateManager::Get().player;
    auto player_p = StateManager::Get().player->GetPosition();
    double x_diff = (player_p.x + (player->GetWidth() / 2)) - this->currentPos.x;
    double y_diff = (player_p.y + (player->GetHeight() / 2)) - this->currentPos.y;

    double dist = sqrt(pow(x_diff, 2) + pow(y_diff, 2));

    double x_dir = x_diff / dist;
    double y_dir = y_diff / dist;

    auto p = std::make_shared<Projectile>(this->currentPos.x, this->currentPos.y, x_dir * 0.3, y_dir * 0.3);
    p->dmg = stats.attack_damage;

    StateManager::Get().AddEntity(p);
}

void Enemy::ai_move()
{
    // Movement x based on player positiion
    auto player = StateManager::Get().player;
    auto player_p = player->GetPosition();
    if (player_p.x > currentPos.x)
    {
        vel_x = stats.speed;
    }
    else if (player_p.x < currentPos.x)
    {
        vel_x = -stats.speed;
    }
    else
    {
        vel_x = 0;
    }

    double range = sqrt(pow(player_p.x - currentPos.x, 2) + pow(player_p.y - currentPos.y, 2));

    if (range >= 0.6)
    {
        vel_y = stats.speed;
    }
    else if (range <= 0.5)
    {
        vel_y = -stats.speed;
    }
    else
    {
        vel_y = 0;
    }
}

void Enemy::check_projectile_collisions()
{
    auto &entities = StateManager::Get().entities;

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

void Enemy::projectile_hit(std::shared_ptr<Projectile> projectile)
{

    if (projectile->player_shot)
    {
        this->state.health -= projectile->dmg;
        projectile->next_remove = true;

        if (state.health <= 0)
        {
            next_remove = true;
        }
    }
}