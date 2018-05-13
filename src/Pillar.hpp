/*
Jumping Cube
Copyright 2018 by Michał Gibas
*/

#ifndef JUMPING_CUBE_PILLAR_HPP
#define JUMPING_CUBE_PILLAR_HPP

#include "Obstacle.hpp"

namespace JumpingCube
{

class Pillar :public Obstacle
{
public:
    Pillar(int y, float speed);
private:
    virtual void updateOtherStuff(float deltaTime) {}
};

} //namespace JumpingCube

#endif //JUMPING_CUBE_PILLAR_HPP