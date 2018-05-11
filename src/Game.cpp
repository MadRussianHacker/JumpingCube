/*
Jumping Cube
Copyright 2018 by Michał Gibas
*/
#include "Game.hpp"
#include <cstdio>

namespace JumpingCube
{
Game::Game(){
    isRunning = false;
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
        handleUserInput();
        update();
        render();
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
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            isRunning = false;
        }
    }
}

void Game::update(){
}

void Game::render() const{
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

} //namespace JumpingCube