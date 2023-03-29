#pragma once

#include "tile.hpp"
#include <vector>

class EngMap {
private:
  std::vector<EngTile*> tiles;
  EngWindow *wnd;
  EngTile *highlightedTile;
  bool highlight = false;
public:
  EngMap(EngWindow *wnd);

  void draw();
  void highlightTile(SDL_Rect pos);
  void deleteTile(SDL_Rect pos);
  void addTile(SDL_Rect pos);

  SDL_Rect selectedTile(int mouseX, int mouseY);
  ~EngMap();
};
