#include <iostream>
#include <string>

#include <SDL2/SDL.h>

int main(int argc, char *argv[]) {
  SDL_Init(SDL_INIT_VIDEO);
  std::cout << "Hello world!" << std::endl;

  return 0;
}
