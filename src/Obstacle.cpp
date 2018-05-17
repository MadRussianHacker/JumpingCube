/*
Jumping Cube
Copyright 2018 by Michał Gibas
*/

#include "Obstacle.hpp"

namespace JumpingCube
{

Obstacle::Obstacle(int y, float speed){
    rect.y = y;
    rect.x = 900;
    this->speed = speed;
}
Obstacle::~Obstacle(){
}

void Obstacle::draw(SDL_Renderer* renderer) const { 
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
}

void Obstacle::setColor(SDL_Color color){
    this->color = color;
}

void Obstacle::update(float deltaTime){
    move(deltaTime);
    updateOtherStuff(deltaTime);
}
void Obstacle::move(float deltaTime){
    rect.x -= static_cast<int>(speed*deltaTime);
}

bool Obstacle::isColliding(SDL_Rect& other){
    if( (other.x > rect.x) 
    && (other.x < (rect.x + rect.w)) 
    && (other.y > rect.y)
    && (other.y < (rect.y + rect.h))) return true;
    if( ((other.x+other.w) > rect.x) 
    && (other.x < (rect.x + rect.w)) 
    && (other.y > rect.y)
    && (other.y < (rect.y + rect.h))) return true;
    if( (other.x > rect.x) 
    && (other.x < (rect.x + rect.w)) 
    && ((other.y+other.h) > rect.y)
    && (other.y < (rect.y + rect.h))) return true;
    

    return false;
}

} //namespace JumpingCube