#include "game.hpp"
#include "textureManager.hpp"
#include "board.hpp"



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





Game::Game(){

}
Game::~Game()
{


}

bool isInsideRect(int x, int y, SDL_Rect r) {
  return y > r.y &&  (y < r.y+r.h)   &&  x>r.x  &&  (x < r.x + r.w);
}



void Game::init(const char *title, int xpos, int ypos, int widht, int height, bool fullscreen){

  SCREEN_WIDTH = widht;
  SCREEN_HEIGHT = height;
  int flags = 0;
  if (fullscreen)
    flags = SDL_WINDOW_FULLSCREEN;


  if (!SDL_Init(SDL_INIT_EVERYTHING)) {
    std::cout << "Game initialize \n";


    window = SDL_CreateWindow(title, xpos, ypos, widht, height, flags);
    if( window){
      std::cout << "Window created \n";
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if(renderer){
      SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
      std::cout << "render created" << "\n";
    }
    isRunning = true;
    board = new  Board("baseShape.png","xShape.png","oShape.png",renderer,SCREEN_WIDTH,SCREEN_HEIGHT);
    currPlayer = playerX;
    currentMove = -1 ;

  }else
    isRunning = false;






}

void Game::handleEvents(){
  SDL_Event event;
  SDL_PollEvent(&event);
  switch (event.type) {
  case SDL_QUIT:
    isRunning = false;
    break;
  case SDL_MOUSEBUTTONDOWN:
    if (board->getWinner() != UNPLAYED) {
      break;
    }
    int x,y;
    SDL_GetMouseState(&x, &y);
    for (int i = 0; i < 9; i++) {
      if(isInsideRect(x,y,*board->getIthSquare(i)))
	{
	  if (board->getIthOnSquare(i) == UNPLAYED) {
	   
	    currentMove = i;
	    board->Update(currPlayer,currentMove);
	    currPlayer = 3- currPlayer;
	  }
	  else {
	    currentMove = -1;
	  }
	}
      else {
	currentMove = -1;
      }
    }

    break;
  default:
    currentMove = -1;
    break;

  }

}

void Game::update(){
  cnt++ ;
  if (cnt % 20 == 0) {
    (void) 0;
  }
  
    
    
  


  
}


void Game::render(){
  SDL_RenderClear(renderer);

  board->Render();


  SDL_RenderPresent(renderer);
}

void Game::clean(){
  delete board;
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  std::cout << "game donezo" << "\n";
}



bool Game::running(){
  return isRunning;
}
