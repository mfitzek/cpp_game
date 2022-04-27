

#include "projectile.h"





Projectile::Projectile(float x, float y, float vel_x, float vel_y){
    this->x = x;
    this->y = y;
    this->velocity_x = vel_x;
    this->velocity_y = vel_y;
}


void Projectile::update(float delta){
    this->x += (velocity_x*delta);
    this->y += (velocity_y*delta);
} 

void Projectile::render(){
    auto renderer = StateManager::Get().GetWindow()->get_renderer();

    SDL_Rect rect;
    rect.x = this->x - 5;
    rect.y= this->y - 5;
    rect.w = 10;
    rect.h = 10;

    SDL_SetRenderDrawColor(renderer, 255,255,255,255);
    SDL_RenderFillRect(renderer, &rect);
    
}

void Projectile::tick(){

    if(x < 0 || y < 0 || x > StateManager::Get().GetWindow()->GetWidth() || y > StateManager::Get().GetWindow()->GetHeight()){
        next_remove = true;
    }
}





