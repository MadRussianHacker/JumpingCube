/*
Jumping Cube
Copyright 2018 by Michał Gibas
*/

#ifndef JUMPING_CUBE_LEVEL_HPP
#define JUMPING_CUBE_LEVEL_HPP

#include "Pillar.hpp"
#include <vector>

namespace JumpingCube
{

class Level
{
public:
    Level();
    void update(float deltaTime);
    void draw(SDL_Renderer* renderer) const;
    bool isPlayerColliding(SDL_Rect& player);
private:
    void moveObstacles(float deltaTime);
    std::vector<Obstacle*> obstacles;
    unsigned int obstacleCounter;
    float currentSpeed;
    int obstacleGap;
    const int MAX_GAP_SIZE = 500;
};

} //namespace JumpingCube

#endif //JUMPING_CUBE_LEVEL_HPP