#ifndef GAME_H
#define GAME_H

#include "SDL2/SDL.h"
#include "SDL/SDL_image.h"
#include "board.hpp"
#include <iostream>
#include <array>
class Game
{
public:
  Game();
  ~Game();

  void init(const char* title, int xpos, int ypos, int widht, int height, bool fullscreen);

  void handleEvents();

  void update();

  void render();
  void clean();

  bool running();

private:
  Board *board;
  int SCREEN_WIDTH;
  int SCREEN_HEIGHT;
  bool isRunning;
  SDL_Window *window;
  SDL_Renderer *renderer;
  int currPlayer;
  int currentMove;
  
  

  
  
  
  
  
  int cnt;
};



#endif /* GAME_H */
