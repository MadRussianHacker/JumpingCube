/*
Jumping Cube
Copyright 2018 by Michał Gibas
*/

#ifndef JUMPING_CUBE_PLAYER_HPP
#define JUMPING_CUBE_PLAYER_HPP

#include "SDL.h"

namespace JumpingCube
{

class Player
{
public:
    Player();
    virtual ~Player();
    void draw(SDL_Renderer* renderer) const;
    void update(float deltaTime);
    void jump();
    bool isDead();
    inline SDL_Rect& getCollider() { return cube; }
private:
    SDL_Rect cube;
    int red, blue;
    float playerVelocity;
    float gravity;
    const float MAX_GRAVITY_VELOCITY = 15;
    const float MAX_JUMP_VELOCITY = 8;
    const float ACCELERATION = 350.0;
    const int CUBE_SIZE = 30;
};

} //namespace JumpingCube

#endif //JUMPING_CUBE_PLAYER_HPP