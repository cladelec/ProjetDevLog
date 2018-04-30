cmake_minimum_required(VERSION 3.1.3)

project(TP6 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14) # Use C++14

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")

add_executable(executable main.cpp Grille.cpp Case.cpp Bacterie.cpp BactL.cpp BactS.cpp)

