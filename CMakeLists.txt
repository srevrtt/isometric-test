cmake_minimum_required(VERSION 3.0)
project(IsometricTest VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(SRCS src/main.cpp src/window.cpp src/tile.cpp src/map.cpp)

if(MINGW)
  include_directories(external)
  link_directories(external/lib)
endif(MINGW)

if(UNIX AND NOT APPLE)
  include_directories(/usr/include/SDL2)
endif(UNIX AND NOT APPLE)

if(APPLE)
  include_directories(/usr/local/include)
  link_directories(/usr/local/lib)
endif(APPLE)

add_executable(IsometricTest ${SRCS})

if(MINGW)
  target_link_libraries(IsometricTest mingw32 SDL2main SDL2 SDL2_image SDL2_ttf)
endif(MINGW)

if(UNIX)
  target_link_libraries(IsometricTest SDL2main SDL2 SDL2_image SDL2_ttf)
endif(UNIX)
