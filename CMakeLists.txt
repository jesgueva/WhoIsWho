cmake_minimum_required(VERSION 3.15)
project(SDL_TEST)
SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake-build-debug/CMakeFiles)
find_package(SDL2 REQUIRED)
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 14)

add_executable(SDL_TEST main.cpp)
target_link_libraries(SDL_TEST ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -mwindows)
