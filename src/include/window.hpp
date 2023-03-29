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

#include <SDL2/SDL.h>
#include <string>

#define WND_RED 105
#define WND_GREEN 170
#define WND_BLUE 255

class EngWindow {
private:
  SDL_Window *window;
  SDL_Renderer *renderer;
public:
  EngWindow(unsigned int width, unsigned int height, std::string title);
  
  void clear();
  void display();

  SDL_Window *getWindow();

  ~EngWindow();
};
