

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
    
}

void Projectile::tick(){

}





