#include "enemy.h"




Enemy::Enemy(double x, double y){
    currentPos.x = x;
    currentPos.y = y;

    auto& stats = StateManager::Get().enemy_stats;

    health = stats.health;
    
}


void Enemy::update(double delta){

    auto &map = StateManager::Get().map;

    BoundingBox bounds(currentPos.x, currentPos.y, width, height);

    bounds.x1 += vel_x * stats.speed * delta;
    bounds.x2 += vel_x * stats.speed * delta;
    bounds.y1 += vel_y * stats.speed * delta;
    bounds.y2 += vel_y * stats.speed * delta;


    bool can_move = true;
    for(auto& l: map.map){
        if(bounds.CheckCollision(l)){
            can_move = false;
            break;
        }
    }

    if(can_move){
        currentPos.x +=vel_x * stats.speed * delta;
        currentPos.y +=vel_y * stats.speed * delta;
    }
    

}


void Enemy::tick(){
    auto player = StateManager::Get().player;
    if(player->GetPosition().x > currentPos.x){
        vel_x = stats.speed;
    }else if (player->GetPosition().x < currentPos.x){
        vel_x = -stats.speed;
    }else{
        vel_x = 0;
    }


    auto player_p = player->GetPosition();
    
    double x_diff = player_p.x - this->currentPos.x;
    double y_diff = player_p.y - this->currentPos.y;

    double dist = sqrt(pow(x_diff, 2) + pow(y_diff, 2));

    double x_dir = x_diff / dist;
    double y_dir = y_diff / dist;

         if ((StateManager::Get().GetTicks() - stats.last_shot) >= (60/2))
        {

            stats.last_shot = StateManager::Get().GetTicks();

            auto p = std::make_shared<Projectile>(this->currentPos.x, this->currentPos.y, x_dir * 0.5, y_dir * 0.5);

            StateManager::Get().AddEntity(p);
        }


}

void Enemy::render(){

    Window &window = Window::Get();

    SDL_Rect rect{
        .x = (int)(this->currentPos.x * window.GetWidth()),
        .y = (int)(this->currentPos.y * window.GetHeight()),
        .w = (int)(width*(double)window.GetWidth()),
        .h = (int)(height*(double)window.GetHeight())};

    auto renderer = window.get_renderer();

    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
    SDL_RenderFillRect(renderer, &rect);

}

