cmake_minimum_required(VERSION 3.15)
project(buffy)

set(CMAKE_CXX_STANDARD 14)

add_executable(buffy main.cpp Humanoid.cpp Humanoid.hpp Field.cpp Field.hpp Cell.cpp Cell.hpp Action.cpp Action.hpp HumanoidType.cpp HumanoidType.hpp Displayable.cpp Displayable.hpp)