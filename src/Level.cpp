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
    currentSpeed = 400.0f;
    obstacles.push_back(new Pillar(0, currentSpeed));
    obstacleGap = 400;
}
void Level::update(float deltaTime){
    static bool lock = 0;
    static std::default_random_engine engine{};
    static std::uniform_int_distribution<int> dist{0, 2};
    static int last = 0;

    if(!lock){
        if(obstacleCounter%2 == 0){
            currentSpeed += 10.0f;
            if(obstacleGap < MAX_GAP_SIZE) obstacleGap += 20;
            lock = 1;
        }
    }
    if(obstacles.back()->getX() <= obstacleGap){
        int random = dist(engine);
        while(random == last)
            random = dist(engine);
        if(random == 0) obstacles.push_back(new Pillar(0, currentSpeed));
        if(random == 1) obstacles.push_back(new Pillar(350, currentSpeed));
        if(random == 2) {
            std::uniform_int_distribution<int> a{380, 420};
            std::uniform_int_distribution<int> b{-100, 0};
            int aY = a(engine);
            int bY = b(engine);
            obstacles.push_back(new Pillar(aY, currentSpeed));
            obstacles.push_back(new Pillar(bY, currentSpeed));
        }
        ++obstacleCounter;
        lock = 0;
        last = random;
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