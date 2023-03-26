#include <iostream>
#include <string>

#include "include/map.hpp"

// Creates a new isometric tilemap
EngMap::EngMap(EngWindow *wnd) {
  renderer = SDL_GetRenderer(wnd->getWindow());

  tiles.push_back(new EngTile(10, 10, 283, 283, "../images/grass.png", wnd));
}

// Draws the map
void EngMap::draw() {
  for (auto &t : tiles) {
    t->draw();
  }
}

// Destroys the map
EngMap::~EngMap() {
  for (auto &t : tiles) {
    t->~EngTile();
  }
}
