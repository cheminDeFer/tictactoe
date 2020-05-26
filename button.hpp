#ifndef BUTTON_H
#define BUTTON_H



#include "SDL2/SDL.h"
#include "myTexture.hpp"




class Button
{
public:
  Button(const char* fontFileName,const char* caption,int x, int y, int width, int height,SDL_Renderer *ren);
  virtual ~Button(void);
  std::string getCaption(void);
  void setCaption(std::string m_caption);
  void Render();

  SDL_Rect getRect();
  
private:
  SDL_Rect r;
  MyTexture texture;
  std::string m_caption;
  

  SDL_Renderer *renderer;
  
  
};


#endif /* BUTTON_H */
