#include "board.hpp"
#include "textureManager.hpp"
#include <iostream>
#include <utility>
#include <algorithm>
#include <functional>
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
  winner = 0;
  winnerLineRectIds = {0,0};


}

Board::~Board(){

}


void Board::Reset(){
  gameOver = false;
  winner = 0;
  for (auto &i : onSquare) {
    i = UNPLAYED;
  }

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

int Board::getWinner(){
  return winner;
}


bool helper(int x,int y,int z){
  return (x != UNPLAYED)  && (x==y) && (y==z) ;
}

void Board::Update(int currPlayer, int squarePlayed){

  if (squarePlayed != -1) {
    onSquare[squarePlayed] = currPlayer;
  }


  for (int i = 0; i < 3; i++) {
    if(helper(onSquare[3*i],onSquare[3*i+1],onSquare[3*i+2])){
      winner = onSquare[3*i];
      winnerLineRectIds[0] = 3*i;
      winnerLineRectIds[1] = 3*i+2;

      gameOver = true;
    }
  }
  for (int i = 0; i < 3; i++) {
    if(helper(onSquare[i],onSquare[i+3],onSquare[i+6])){
      winner = onSquare[i];
      winnerLineRectIds[0] = i;
      winnerLineRectIds[1] = i+6;
      gameOver = true;

    }
  }

  if (helper(onSquare[0],onSquare[4],onSquare[8])) {
    winner = onSquare[0];
    winnerLineRectIds[0] = 0;
    winnerLineRectIds[1] = 8;
    gameOver = true;

  }

  if (helper(onSquare[2],onSquare[4],onSquare[6])) {


    winner = onSquare[2];
    winnerLineRectIds[0] = 2;
    winnerLineRectIds[1] = 6;
    gameOver = true;
  }
  if(std::all_of(onSquare.begin(), onSquare.end(), [](int i) {return i != UNPLAYED;} ))
    {
      gameOver = true;
    }
  

}

bool Board::getGameOver(){
  return gameOver;
}

std::pair<int,int> getRectCenter(const SDL_Rect& r){

  return std::make_pair(r.x + r.w / 2 , r.y + r.h/2);
}




void Board::Render(){

  for (auto &i : squares) {
    SDL_RenderCopy(renderer, boardTexture, NULL, &i);
  }


  

  SDL_Texture *tempTexture ;

  for (int i = 0; i < 9; i++) {

    if (onSquare[i] != UNPLAYED) {
      tempTexture = onSquare[i] == PLAYED_X ? xTexture  :oTexture;
      SDL_RenderCopy(renderer, tempTexture, NULL, &squares[i]);
    }

  }
  if (winner != 0) {
    SDL_Rect firstRect = squares[winnerLineRectIds[0]];
    SDL_Rect secondRect = squares[winnerLineRectIds[1]];
    auto c1 = getRectCenter(std::move(firstRect));
    auto c2 = getRectCenter(std::move(secondRect));



    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderDrawLine(renderer,
		       std::get<0>(c1),std::get<1>(c1),
		       std::get<0>(c2),std::get<1>(c2)
		       );
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

  }




}
