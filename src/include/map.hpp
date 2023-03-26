#pragma once

#include "tile.hpp"
#include <vector>

class EngMap {
private:
  std::vector<EngTile*> tiles;
  SDL_Renderer *renderer;
public:
  EngMap(EngWindow *wnd);
  void draw();
  ~EngMap();
};
