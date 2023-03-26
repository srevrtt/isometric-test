#include <iostream>
#include <string>

#include <SDL2/SDL_image.h>

#include "include/tile.hpp"
#include "include/window.hpp"

// Creates a new tile
EngTile::EngTile(int x, int y, int w, int h, std::string image, EngWindow *wnd) {
  renderer = SDL_GetRenderer(wnd->getWindow());
  dst = {x, y, w, h};

  SDL_Surface *img = IMG_Load(image.c_str());
  texture = SDL_CreateTextureFromSurface(renderer, img);

  SDL_FreeSurface(img);
}

// Draws the tile
void EngTile::draw() {
  SDL_RenderCopy(renderer, texture, nullptr, &dst);
}

// Destroys the tile
EngTile::~EngTile() {
  SDL_DestroyTexture(texture);
}
