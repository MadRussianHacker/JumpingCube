/*
Jumping Cube
Copyright 2018 by Michał Gibas
*/

#ifndef JUMPING_CUBE_GAME_HPP
#define JUMPING_CUBE_GAME_HPP

#include "Player.hpp"

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
    bool paused;
    bool gameOver;

    float deltaTime;

    SDL_Window* window;
    SDL_Renderer* renderer;

    SDL_Texture* greetingScreen;
    SDL_Texture* gameOverScreen;
    SDL_Rect gsDimensions, goDimensions;

    Player player;
};

} //namespace JumpingCube

#endif //JUMPING_CUBE_GAME_HPP