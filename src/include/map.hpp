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
