/*
  Copyright 2023 Srevrtt.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

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
  if (shown) {
    SDL_RenderCopy(renderer, texture, nullptr, &dst);
  }
}

// Changes the position of the tile
void EngTile::changePos(int x, int y) {
  dst.x = x;
  dst.y = y;
}

// Gets the tile's rectangle
SDL_Rect EngTile::getRect() {
  return dst;
}

// Destroys the tile
EngTile::~EngTile() {
  SDL_DestroyTexture(texture);
}
