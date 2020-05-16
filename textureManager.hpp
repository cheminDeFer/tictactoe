#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include "SDL2/SDL.h";
#include "SDL2/SDL_image.h"
class TextureManager
{
public:
  static SDL_Texture* LoadTexture(const char *, SDL_Renderer* ren); 
  
};


#endif /* TEXTUREMANAGER_H */
