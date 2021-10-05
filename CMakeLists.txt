cmake_minimum_required(VERSION 3.17)
project(Graphe)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)
include_directories( ${SDL2_INCLUDE_DIR} )

add_executable(Graphe main.cpp Screen.cpp Line.cpp)

target_link_libraries(Graphe ${SDL2_LIBRARY} )