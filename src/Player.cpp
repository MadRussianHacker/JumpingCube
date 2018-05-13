/*
Jumping Cube
Copyright 2018 by Michał Gibas
*/

#include "Player.hpp"
#include <cmath>

namespace JumpingCube
{

Player::Player(){
    cube.w = 30;
    cube.h = 30;
    cube.x = 370;
    cube.y = 270;
    playerVelocity = 0.0f;
    gravity = 0.0f;
    red = 50;
    blue = 200;
}
Player::~Player(){
}

void Player::draw(SDL_Renderer* renderer) const {
    SDL_SetRenderDrawColor(renderer, red, 80, blue, 255);
    SDL_RenderFillRect(renderer, &cube);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
}

void Player::update(float deltaTime) {
    static float totalTime = 0;
    totalTime += deltaTime;
    if(gravity < MAX_GRAVITY_VELOCITY){
        gravity += deltaTime*ACCELERATION;
    }
    playerVelocity += deltaTime*gravity;
    cube.y += static_cast<int>(playerVelocity);
    red = static_cast<int>((cos(totalTime)+1)*100)+55;
    blue = static_cast<int>((sin(totalTime)+1)*100)+55;
}

void Player::jump(){
    playerVelocity = -(MAX_JUMP_VELOCITY);
    gravity = 2.0;
}

} //namespace JumpingCube