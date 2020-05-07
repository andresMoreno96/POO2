cmake_minimum_required(VERSION 3.15)
project(buffy)

set(CMAKE_CXX_STANDARD 14)

add_executable(buffy main.cpp Person.cpp Person.hpp Grid.cpp Grid.hpp Cell.cpp Cell.hpp Manager.cpp Manager.hpp Buffy.cpp Buffy.hpp Vampire.cpp Vampire.hpp Human.cpp Human.hpp)