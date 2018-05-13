/*
Jumping Cube
Copyright 2018 by Michał Gibas
*/

#ifndef JUMPING_CUBE_OBSTACLE_HPP
#define JUMPING_CUBE_OBSTACLE_HPP

#include "SDL.h"

namespace JumpingCube
{

class Obstacle
{
public:
    Obstacle(int y, float speed);
    virtual ~Obstacle();
    void setColor(SDL_Color color);
    void draw(SDL_Renderer* renderer) const;
    void update(float deltaTime);
    bool isColliding(SDL_Rect& other);
    inline int getX() { return rect.x; }
protected:
    SDL_Rect rect;
    SDL_Color color;
private:
    float speed;
    void move(float deltaTime);
    virtual void updateOtherStuff(float deltaTime) = 0;
};

} //namespace JumpingCube

#endif //JUMPING_CUBE_OBSTACLE_HPP