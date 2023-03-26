#include <iostream>
#include <string>

#include <SDL2/SDL.h>

#include "include/window.hpp"
#include "include/tile.hpp"

int main(int argc, char *argv[]) {
  EngWindow *wnd = new EngWindow(1280, 720, "Isometric Test");

  const Uint64 frameDelay = 1000 / 60;
  Uint64 frameStart, frameTime;

  bool running = true;
  SDL_Event event;

  EngTile *testTile = new EngTile(10, 10, 283, 283, "../images/grass.png", wnd);

  while (running) {
    frameStart = SDL_GetTicks64();

    wnd->clear();
    testTile->draw();
    wnd->display();
    
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        running = false;
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
