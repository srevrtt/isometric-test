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

#include <SDL2/SDL.h>
#include <emscripten.h>

#include "include/window.hpp"
#include "include/tile.hpp"
#include "include/map.hpp"

EngWindow *wnd;

const Uint64 frameDelay = 1000 / 60;
Uint64 frameStart, frameTime;

bool running = true;
SDL_Event event;

#ifdef __APPLE__
  bool ctrlClick = false;
#endif

EngMap *map;

void loop(void *arg) {
  frameStart = SDL_GetTicks();

  wnd->clear();
  map->draw();
  wnd->display();

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_QUIT:
      running = false;
      emscripten_cancel_main_loop();

      break;
    case SDL_KEYDOWN:
      #ifdef __APPLE__
        if (event.key.keysym.sym == SDLK_LCTRL) {
          ctrlClick = true;
        }
      #endif

      break;
    case SDL_KEYUP:
      #ifdef __APPLE__
        if (event.key.keysym.sym == SDLK_LCTRL) {
          ctrlClick = false;
        }
      #endif

      break;
    case SDL_MOUSEMOTION:
      {
        SDL_Rect rect = map->selectedTile(event.motion.x, event.motion.y);

        if (rect.x > 0) {
          map->highlightTile(rect);
        }

        break;
      }
    case SDL_MOUSEBUTTONUP:
      SDL_Rect btnrect = map->selectedTile(event.motion.x, event.motion.y);

      if (btnrect.x > 0) {
        #if defined(_WIN32) || defined(__linux__)
          if (event.button.button == SDL_BUTTON_LEFT) {
            map->addTile(btnrect);
          }

          if (event.button.button == SDL_BUTTON_RIGHT) {
            map->deleteTile(btnrect);
          }
        #endif

        #ifdef __APPLE__
          if (ctrlClick && event.button.button == SDL_BUTTON_LEFT) {
            map->deleteTile(btnrect);
          }

          if (!ctrlClick && event.button.button == SDL_BUTTON_LEFT) {
            map->addTile(btnrect);
          }
        #endif
      }

      break;
    }
  }

  frameTime = SDL_GetTicks() - frameStart;
  if (frameDelay > frameTime) {
    SDL_Delay(frameDelay - frameTime);
  }
}

int main(int argc, char *argv[]) {
  wnd = new EngWindow(1280, 720, "Isometric Test");
  map = new EngMap(wnd);

  #ifdef __APPLE__
    ctrlClick = false;
  #endif

  emscripten_set_main_loop(loop, -1, running);

  return 0;
}
