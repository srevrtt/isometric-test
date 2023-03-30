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
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "include/window.hpp"

bool windowCreated = false;

// Creates a new window
EngWindow::EngWindow(unsigned int width, unsigned int height, std::string title) {
  if (!windowCreated) {
    windowCreated = true;

    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, 
      SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    
    if (!window) {
      std::cout << "Error: Failed to create an SDL2 window." << std::endl;
      exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
      std::cout << "Error: Failed to create an SDL2 renderer." << std::endl;
      exit(1);
    }

    SDL_SetRenderDrawColor(renderer, WND_RED, WND_GREEN, WND_BLUE, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }
}

// Clears the window's renderer
void EngWindow::clear() {
  SDL_SetRenderDrawColor(renderer, WND_RED, WND_GREEN, WND_BLUE, 255);
  SDL_RenderClear(renderer);
}

// Renders everything from the renderer onto the screen
void EngWindow::display() {
  SDL_RenderPresent(renderer);
}

// Gets the SDL2 window handle
SDL_Window *EngWindow::getWindow() {
  return window;
}

// Closes the window
EngWindow::~EngWindow() {
  if (windowCreated) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
  }
}
