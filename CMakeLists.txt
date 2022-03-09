cmake_minimum_required(VERSION 3.20)
project(photoCriptic)

set(CMAKE_CXX_STANDARD 23)

add_executable(photoCriptic main.cpp Obliczator.cpp Obliczator.h Analizator.cpp Analizator.h)
