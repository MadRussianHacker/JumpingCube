/*
Jumping Cube
Copyright 2018 by Michał Gibas
*/

#ifndef JUMPING_CUBE_GAME_HPP
#define JUMPING_CUBE_GAME_HPP

#include "Player.hpp"
#include "Level.hpp"

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
    bool loadTexture(const char* fileName, SDL_Texture** texture);
    bool isRunning;
    bool paused;
    bool gameOver;

    float deltaTime;

    SDL_Window* window;
    SDL_Renderer* renderer;

    SDL_Texture* greetingScreen;
    SDL_Texture* gameOverScreen;
    SDL_Rect dimensions;

    Level level;

    Player player;
};

} //namespace JumpingCube

#endif //JUMPING_CUBE_GAME_HPP