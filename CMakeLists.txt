cmake_minimum_required(VERSION 3.5)
project(tic-tac-toe)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

include_directories(inc)

add_executable(main
        src/Game.cpp
        inc/Board.h
        src/Board.cpp
        inc/Player.h
        src/Player.cpp
        )
