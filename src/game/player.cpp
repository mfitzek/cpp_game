#include "player.h"




#include <iostream>



Player::Player(float x, float y){
    this->x = x;
    this->y = y;
}




void Player::update(float delta){

    if(Input::Get().GetKeyDown(SDLK_w)){
        jump();
    }
    if(Input::Get().GetKeyDown(SDLK_a)){
        this->x -= x_speed*delta;
    }
    if(Input::Get().GetKeyDown(SDLK_d)){
        this->x += x_speed*delta;
    }

    if(Input::Get().GetKeyDown(SDLK_SPACE)){
        jump();
    }

    if(this->y + (y_velocity* delta) < (720-height)){
        this->y += (y_velocity* delta);
    }else{
        this->y = (720-height);
    }
}

bool Player::is_falling(){
    return this->y < (720-height);
}


void Player::gravity(){

    this->y_velocity += 20.f;
    
}

void Player::tick(){
    gravity();
}

void Player::jump(){
    if(!is_falling())
    this->y_velocity = -500.f;
}

void Player::render(SDL_Renderer *renderer){

    SDL_Rect rect{
        .x = (int)this->x,
        .y = (int)this->y,
        .w = 50,
        .h = 120
    };
    

    
    SDL_SetRenderDrawColor(renderer, 255,255,255,255);
    SDL_RenderFillRect(renderer, &rect);

}