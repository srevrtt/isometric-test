#include <iostream>
#include <string>

#include "include/map.hpp"

// Creates a new isometric tilemap
EngMap::EngMap(EngWindow *wnd) {
  for (int y = 1; y < 12; y++) {
    for (int x = 1; x < 12; x++) {
      int newX = 590 + (x - y) * 50;
      int newY = 60 + (x + y) * 25;

      tiles.push_back(new EngTile(newX, newY, 100, 50, "../images/grass.png", wnd));
    }
  }

  this->wnd = wnd;
}

// Draws the map
void EngMap::draw() {
  for (auto &t : tiles) {
    t->draw();
  }

  if (highlight) {
    highlightedTile->draw();
  } else {
    highlightedTile = nullptr;
  }
}

// Highlights the tile with the specified position.
void EngMap::highlightTile(SDL_Rect pos) {
  if (highlight == false) {
    this->highlightedTile = new EngTile(pos.x, pos.y, pos.w, pos.h, "../images/highlight.png", wnd);
    highlight = true;
  } else {
    highlightedTile->changePos(pos.x, pos.y);
  }
}

void EngMap::deleteTile(SDL_Rect pos) {
  for (auto &t : tiles) {
    SDL_Rect r = t->getRect();

    if (r.x == pos.x && r.y == pos.y && t->shown == true) {
      t->shown = false;
    }
  }
}

void EngMap::addTile(SDL_Rect pos) {
  tiles.push_back(new EngTile(pos.x, pos.y, 100, 50, "../images/sand.png", wnd));
}

// Returns the currently selected tile.
SDL_Rect EngMap::selectedTile(int mouseX, int mouseY) {
  SDL_Point pt = {mouseX, mouseY};

  for (auto &t : tiles) {
    SDL_Rect rect = t->getRect();

    if (SDL_PointInRect(&pt, &rect)) {
      return rect;
    }
  }

  highlight = false;
  return {0, 0, 0, 0};
}

// 2 - 1

// Destroys the map
EngMap::~EngMap() {
  for (auto &t : tiles) {
    t->~EngTile();
  }
}
