#include "enemy.h"

Enemy::Enemy(double x, double y)
{
    currentPos.x = x;
    currentPos.y = y;

    auto& state_manager = StateManager::Get();

    state.last_shot = state_manager.GetTicks();

    state.health = stats.max_health = state_manager.enemy_stats.health;
    stats.attack_damage = state_manager.enemy_stats.attack_damage;
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
    auto entities = StateManager::Get().GetEntities();

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

    auto texture = ResourceManager::Get().GetTexture("enemy");

    SDL_SetTextureBlendMode(texture->get(), SDL_BLENDMODE_BLEND); // This sets the texture in blendmode

    SDL_SetTextureAlphaMod(texture->get(), (state.health * 255.0 / stats.max_health)); // sets the alpha into the texture

    // SDL_SetRenderDrawColor(renderer, (state.health*255.0 /stats.max_health  ), (state.health*255.0 /stats.max_health  ), 0, 255);
    // SDL_RenderFillRect(renderer, &rect);

    SDL_RenderCopy(renderer, texture->get(), nullptr, &rect);
}

void Enemy::shoot()
{
    state.last_shot = StateManager::Get().GetTicks();
    auto player = StateManager::Get().player;
    auto player_p = StateManager::Get().player->GetPosition();

    double current_x = this->currentPos.x + (width/2);
    double current_y = this->currentPos.y + (height/2);

    double x_diff = (player_p.x + (player->GetWidth() / 2)) - current_x;
    double y_diff = (player_p.y + (player->GetHeight() / 2)) - current_y;

    double dist = sqrt((x_diff, 2) + pow(y_diff, 2));

    double x_dir = x_diff / dist;
    double y_dir = y_diff / dist;

    auto p = std::make_shared<Projectile>(current_x, current_y, x_dir * stats.projectile_speed, y_dir * stats.projectile_speed);
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

void Enemy::projectile_hit(std::shared_ptr<Projectile> projectile)
{

    if (projectile->player_shot)
    {
        this->state.health -= projectile->dmg;
        projectile->next_remove = true;

        StateManager::Get().player->hit_enemy(projectile);

        if (state.health <= 0)
        {
            next_remove = true;
            StateManager::Get().game_state.enemies_count--;
        }
    }
}
