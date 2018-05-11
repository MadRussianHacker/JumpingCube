# Jumping Cube
# Copyright 2018 by Michał Gibas

cmake_minimum_required(VERSION 3.0)

project(JumpingCube CXX)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

file(GLOB_RECURSE SOURCES src/*.cpp src/*.hpp)

add_executable(JumpingCube ${SOURCES})
target_link_libraries(JumpingCube PUBLIC ${SDL2_LIBRARY})