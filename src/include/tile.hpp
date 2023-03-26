#pragma once

#include <SDL2/SDL.h>
#include "window.hpp"

class EngTile {
private:
  SDL_Texture *texture;
  SDL_Rect dst;
  SDL_Renderer *renderer;
public:
  EngTile(int x, int y, int w, int h, std::string image, EngWindow *wnd);
  void draw();
  ~EngTile();
};
