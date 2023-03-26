#pragma once

#include <SDL2/SDL.h>
#include <string>

#define WND_RED 0
#define WND_GREEN 0
#define WND_BLUE 0

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
