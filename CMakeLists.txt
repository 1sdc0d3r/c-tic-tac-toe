cmake_minimum_required(VERSION 3.5)
project(tic-tac-toe)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

include_directories(inc)

set( APP_EXECUTABLE main )

add_executable(${APP_EXECUTABLE}
        src/Game.cpp
        inc/Board.h
        src/Board.cpp
        inc/Player.h
        src/Player.cpp
        )

find_program(VALGRIND "valgrind")
if(VALGRIND)
	add_custom_target(valgrind
		COMMAND "${VALGRIND}" --tool=memcheck --leak-check=yes --show-reachable=yes $<TARGET_FILE:${APP_EXECUTABLE}>)
endif()
