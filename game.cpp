#include "game.hpp"
#include "textureManager.hpp"
#include "board.hpp"
#include "button.hpp"


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






Game::Game() {

}


Game::~Game() noexcept
{
  

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  TTF_Quit();
  
  std::cout << "game donezo" << "\n";
}










inline bool isInsideRect(int const x, int const y, SDL_Rect const r) {
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
    TTF_Init();

    
    isRunning = true;
    started = false;
    
   
    label = std::make_unique<Button>("FreeSerifItalic.ttf","Select first Player:",200,0,210,100, renderer);
    btnX = std::make_unique<Button>("FreeSerifItalic.ttf","PlayerX",200,120,100,100, renderer);
    btnO = std::make_unique<Button>("FreeSerifItalic.ttf","PlayerO",310,120,100,100, renderer);
    board = std::make_unique<Board>("baseShape.png","xShape.png","oShape.png",renderer,SCREEN_WIDTH,SCREEN_HEIGHT) ;
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
    int x,y;
    SDL_GetMouseState(&x, &y);
    if (board->getWinner() != UNPLAYED  ) {
      
      break;
    }
    if (!started) {
      if (isInsideRect(x,y,btnX->getRect())) {
	
	started = true;
	currPlayer = playerX;
      }
      if (isInsideRect(x,y,btnO->getRect())) {
	started = true;
	currPlayer = playerO;
      }

      break;
      
    }
    
    
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
    
  case SDL_KEYDOWN:
    switch (event.key.keysym.sym) {
    case SDLK_SPACE :
      
      board->Reset();
      started = false;
      
      
      break;
    
    default:
      break;
    }

    
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

  //board->Render();
  if (started) {
    board->Render();
  }
  else {
    label->Render();
    btnX->Render();
    btnO->Render();
  }
  


  SDL_RenderPresent(renderer);
}




bool Game::running(){
  return isRunning;
}
