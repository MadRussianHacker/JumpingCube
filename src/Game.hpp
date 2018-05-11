/*
Jumping Cube
Copyright 2018 by Michał Gibas
*/

#ifndef JUMPING_CUBE_GAME_HPP
#define JUMPING_CUBE_GAME_HPP

#include "SDL.h"

namespace JumpingCube
{

class Game
{
public:
    Game();
    virtual ~Game();
    int run();
private:
    int init();
    void handleUserInput();
    void update();
    void render() const;

    bool isRunning;

    SDL_Window* window;
    SDL_Renderer* renderer;
};

} //namespace JumpingCube

#endif //JUMPING_CUBE_GAME_HPP