cmake_minimum_required(VERSION 3.15)
project(buffy)

set(CMAKE_CXX_STANDARD 14)

add_executable(buffy main.cpp Humanoid.cpp Humanoid.hpp Field.cpp Field.hpp Cell.cpp Cell.hpp Buffy.cpp Buffy.hpp Vampire.cpp Vampire.hpp Human.cpp Human.hpp Action.cpp Action.hpp)