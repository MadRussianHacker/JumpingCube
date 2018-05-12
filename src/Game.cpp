/*
Jumping Cube
Copyright 2018 by Michał Gibas
*/
#include "Game.hpp"
#include <cstdio>
#include <chrono>

namespace JumpingCube
{
Game::Game(){
    isRunning = false;
    deltaTime = 0.0f;
}
Game::~Game(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int Game::run(){
    int initializationResult = init();
    if(initializationResult != 0)
        return initializationResult;

    isRunning = true;
    while(isRunning)
    {
        auto start = std::chrono::steady_clock::now();
        handleUserInput();
        update();
        render();
        auto end = std::chrono::steady_clock::now();
        deltaTime = std::chrono::duration_cast<std::chrono::duration<float>>(end - start).count();
    }//while
    return 0;
}

int Game::init(){
    int sdlInitResult = SDL_Init(SDL_INIT_VIDEO);
    if(sdlInitResult != 0){
        fprintf(stderr, "Initialization error: %s \n", SDL_GetError());
        return sdlInitResult;
    }
    window = SDL_CreateWindow("Jumping Cube", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if(window == nullptr){
        fprintf(stderr, "While openning window, an error occured: %s \n", SDL_GetError());
        return 1;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(window == nullptr){
        fprintf(stderr, "Can't create renderer! Error: %s \n", SDL_GetError());
        return 1;
    }

    return 0;
}

void Game::handleUserInput() {
    SDL_Event event;
    static bool isSpacePressed = false;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            isRunning = false;
        }
        if(event.type == SDL_KEYDOWN){
            if(event.key.keysym.sym == SDLK_SPACE){
                if(!isSpacePressed){
                    player.jump();
                }
                isSpacePressed = true;
            }
        }
        if(event.type == SDL_KEYUP){
            if(event.key.keysym.sym == SDLK_SPACE){
                isSpacePressed = false;
            }
        }
    }
}

void Game::update(){
    player.update(deltaTime);
}

void Game::render() const{
    SDL_RenderClear(renderer);
    player.draw(renderer);
    SDL_RenderPresent(renderer);
}

} //namespace JumpingCube