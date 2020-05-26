// using SDL and standard io
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "game.hpp"

#include <iostream>
#include <vector>


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int FPS = 60;
const int frameDelay = 1000/FPS;

enum moveSprite
  {
   UNPLAYED = 0,
   PLAYED_X = 1,
   PLAYED_O = 2
  };

enum player
  {
   playerX = 1,
   playerO = 2
  };





Game *game = nullptr;

int main()
{
  uint32_t frameStart;
  int frameTime;

  game = new Game();

  game->init("tictactoe!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,  SCREEN_HEIGHT,  false);

  while (game->running()) {
    

    frameStart = SDL_GetTicks();
    
    game->handleEvents();
    game->update();
    game->render();

    frameTime = SDL_GetTicks() - frameStart;

    if (frameDelay > frameTime) {
      SDL_Delay(frameDelay - frameTime);
    }
    
  }

  delete game;
  return 0;



}
