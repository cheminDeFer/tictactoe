#include "textureManager.hpp"
#include <iostream>
SDL_Texture* TextureManager::LoadTexture(const char * filename, SDL_Renderer* ren){
  SDL_Surface *tmpSurface = IMG_Load(filename);
  SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, tmpSurface);
  SDL_FreeSurface(tmpSurface);
  return tex;
}



SDL_Texture* TextureManager::LoadTextureFromFont(const char * fontFileName,int fontSize,const char* caption, SDL_Renderer *ren){
  SDL_Color clr;
  clr.r = 0x00;
  clr.b = 0x00;
  clr.g = 0x00;
  clr.a = 0x00;
  
  TTF_Font *font = TTF_OpenFont(fontFileName, fontSize);
  
  if (font == NULL) std::cout <<fontFileName <<"noFont\n";
  SDL_Surface *tmpSurface = TTF_RenderText_Solid(font, caption, clr);
  SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, tmpSurface);
  SDL_FreeSurface(tmpSurface);
  TTF_CloseFont(font);
  return tex;
  
}
