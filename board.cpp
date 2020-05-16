#include "board.hpp"
#include "textureManager.hpp"
#include <iostream>

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




Board::Board(const char *boardTextureSheet,const char *xTextureSheet,const char *oTextureSheet, SDL_Renderer* ren,int SCREEN_WIDTH, int SCREEN_HEIGHT){
  renderer = ren;
  boardTexture = TextureManager::LoadTexture("baseShape.png", renderer);
  xTexture = TextureManager::LoadTexture("xShape.png", renderer);
  oTexture = TextureManager::LoadTexture("oShape.png", renderer);

  destRec.x = 0;
  destRec.y = 0;
  destRec.w = SCREEN_WIDTH/2;
  destRec.h  = SCREEN_HEIGHT;
  

  for (int i = 0; i < 9; i++) {
    SDL_Rect &tmpRect = squares[i];
    tmpRect.h = destRec.h / 3;
    tmpRect.w = destRec.w / 3;
    tmpRect.x = i%3 * tmpRect.w;
    tmpRect.y = i/3 * tmpRect.h;
    squares[i] = tmpRect;
  }
  for (int i = 0; i < 9; i++) {
    onSquare[i] = UNPLAYED;
  }
  
  
}

Board::~Board(){
  
}



SDL_Rect * Board::getIthSquare(int n){
  return &squares[n];
}

void Board::setIthOnSquare(int n, int currPlayer){
  onSquare[n] = currPlayer;
}


int Board::getIthOnSquare(int n){
  return onSquare[n];
}


void Board::Update(int currPlayer, int squarePlayed){
  if (squarePlayed != -1) {
    onSquare[squarePlayed] = currPlayer;  
  }
  
  
  
}

void Board::Render(){
  
  SDL_RenderCopy(renderer, boardTexture, NULL, &destRec);

  SDL_Texture *tempTexture ;

  for (int i = 0; i < 9; i++) {

    if (onSquare[i] != UNPLAYED) {
      tempTexture = onSquare[i] == PLAYED_X ? xTexture  :oTexture;
      SDL_RenderCopy(renderer, tempTexture, NULL, &squares[i]);
    } 
    
  }


  
  
}
