/*
Jumping Cube
Copyright 2018 by Michał Gibas
*/

#include "Pillar.hpp"

namespace JumpingCube
{
Pillar::Pillar(int y, float speed)
:Obstacle(y, speed){
    rect.w = 80;
    rect.h = 250;
    color.r = 200;
    color.g = 50;
    color.b = 50;
    color.a = 255;
}
} //namespace JumpingCube