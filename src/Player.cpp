/*
Jumping Cube
Copyright 2018 by Michał Gibas
*/

#include "Player.hpp"

namespace JumpingCube
{

Player::Player(){
    cube.w = 30;
    cube.h = 30;
    cube.x = 370;
    cube.y = 270;
    playerVelocity = 0.0f;
    gravity = 0.0f;
}
Player::~Player(){
}

void Player::draw(SDL_Renderer* renderer) const {
    SDL_SetRenderDrawColor(renderer, 200, 5, 5, 255);
    SDL_RenderFillRect(renderer, &cube);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
}

void Player::update(float deltaTime) {
    if(gravity < MAX_GRAVITY_VELOCITY){
        gravity += deltaTime*ACCELERATION;
    }
    playerVelocity += deltaTime*gravity;
    cube.y += static_cast<int>(playerVelocity);
}

void Player::jump(){
    playerVelocity = -(MAX_JUMP_VELOCITY);
    gravity = 0;
}

} //namespace JumpingCube