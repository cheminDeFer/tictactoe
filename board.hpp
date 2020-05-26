#ifndef BOARD_H
#define BOARD_H
#include "SDL2/SDL.h"
#include <array>
#include "myTexture.hpp"
class Board
{
public:
  Board(const char *boardTextureSheet,const char *xTextureSheet,const char *oTextureSheet, SDL_Renderer* ren,int scr_w,int scr_h);
  ~Board();
  void Update(int currPlayer,int squarePlayed);
  void Render();

  SDL_Rect * getIthSquare(int n);
  int getIthOnSquare(int n);
  void setIthOnSquare(int n,int currPlayer);
  int getWinner() const;
  void Reset();
  bool getGameOver() const;

private:
  
  MyTexture boardTexture;
  MyTexture xTexture;
  MyTexture oTexture;
  SDL_Rect  destRec;
  SDL_Renderer *renderer;
  
  std::array<SDL_Rect, 9> squares;
  std::array<int, 9> onSquare;

  bool gameOver;
  int winner;
  std::array<int, 2> winnerLineRectIds;
  

  
};


#endif /* BOARD_H */
