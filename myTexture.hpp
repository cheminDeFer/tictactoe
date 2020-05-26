#ifndef MYTEXTURE_H
#define MYTEXTURE_H

#include "SDL2/SDL.h"
#include <iostream>
#include <memory>

struct TextureDeleter {
  void operator()(SDL_Texture* p) const {std::cout << "textureDestroyed\n";
    SDL_DestroyTexture(p);}
};

class MyTexture{
  std::unique_ptr<SDL_Texture, TextureDeleter> p_;
  
public:
  explicit MyTexture(std::unique_ptr<SDL_Texture,TextureDeleter> p) :
    p_(std::move(p)) {}
  void render(SDL_Renderer * renderer,SDL_Rect* src, SDL_Rect* dst){
    
    
    
    SDL_RenderCopy(renderer, p_.get(), src, dst);
    
  }
  
};
#endif /* MYTEXTURE_H */

