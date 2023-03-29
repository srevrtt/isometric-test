#include <iostream>
#include <string>

#include <SDL2/SDL.h>

#include "include/window.hpp"
#include "include/tile.hpp"
#include "include/map.hpp"

int main(int argc, char *argv[]) {
  EngWindow *wnd = new EngWindow(1280, 720, "Isometric Test");

  const Uint64 frameDelay = 1000 / 60;
  Uint64 frameStart, frameTime;

  bool running = true;
  SDL_Event event;

  EngMap *map = new EngMap(wnd);

  while (running) {
    frameStart = SDL_GetTicks64();

    wnd->clear();
    map->draw();
    wnd->display();
    
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        running = false;
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
          if (event.button.button == SDL_BUTTON_LEFT) {
            map->addTile(btnrect);
          }

          if (event.button.button == SDL_BUTTON_RIGHT) {
            map->deleteTile(btnrect);
          }
        }

        break;
      }
    }

    frameTime = SDL_GetTicks64() - frameStart;
    if (frameDelay > frameTime) {
      SDL_Delay(frameDelay - frameTime);
    }
  }

  return 0;
}
