#include "button.hpp"
#include "textureManager.hpp"
#include <memory>


Button::Button(const char* fontFileName,const char* caption,int x,int y, int width, int height,SDL_Renderer *ren)
  : texture(std::unique_ptr<SDL_Texture,TextureDeleter>(TextureManager::LoadTextureFromFont(fontFileName, 100, caption, ren) )) 
{
  r.w = width;
  r.h = height;
  r.x = x;
  r.y = y;
  renderer = ren;
  
  std::cout << "button created\n";
}

void Button::Render(){
  
  
  
  texture.render(renderer, NULL, &r);
  SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
  SDL_RenderDrawRect(renderer, &r);
  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF); 
  
}


Button::~Button(){
  std::cout << "Button destroyed"  << "\n";  
}

SDL_Rect Button::getRect(){
  return r;
}
