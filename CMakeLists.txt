cmake_minimum_required(VERSION 3.0)
project(IsometricTest VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(SRCS src/main.cpp src/window.cpp)

if(MINGW)
  include_directories(external)
  link_directories(external/lib)
endif(MINGW)

add_executable(IsometricTest ${SRCS})

if(MINGW)
  target_link_libraries(IsometricTest mingw32 SDL2main SDL2 SDL2_image SDL2_ttf)
endif(MINGW)
