

#include "projectile.h"





Projectile::Projectile(double x, double y, double vel_x, double vel_y){
    this->currentPos.x = x;
    this->currentPos.y = y;
    this->velocity_x = vel_x;
    this->velocity_y = vel_y;
}


void Projectile::update(double delta){
    this->currentPos.x += (velocity_x*delta);
    this->currentPos.y += (velocity_y*delta);
} 

void Projectile::render(){


    auto& window = Window::Get();

    SDL_Rect rect;
    rect.x = this->currentPos.x * window.GetWidth();
    rect.y= this->currentPos.y * window.GetHeight();
    rect.w = 10;
    rect.h = 10;

    SDL_SetRenderDrawColor(window.get_renderer(), 255,255,255,255);
    SDL_RenderFillRect(window.get_renderer(), &rect);
    
}

void Projectile::tick(){

    if(currentPos.x < 0 || currentPos.y < 0 || currentPos.x > 1 || currentPos.y > 1){
        next_remove = true;
    }
}





