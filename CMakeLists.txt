cmake_minimum_required(VERSION 3.15)
project(WhoIsWho)
SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake-build-debug/CMakeFiles)
find_package(SDL2 REQUIRED)
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIR})
set(CMAKE_CXX_STANDARD 14)

add_executable(WhoIsWho Game.cpp)
target_link_libraries(WhoIsWho ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -mwindows)