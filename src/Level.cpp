/*
Jumping Cube
Copyright 2018 by Michał Gibas
*/

#include "Level.hpp"
#include <random>

namespace JumpingCube
{
Level::Level(){
    obstacleCounter = 1;
    currentSpeed = 300.0f;
    obstacles.push_back(new Pillar(0, currentSpeed));
    obstacleGap = 400;
}
void Level::update(float deltaTime){
    static bool lock = 0;
    static std::default_random_engine engine{};
    static std::uniform_int_distribution<int> dist{0, 1};

    if(!lock){
        if(obstacleCounter%2 == 0){
            currentSpeed += 20.0f;
            if(obstacleGap < MAX_GAP_SIZE) obstacleGap += 20;
            lock = 1;
        }
    }
    if(obstacles.back()->getX() <= obstacleGap){
        int random = dist(engine);
        if(random == 0) obstacles.push_back(new Pillar(0, currentSpeed));
        if(random == 1) obstacles.push_back(new Pillar(350, currentSpeed));
        ++obstacleCounter;
        lock = 0;
    }
    if(obstacles.front()->getX() < -100)
        obstacles.erase(obstacles.begin());
    for(auto x : obstacles)
        x->update(deltaTime);
}
bool Level::isPlayerColliding(SDL_Rect& player){
    for(auto x : obstacles){
        if(x->isColliding(player))
            return true;
    }
    return false;
}
void Level::draw(SDL_Renderer* renderer) const {
    for(auto x : obstacles) x->draw(renderer);
}

} //namespace JumpingCube