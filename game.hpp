#ifndef GAME_H
#define GAME_H

#include "SDL2/SDL.h"
#include "SDL/SDL_image.h"
#include "board.hpp"
#include <iostream>
#include <array>
#include <memory>
#include "button.hpp"
class Game
{
public:
  Game();
  Game(const Game&) = delete;
  Game& operator=(const Game&) = delete;
  ~Game() noexcept;

  void init(const char* title, int xpos, int ypos, int widht, int height, bool fullscreen);

  void handleEvents();

  void update();

  void render();
  void clean();

  bool running();
private:
  std::unique_ptr<Board>  board;
  int SCREEN_WIDTH;
  int SCREEN_HEIGHT;
  bool isRunning;
  bool started;
  SDL_Window *window;
  SDL_Renderer *renderer;
  
  int currPlayer;
  int currentMove;

  std::unique_ptr<Button>  btnX;
  std::unique_ptr<Button>  btnO;

  
  

  
  
  
  
  
  int cnt;
};



#endif /* GAME_H */
